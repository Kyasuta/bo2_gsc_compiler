// bo2_gsc_lexer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bo2_gsc_file.h"

using namespace std;

extern int lineCount;
extern int yydebug;

extern FILE* yyin;
extern int yyparse();

void recursive_yyparse(char* dir)
{
	char fileDir[MAX_PATH];
	strcpy_s(fileDir, dir);

	char* _dir = fileDir;
	char* tmp;
	while (true)
	{
		tmp = strchr(_dir, '\\');

		if (tmp)
			_dir = tmp + 1;
		else
			break;
	}

	HANDLE hFind;
	WIN32_FIND_DATAA data;
	FILE* fileHandle;
	
	hFind = FindFirstFileA(dir, &data);
	
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (strcmp(data.cFileName, ".") && strcmp(data.cFileName, ".."))
				{
					strcpy(_dir, data.cFileName);
					strcat(_dir + strlen(data.cFileName), "\\*");
					recursive_yyparse(fileDir);
				}
			}
			else if (!strcmp(PathFindExtensionA(data.cFileName), ".gsc") &&
				strcmp(data.cFileName, "_globallogic_utils.gsc") &&
				strcmp(data.cFileName, "_foliage_cover.gsc") &&
				strcmp(data.cFileName, "_menus.gsc") &&
				strcmp(data.cFileName, "_specialops.gsc") &&
				strcmp(data.cFileName, "_zombiemode_money.gsc"))
			{
				strcpy(_dir, data.cFileName);

				printf_s("parsing %s\n", fileDir);
				
				FILE* stderrlog = NULL;
				freopen_s(&stderrlog, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\stderr.log", "w", stderr);

				fopen_s(&fileHandle, fileDir, "r");
				yyin = fileHandle;
				lineCount = 1;
				yyparse();
				fclose(fileHandle);

				fclose(stderrlog);
				DeleteFileA("C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\stderr.log");
			}
		} while (FindNextFileA(hFind, &data));

		FindClose(hFind);
	}
}

DWORD EmitExpression(sNode* node, bool ref, bool object);

void CompileError(char* errorString, ...)
{
	va_list ap;
	
	va_start(ap, errorString);
	int length = _vscprintf(errorString, ap);
	va_end(ap);

	char* allocatedString = (char*)malloc(length + 1);

	va_start(ap, errorString);
	_vsnprintf_s(allocatedString, length + 1, length + 1, errorString, ap);
	va_end(ap);

	MessageBoxA(NULL, allocatedString, NULL, MB_ICONERROR | MB_OK);

	free(allocatedString);
	ExitProcess(-1);
}

/*
	IMPORTANT WHEN I WAKE UP:
	MAKE SUPPORT FOR THE BELOW KEYWORDS IN THE .y FILE
	THEN I WONT NEED THIS FUNCTION
*/
bool IsKeyword(char* str)
{
	return !strcmp(str, "level")
		|| !strcmp(str, "anim")
		|| !strcmp(str, "self")
		|| !strcmp(str, "game")
		|| !strcmp(str, "size");
}

void CompileStrings()
{
	sNode* curString;
	sNode* curString2;
	char* stringValue;

	// compile strings in compiler->strings
	for (std::vector<sNode*>::iterator it = compiler->strings.begin(); it < compiler->strings.end(); it++)
	{
		curString = *it;

		if (curString->nodeType == TYPE_COMPILED_STRING)
			continue;

		// backup string value
		stringValue = curString->stringValue;

		// allocate compiledString struct (overwrites stringValue)
		curString->compiledString = (sCompiledString*)malloc(sizeof(sCompiledString));
		memset(curString->compiledString, 0, sizeof(sCompiledString));

		// check if the string is a keyword
		if (curString->nodeType == TYPE_IDENTIFIER)
		{
			if (!strcmp(stringValue, "anim"))
			{
				free(stringValue);
				curString->compiledString->keywordType = TYPE_KWRD_ANIM;
				curString->compiledString->isKeyword = true;
				curString->nodeType = TYPE_COMPILED_STRING;
			}
			else if (!strcmp(stringValue, "game"))
			{
				free(stringValue);
				curString->compiledString->keywordType = TYPE_KWRD_GAME;
				curString->compiledString->isKeyword = true;
				curString->nodeType = TYPE_COMPILED_STRING;
			}
			else if (!strcmp(stringValue, "level"))
			{
				free(stringValue);
				curString->compiledString->keywordType = TYPE_KWRD_LEVEL;
				curString->compiledString->isKeyword = true;
				curString->nodeType = TYPE_COMPILED_STRING;
			}
			else if (!strcmp(stringValue, "self"))
			{
				free(stringValue);
				curString->compiledString->keywordType = TYPE_KWRD_SELF;
				curString->compiledString->isKeyword = true;
				curString->nodeType = TYPE_COMPILED_STRING;
			}
			else
				goto nonkeyword;
		}
		else
		{
nonkeyword:
			curString->compiledString->isKeyword = false;

			// compile string
			curString->compiledString->stringValue = stringValue;
			curString->compiledString->type = curString->nodeType;
		
			// safe check for string offset
			if (compiler->GetRelPos() + strlen(curString->compiledString->GetString()) + 1 > 0xFFFF)
				CompileError("CompileStrings: too many strings");
			curString->compiledString->offset = (WORD)compiler->GetRelPos();

			compiler->AddBytes(curString->compiledString->GetString(), strlen(curString->compiledString->GetString()) + 1);
			curString->nodeType = TYPE_COMPILED_STRING;

			// check if there's any other string with the same content, if yes, then compile those too
			for (std::vector<sNode*>::iterator it2 = compiler->strings.begin(); it2 < compiler->strings.end(); it2++)
			{
				curString2 = *it2;

				if (curString2 != curString && !strcmp(curString2->stringValue, curString->compiledString->GetString()))
				{
					assert(curString2->nodeType != TYPE_COMPILED_STRING);

					stringValue = curString2->stringValue;

					curString2->compiledString = (sCompiledString*)malloc(sizeof(sCompiledString));

					curString2->compiledString->isKeyword = false;

					curString2->compiledString->type = curString2->nodeType;
					curString2->compiledString->stringValue = stringValue;
					curString2->compiledString->offset = curString->compiledString->GetOffset();
					curString2->nodeType = TYPE_COMPILED_STRING;
				}
			}
		}
	}
}

void EmitIncludes()
{
	COD9_GSC* gsc = compiler->gsc;
	sNode* curInclude;
	sNode* curInclude2;
	includeStruct curIncludeStruct;

	gsc->includeStructs = compiler->GetRelPos();

	for (std::vector<sNode*>::iterator it = compiler->sourceCode->begin(); it < compiler->sourceCode->end(); it++)
	{
		curInclude = *it;

		if (curInclude->nodeType != TYPE_COMPILED_STRING || curInclude->compiledString->type != TYPE_INCLUDE)
			continue;
		
		// make sure the include isn't duplicated, if it is then throw an error
		for (std::vector<sNode*>::iterator it2 = compiler->sourceCode->begin(); it2 < compiler->sourceCode->end(); it2++)
		{
			curInclude2 = *it2;
			
			if (curInclude2->nodeType == TYPE_COMPILED_STRING && curInclude2->compiledString->type == TYPE_INCLUDE &&
				curInclude2 != curInclude && curInclude2->compiledString->GetOffset() == curInclude->compiledString->GetOffset())
				CompileError("EmitIncludes: duplicate include \"%s\"", curInclude->compiledString->GetString());
		}
		// set up the includeStruct and write it to the stream
		curIncludeStruct.string = curInclude->compiledString->GetOffset();
		compiler->AddBytes(&curIncludeStruct, sizeof(includeStruct));
		
		gsc->numOfIncludes++;
	}
}

// writes the opcode to the stream, nothing else
void EmitOpcode(bo2_opcode opcode)
{
	compiler->AddByte((BYTE)opcode);
}

BYTE GetLocalVarIndex(WORD identifierOffset)
{
	WORD curLocalVar;
	int counter = 0;
	for (std::vector<WORD>::iterator it = compiler->localVars.begin(); it < compiler->localVars.end(); it++, counter++)
	{
		curLocalVar = *it;

		if (curLocalVar == identifierOffset)
		{
			if (counter < 0xFF)
				return counter;
			else
				CompileError("GetLocalVarIndex: too many local vars");
		}
	}

	return 0xFF;
}

void EmitInteger(int i)
{
	if (i == 0)
		EmitOpcode(OP_GetZero);
	else if (i > 0 && i < 256)
	{
		BYTE i1 = (BYTE)i;
		EmitOpcode(OP_GetByte);
		compiler->AddByte(i1);
	}
	else if (i > 0 && i < 65536)
	{
		WORD i2 = (WORD)i;
		EmitOpcode(OP_GetUnsignedShort);
		compiler->AddWord(i2);
	}
	else if (i < 0 && i > -256)
	{
		BYTE ni1 = (BYTE)-i;
		EmitOpcode(OP_GetNegByte);
		compiler->AddByte(ni1);
	}
	else if (i < 0 && i > -65536)
	{
		WORD ni2 = (WORD)-i;
		EmitOpcode(OP_GetNegUnsignedShort);
		compiler->AddWord(ni2);
	}
	else
	{
		DWORD i4 = (DWORD)i;
		EmitOpcode(OP_GetInteger);
		compiler->AddDword(i4);
	}
}

bool EmitIdentifier(sCompiledString* Identifier, bool ref, bool object)
{
	// check if it's a keyword
	if (Identifier->isKeyword)
	{
		switch (Identifier->keywordType)
		{
		case TYPE_KWRD_ANIM:
			if (ref)
				CompileError("EmitIdentifier->Keyword: anim doesn't have a reference");
			else if (object)
			{
				EmitOpcode(OP_GetAnimObject);
				return true;
			}
			else
				EmitOpcode(OP_GetAnim);
			break;
		case TYPE_KWRD_GAME:
			if (ref)
				EmitOpcode(OP_GetGameRef); // not sure
			else if (object)
				CompileError("EmitIdentifier->Keyword: game doesn't have an object");
			else
				EmitOpcode(OP_GetGame);
			break;
		case TYPE_KWRD_LEVEL:
			if (ref)
				CompileError("EmitIdentifier->Keyword: level doesn't have a reference");
			else if (object)
			{
				EmitOpcode(OP_GetLevelObject);
				return true;
			}
			else
				EmitOpcode(OP_GetLevel);
			break;
		case TYPE_KWRD_SELF:
			if (ref)
				CompileError("EmitIdentifier->Keyword: self doesn't have a reference");
			else if (object)
			{
				EmitOpcode(OP_GetSelfObject);
				return true;
			}
			else
				EmitOpcode(OP_GetSelf);
			break;
		default:
			CompileError("EmitIdentifier: unexpected keyword type %d", Identifier->keywordType);
			return false;
		}

		return false;
	}
	else
	{
		// if it's not a keyword, then it must be a local variable
		BYTE localVarIndex = GetLocalVarIndex(Identifier->GetOffset());
		if (localVarIndex != 0xFF)
		{
			EmitOpcode(ref ? OP_EvalLocalVariableRefCached : OP_EvalLocalVariableCached);
			compiler->AddByte(localVarIndex);
		}
		else
			CompileError("EmitIdentifier: undefined identifier %s", Identifier->GetString());

		return false;
	}
}

void EmitString(sCompiledString* compiledString)
{
	EmitOpcode(OP_GetString);
	compiler->AddWord(compiledString->GetOffset());
}

void EmitLocString(sCompiledString* compiledString)
{
	EmitOpcode(OP_GetIString);
	compiler->AddWord(compiledString->GetOffset());
}

void EmitHashString(DWORD h)
{
	EmitOpcode(OP_GetHash);
	compiler->AddDword(h);
}

// returns true if it has emited an object (GetAnimObject, GetLevelObject or GetSelfObject)
bool EmitCompiledString(sCompiledString* compiledString, bool ref, bool object)
{
	switch (compiledString->type)
	{
	case TYPE_IDENTIFIER:
		return EmitIdentifier(compiledString, ref, object);
	case TYPE_STRING:
		EmitString(compiledString);
		return false;
	case TYPE_LOC_STRING:
		EmitLocString(compiledString);
		return false;
	default:
		CompileError("EmitCompiledString: unexpected compiled string type %d", compiledString->type);
		return false;
	}
}

void EmitFloat(float f)
{
	EmitOpcode(OP_GetFloat);
	compiler->AddFloat(f);
}

// vector_scale optimization not added
void EmitVector(sNode* n1, sNode* n2, sNode* n3)
{
	if (n1->nodeType != TYPE_EXPRESSION || n2->nodeType != TYPE_EXPRESSION || n3->nodeType != TYPE_EXPRESSION)
		CompileError("EmitVector: wrong node types %d, %d and %d", n1->nodeType, n2->nodeType, n3->nodeType);

	sExpression* e1 = n1->expression;
	sExpression* e2 = n2->expression;
	sExpression* e3 = n3->expression;

	if ((e1->type == TYPE_EXPR_INT || e1->type == TYPE_EXPR_FLOAT) &&
		(e2->type == TYPE_EXPR_INT || e2->type == TYPE_EXPR_FLOAT) &&
		(e3->type == TYPE_EXPR_INT || e3->type == TYPE_EXPR_FLOAT))
	{
		float f1 = e1->type == TYPE_EXPR_INT ? (float)e1->nodeList->at(0)->intValue : e1->nodeList->at(0)->floatValue;
		float f2 = e2->type == TYPE_EXPR_INT ? (float)e2->nodeList->at(0)->intValue : e2->nodeList->at(0)->floatValue;
		float f3 = e3->type == TYPE_EXPR_INT ? (float)e3->nodeList->at(0)->intValue : e3->nodeList->at(0)->floatValue;

		if ((f1 == -1.0f || f1 == 0.0f || f1 == 1.0f) &&
			(f2 == -1.0f || f2 == 0.0f || f2 == 1.0f) &&
			(f3 == -1.0f || f3 == 0.0f || f3 == 1.0f))
		{
			BYTE flag = 0;
			if (f1 == 1.0f)
				flag |= 0x20;
			else if (f1 == -1.0f)
				flag |= 0x10;

			if (f2 == 1.0f)
				flag |= 0x08;
			else if (f2 == -1.0f)
				flag |= 0x04;

			if (f3 == 1.0f)
				flag |= 0x02;
			else if (f3 == -1.0f)
				flag |= 0x01;

			EmitOpcode(OP_GetSimpleVector);
			compiler->AddByte(flag);
		}
		else
		{
			EmitOpcode(OP_GetVector);
			compiler->AddFloat(f1);
			compiler->AddFloat(f2);
			compiler->AddFloat(f3);
		}
	}
	else
	{
		EmitExpression(n3, false, false);
		EmitExpression(n2, false, false);
		EmitExpression(n1, false, false);
		EmitOpcode(OP_vector);
	}

	// OP_GetSimpleVector -> OP_vectorscale optimization
	// string refs
}

void EmitTernaryOperation(sExpression* expression)
{
	int16_t* reserved1;		// pointer where the amount of bytes to jump for the 1st jump will be written
	int16_t* reserved2;		// pointer where the amount of bytes to jump for the 2nd jump will be written
	DWORD relPosBefore;		// used to calculate trueExprSize
	DWORD trueExprSize;		// size of the true expression
	DWORD falseExprSize;	// size of the false expression

	if (expression->type != TYPE_EXPR_TERNARY_OP)
		CompileError("EmitTernaryOperation: wrong expression type %d", expression->type);

	// emit the expressions and the jump opcodes

	// this is what will check if the expression is true or false
	EmitExpression(expression->nodeList->at(0), false, false);
	EmitOpcode(OP_JumpOnFalse);
	reserved1 = compiler->ReserveInt16();

	// this is the code which will get executed if the expression is true
	relPosBefore = compiler->GetRelPos();
	EmitExpression(expression->nodeList->at(1), false, false);
	EmitOpcode(OP_jump);
	reserved2 = compiler->ReserveInt16();
	trueExprSize = compiler->GetRelPos() - relPosBefore;

	// this is the code which will get executed if the expression is false
	falseExprSize = EmitExpression(expression->nodeList->at(2), false, false);

	// check the expression sizes to not be higher than INT16_MAX
	if (trueExprSize > INT16_MAX || falseExprSize > INT16_MAX)
		CompileError("EmitTernaryOperation: too many bytes written for true/false expressions");

	// write the amount of bytes to jump for each jump opcode to the reserved slots
	*reserved1 = (int16_t)trueExprSize;
	*reserved2 = (int16_t)falseExprSize;
}

void EmitBinaryOperation(sExpression* expression)
{
	// emit expressions
	EmitExpression(expression->nodeList->at(1), false, false);
	EmitExpression(expression->nodeList->at(0), false, false);

	// emit opcode
	switch (expression->type)
	{
	case TYPE_EXPR_BIT_OR_OP:
		EmitOpcode(OP_bit_or);
		break;
	case TYPE_EXPR_BIT_EX_OR_OP:
		EmitOpcode(OP_bit_ex_or);
		break;
	case TYPE_EXPR_BIT_AND_OP:
		EmitOpcode(OP_bit_and);
		break;
	case TYPE_EXPR_EQUALITY_OP:
		EmitOpcode(OP_equality);
		break;
	case TYPE_EXPR_INEQUALITY_OP:
		EmitOpcode(OP_inequality);
		break;
	case TYPE_EXPR_LESS_OP:
		EmitOpcode(OP_less);
		break;
	case TYPE_EXPR_GREATER_OP:
		EmitOpcode(OP_greater);
		break;
	case TYPE_EXPR_LESS_EQUAL_OP:
		EmitOpcode(OP_less_equal);
		break;
	case TYPE_EXPR_GREATER_EQUAL_OP:
		EmitOpcode(OP_greater_equal);
		break;
	case TYPE_EXPR_SHIFT_LEFT_OP:
		EmitOpcode(OP_shift_left);
		break;
	case TYPE_EXPR_SHIFT_RIGHT_OP:
		EmitOpcode(OP_shift_right);
		break;
	case TYPE_EXPR_PLUS_OP:
		EmitOpcode(OP_plus);
		break;
	case TYPE_EXPR_MINUS_OP:
		EmitOpcode(OP_minus);
		break;
	case TYPE_EXPR_MULTIPLY_OP:
		EmitOpcode(OP_multiply);
		break;
	case TYPE_EXPR_DIVIDE_OP:
		EmitOpcode(OP_divide);
		break;
	case TYPE_EXPR_MOD_OP:
		EmitOpcode(OP_mod);
		break;
	case TYPE_EXPR_BOOL_NOT_OP:
		EmitOpcode(OP_BoolNot);
		break;
	case TYPE_EXPR_BOOL_COMPLEMENT_OP:
		EmitOpcode(OP_BoolComplement);
		break;
	default:
		CompileError("EmitBinaryOperation: unexpected operation type %d", expression->type);
		break;
	}
}

// OP_CastBool doesn't seem to be used
void EmitUnaryOperation(sExpression* expression)
{
	// emit expression
	EmitExpression(expression->nodeList->at(0), false, false);

	// emit opcode
	switch (expression->type)
	{
	case TYPE_EXPR_BOOL_NOT_OP:
		EmitOpcode(OP_BoolNot);
		break;
	case TYPE_EXPR_BOOL_COMPLEMENT_OP:
		EmitOpcode(OP_BoolComplement);
		break;
	default:
		CompileError("EmitUnaryOperation: unexpected operation type %d", expression->type);
		break;
	}
}

void EmitArraySubscriptingExpression(sArraySubscriptingExpression* arraySubscriptingExpression, bool ref)
{
	// emit the index expression
	EmitExpression(arraySubscriptingExpression->index, false, false);

	// emit the array
	EmitExpression(arraySubscriptingExpression->arrayName, ref, false);

	// emit the opcode
	EmitOpcode(ref ? OP_EvalArrayRef : OP_EvalArray);
}

void EmitElementSelectionExpression(sElementSelectionExpression* elementSelectionExpression, bool ref)
{
	// emit the object
	EmitExpression(elementSelectionExpression->object, false, true);
	
	// emit code to access the element (or get the size)
	if (elementSelectionExpression->isSize)
	{
		if (ref)
			CompileError("EmitElementSelectionExpression: size element can't be referenced");

		EmitOpcode(OP_size);
	}
	else
	{
		EmitOpcode(ref ? OP_EvalFieldVariableRef : OP_EvalFieldVariable);

		if (elementSelectionExpression->selectedElement->nodeType != TYPE_COMPILED_STRING ||
			elementSelectionExpression->selectedElement->compiledString->type != TYPE_IDENTIFIER)
			CompileError("EmitElementSelectionExpression: wrong selectedElement node type %d", elementSelectionExpression->selectedElement->nodeType);

		compiler->AddWord(elementSelectionExpression->selectedElement->compiledString->GetOffset());
	}
}

// returns the amount of bytes written
DWORD EmitExpression(sNode* expressionNode, bool ref, bool object)
{
	DWORD relPosBefore = compiler->GetRelPos();

	bool emitedObject = false;

	if (ref && object)
		CompileError("EmitExpression: parameters ref and object can't be both true");

	if (expressionNode->nodeType == TYPE_EXPRESSION)
	{
		sExpression* expression = expressionNode->expression;

		switch (expression->type)
		{
		case TYPE_EXPR_IDENTIFIER:
		case TYPE_EXPR_STRING:
		case TYPE_EXPR_LOC_STRING:
			{
				sNode* node = expression->nodeList->at(0);

				if (node->nodeType != TYPE_COMPILED_STRING)
					CompileError("EmitExpression->Identifier/String/LocString: wrong node type %d", node->nodeType);

				emitedObject = EmitCompiledString(node->compiledString, ref, object);
			}
			break;
		case TYPE_EXPR_FUNC_CALL_NOTHRD:
			break;
		case TYPE_EXPR_ARRAY_SUBSCRIPTING:
			{
				sNode* node = expression->nodeList->at(0);

				if (node->nodeType != TYPE_ARRAY_SUBSCRIPTING_EXPRESSION)
					CompileError("EmitExpression->TYPE_EXPR_ARRAY_SUBSCRIPTING: wrong node type %d", node->nodeType);

				sArraySubscriptingExpression* arraySubscriptingExpression = node->arraySubscriptingExpression;
				EmitArraySubscriptingExpression(arraySubscriptingExpression, ref);
			}
			break;
		case TYPE_EXPR_ELEMENT_SELECTION:
			{
				sNode* node = expression->nodeList->at(0);

				if (node->nodeType != TYPE_ELEMENT_SELECTION_EXPRESSION)
					CompileError("EmitExpression->TYPE_EXPR_ELEMENT_SELECTION: wrong node type %d", node->nodeType);

				sElementSelectionExpression* elementSelectionExpression = node->elementSelectionExpression;
				EmitElementSelectionExpression(elementSelectionExpression, ref);
			}
		case TYPE_EXPR_FUNC_REF:
			break;
		case TYPE_EXPR_INT:
			EmitInteger(expression->nodeList->at(0)->intValue);
			break;
		case TYPE_EXPR_FLOAT:
			EmitFloat(expression->nodeList->at(0)->floatValue);
			break;
		case TYPE_EXPR_HASH_STRING:
			EmitHashString((DWORD)expression->nodeList->at(0)->intValue);
			break;
		case TYPE_EXPR_VECTOR:
			EmitVector(expression->nodeList->at(0), expression->nodeList->at(1), expression->nodeList->at(2));
			break;
		case TYPE_EXPR_EMPTY_ARRAY:
			EmitOpcode(OP_EmptyArray);
			break;
		case TYPE_EXPR_UNDEFINED:
			EmitOpcode(OP_GetUndefined);
			break;
		case TYPE_EXPR_TERNARY_OP:
			EmitTernaryOperation(expression);
			break;
		case TYPE_EXPR_BIT_OR_OP:
		case TYPE_EXPR_BIT_EX_OR_OP:
		case TYPE_EXPR_BIT_AND_OP:
		case TYPE_EXPR_EQUALITY_OP:
		case TYPE_EXPR_INEQUALITY_OP:
		case TYPE_EXPR_LESS_OP:
		case TYPE_EXPR_GREATER_OP:
		case TYPE_EXPR_LESS_EQUAL_OP:
		case TYPE_EXPR_GREATER_EQUAL_OP:
		case TYPE_EXPR_SHIFT_LEFT_OP:
		case TYPE_EXPR_SHIFT_RIGHT_OP:
		case TYPE_EXPR_PLUS_OP:
		case TYPE_EXPR_MINUS_OP:
		case TYPE_EXPR_MULTIPLY_OP:
		case TYPE_EXPR_DIVIDE_OP:
		case TYPE_EXPR_MOD_OP:
			EmitBinaryOperation(expression);
			break;
		case TYPE_EXPR_BOOL_NOT_OP:
		case TYPE_EXPR_BOOL_COMPLEMENT_OP:
			EmitUnaryOperation(expression);
			break;
		case TYPE_EXPR_LOGICAL_OR_OP:
		case TYPE_EXPR_LOGICAL_AND_OP:
		case TYPE_EXPR_UANIMREF_OP:
			break;
		default:
			CompileError("EmitExpression: unexpected expression type %d", expression->type);
			break;
		}
	}
	else
	{
		switch (expressionNode->nodeType)
		{
		case TYPE_COMPILED_STRING:
			emitedObject = EmitCompiledString(expressionNode->compiledString, ref, object);
			break;
		case TYPE_FUNC_CALL_EXPRESSION:
			break;
		case TYPE_ARRAY_SUBSCRIPTING_EXPRESSION:
			{
				sArraySubscriptingExpression* arraySubscriptingExpression = expressionNode->arraySubscriptingExpression;
				EmitArraySubscriptingExpression(arraySubscriptingExpression, ref);
			}
			break;
		case TYPE_ELEMENT_SELECTION_EXPRESSION:
			{
				sElementSelectionExpression* elementSelectionExpression = expressionNode->elementSelectionExpression;
				EmitElementSelectionExpression(elementSelectionExpression, ref);
			}
			break;
		case TYPE_FUNC_REF_EXPRESSION:
			break;
		default:
			// unexpected type here because self isn't added to the compiled string array
			CompileError("EmitExpression->Other type: unexpected node type %d", expressionNode->nodeType);
			break;
		}
	}

	// if we need an object and we didn't emit one yet, then cast the expression result to an object
	if (object && !emitedObject)
		EmitOpcode(OP_CastFieldObject);

	return compiler->GetRelPos() - relPosBefore;
}

void EmitAssignmentStatement(EStatementType type, sNode* lvalue, sNode* rvalue)
{
	if ((lvalue->nodeType != TYPE_COMPILED_STRING && lvalue->nodeType != TYPE_ARRAY_SUBSCRIPTING_EXPRESSION &&
		lvalue->nodeType != TYPE_ELEMENT_SELECTION_EXPRESSION) || rvalue->nodeType != TYPE_EXPRESSION)
		CompileError("EmitAssignmentStatement: wrong node types %d and %d", lvalue->nodeType, rvalue->nodeType);

	if (type == TYPE_STMT_REGULAR_ASSIGN)
	{
		// special check for local variable creation
		if (lvalue->nodeType == TYPE_COMPILED_STRING &&
			lvalue->compiledString->type == TYPE_IDENTIFIER &&
			GetLocalVarIndex(lvalue->compiledString->GetOffset()) == 0xFF)
		{
			compiler->localVars.push_back(lvalue->compiledString->GetOffset());
		}

		// OP_ClearFieldVariable and OP_ClearArray check
		if (rvalue->expression->type == TYPE_EXPR_UNDEFINED)
		{
			if (lvalue->nodeType == TYPE_ELEMENT_SELECTION_EXPRESSION)
			{
				sElementSelectionExpression* elementSelectionExpression = lvalue->elementSelectionExpression;
				EmitExpression(elementSelectionExpression->object, false, true);
				EmitOpcode(OP_ClearFieldVariable);
				
				if (elementSelectionExpression->selectedElement->nodeType != TYPE_COMPILED_STRING ||
					elementSelectionExpression->selectedElement->compiledString->type != TYPE_IDENTIFIER)
					CompileError("EmitAssignmentStatement->OP_ClearFieldVariable: wrong selectedElement node type %d", elementSelectionExpression->selectedElement->nodeType);
				
				compiler->AddWord(elementSelectionExpression->selectedElement->compiledString->GetOffset());
			}
			else if (lvalue->nodeType == TYPE_ARRAY_SUBSCRIPTING_EXPRESSION)
			{
				sArraySubscriptingExpression* arraySubscriptingExpression = lvalue->arraySubscriptingExpression;
				EmitExpression(arraySubscriptingExpression->index, false, false);
				EmitExpression(arraySubscriptingExpression->arrayName, true, false);
				EmitOpcode(OP_ClearArray);
			}
			else
				goto regularassign;
		}
		else
		{
regularassign:
			EmitExpression(rvalue, false, false);
			EmitExpression(lvalue, true, false);
			EmitOpcode(OP_SetVariableField);
		}
	}
	else
	{
		EmitExpression(lvalue, false, false);
		EmitExpression(rvalue, false, false);
		switch (type)
		{
		case TYPE_STMT_PLUS_ASSIGN:
			EmitOpcode(OP_plus);
			break;
		case TYPE_STMT_MINUS_ASSIGN:
			EmitOpcode(OP_minus);
			break;
		case TYPE_STMT_MULTIPLY_ASSIGN:
			EmitOpcode(OP_multiply);
			break;
		case TYPE_STMT_DIVIDE_ASSIGN:
			EmitOpcode(OP_divide);
			break;
		case TYPE_STMT_MOD_ASSIGN:
			EmitOpcode(OP_mod);
			break;
		case TYPE_STMT_SHIFT_LEFT_ASSIGN:
			EmitOpcode(OP_shift_left);
			break;
		case TYPE_STMT_SHIFT_RIGHT_ASSIGN:
			EmitOpcode(OP_shift_right);
			break;
		case TYPE_STMT_BIT_AND_ASSIGN:
			EmitOpcode(OP_bit_and);
			break;
		case TYPE_STMT_BIT_EX_OR_ASSIGN:
			EmitOpcode(OP_bit_ex_or);
			break;
		case TYPE_STMT_BIT_OR_ASSIGN:
			EmitOpcode(OP_bit_or);
			break;
		default:
			CompileError("EmitAssignmentStatement: unexpected assignment type %d", type);
			break;
		}
		EmitExpression(lvalue, true, false);
		EmitOpcode(OP_SetVariableField);
	}
}

void EmitReturnStatement(sExpression* expression)
{

}

void EmitIfStatement(sExpression* ifExpression, sStatement* ifStatement)
{

}

void EmitIfElseStatement(sExpression* ifExpression, sStatement* ifStatement, sStatement* elseStatement)
{

}

// maybe sNode* statement?
void EmitStatement(sStatement* statement)
{
	switch (statement->type)
	{
	case TYPE_STMT_INC:
	case TYPE_STMT_DEC:
		break;
	case TYPE_STMT_REGULAR_ASSIGN:
	case TYPE_STMT_PLUS_ASSIGN:
	case TYPE_STMT_MINUS_ASSIGN:
	case TYPE_STMT_MULTIPLY_ASSIGN:
	case TYPE_STMT_DIVIDE_ASSIGN:
	case TYPE_STMT_MOD_ASSIGN:
	case TYPE_STMT_SHIFT_LEFT_ASSIGN:
	case TYPE_STMT_SHIFT_RIGHT_ASSIGN:
	case TYPE_STMT_BIT_AND_ASSIGN:
	case TYPE_STMT_BIT_EX_OR_ASSIGN:
	case TYPE_STMT_BIT_OR_ASSIGN:
		{
			sNode* node1 = statement->nodeList->at(0);
			sNode* node2 = statement->nodeList->at(1);

			EmitAssignmentStatement(statement->type, node1, node2);
		}
		break;
	case TYPE_STMT_CASE:
		break;
	case TYPE_STMT_DEFAULT:
		break;
	case TYPE_STMT_CONTINUE:
		break;
	case TYPE_STMT_BREAK:
		break;
	case TYPE_STMT_RETURN:
		{
			sNode* node = statement->nodeList->at(0);

			if (node)
			{
				if (node->nodeType != TYPE_EXPRESSION)
					CompileError("EmitStatement->TYPE_STMT_RETURN: wrong node type %d", node->nodeType);
				EmitExpression(node, false, false);
				EmitOpcode(OP_Return);
			}
			else
				EmitOpcode(OP_End);
		}
		break;
	case TYPE_STMT_WAIT:
		break;
	case TYPE_STMT_WAITTILLFRAMEEND:
		break;
	case TYPE_STMT_EXPRESSION_STATEMENT:
		{
			sNode* node = statement->nodeList->at(0);

			if (node)
			{
				// check for inc_dec_statement and assignment_statement special case
				if (node->nodeType == TYPE_STATEMENT)
					EmitStatement(node->statement);
				else
				{
					EmitExpression(node, false, false);

					// if it was a function call, emit an opcode to pop the return value
					if (node->nodeType == TYPE_FUNC_CALL_EXPRESSION)
						EmitOpcode(OP_DecTop);
				}
			}
		}
		break;
	case TYPE_STMT_COMPOUND:
		if (statement->nodeList)
		{
			sNode* curNode;
			for (std::vector<sNode*>::iterator it = statement->nodeList->begin(); it < statement->nodeList->end(); it++)
			{
				curNode = *it;

				EmitStatement(curNode->statement);
			}
		}
		break;
	case TYPE_STMT_IF:
		{
			sNode* node1 = statement->nodeList->at(0);
			sNode* node2 = statement->nodeList->at(1);

			EmitIfStatement(node1->expression, node2->statement);
		}
		break;
	case TYPE_STMT_IF_ELSE:
		{
			sNode* node1 = statement->nodeList->at(0);
			sNode* node2 = statement->nodeList->at(1);
			sNode* node3 = statement->nodeList->at(2);

			EmitIfElseStatement(node1->expression, node2->statement, node3->statement);
		}
		break;
	case TYPE_STMT_SWITCH:
		break;
	case TYPE_STMT_FOR:
		break;
	case TYPE_STMT_WHILE:
		break;
	case TYPE_STMT_FOREACH:
		break;
	default:
		CompileError("EmitStatement: unexpected statement type %d", statement->type);
		break;
	}
}

void EmitFunction(sFuncDefinition* funcDefinition)
{
	sNode* curNode;

	compiler->AlignPos(16);

	// push the function parameters to the local var list (if the it has any)
	if (funcDefinition->parameterList)
	{
		for (std::vector<sNode*>::iterator it = funcDefinition->parameterList->begin(); it < funcDefinition->parameterList->end(); it++)
		{
			curNode = *it;

			if (curNode->nodeType != TYPE_COMPILED_STRING || curNode->compiledString->type != TYPE_IDENTIFIER)
				CompileError("EmitFunction: wrong type of parameter");

			compiler->localVars.push_back(curNode->compiledString->GetOffset());
		}
	}

	// iterate through all the code nodes and emit the opcodes
	std::vector<sNode*>* code = funcDefinition->compoundStatement->statement->nodeList;
	for (std::vector<sNode*>::iterator it = code->begin(); it < code->end(); it++)
	{
		curNode = *it;

		if (curNode->nodeType != TYPE_STATEMENT)
			CompileError("EmitFunction: unexpected curNode type %d at function scope", curNode->nodeType);
		
		EmitStatement(curNode->statement);
	}
}

void EmitFunctions()
{
	COD9_GSC* gsc = compiler->gsc;
	sNode* curFuncDefinition;

	for (std::vector<sNode*>::iterator it = compiler->sourceCode->begin(); it < compiler->sourceCode->end(); it++)
	{
		curFuncDefinition = *it;

		if (curFuncDefinition->nodeType != TYPE_FUNC_DEFINITION)
			continue;

		if (curFuncDefinition->funcDefinition/*->compoundStatement->statement->nodeList*/)
			EmitFunction(curFuncDefinition->funcDefinition/*->compoundStatement->statement->nodeList*/);
	}
}

/*
	IMPORTANT, COMPILED GSC DATA ORDER:

	1.	header
	2.	gsc name
	3.	string table
	4.	includeStructs
	5.	unknown code section start bullshit, most likely padding
	6.	function code -> there're some bytes before/after each function, but its most likely just weird padding
	7.	funcDefinitions
	8.	referencedFunctions (gonna rename this)
	9.	usinganimtreeStructs
	10.	want more data? well no, fuck you
*/

void OnParsingComplete()
{
	COD9_GSC* gsc = compiler->gsc;

	memcpy(&gsc->identifier, COD9_GSC_IDENTIFIER, sizeof(COD9_GSC_IDENTIFIER));

	// add relative path of compiled gsc
	gsc->name = (WORD)compiler->GetRelPos();
	compiler->AddBytes(compiler->relativePath, strlen(compiler->relativePath) + 1);

	// for nodes which are strings, sets up compiledString member
	CompileStrings();

	EmitIncludes();

	EmitFunctions();
}

void Preyyparse(char* relativePath, char* outputDir, bool devMode)
{
	lineCount = 1;

	compiler = new sCompiler();

	// fix relative path slashes
	compiler->relativePath = _strdup(relativePath);
	for (char* c = compiler->relativePath; *c; c++)
	{
		if (*c == '\\')
			*c = '/';
	}
	
	// open output file
	compiler->outputDir = outputDir;
	fopen_s(&compiler->outputFile, compiler->outputDir, "wb");

	// set dev mode bool
	compiler->devMode = devMode;
}

void Postyyparse()
{
	fwrite(compiler->buf, 1, compiler->GetRelPos(), compiler->outputFile);
	fclose(compiler->outputFile);

	free(compiler->relativePath);
	delete compiler;
}

int main(int argc, char* argv[])
{
	// set debug mode so the stderr log is written by bison
	yydebug = 1;

	// create a stderr log
	FILE* stderrlog = NULL;
	freopen_s(&stderrlog, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\stderr.log", "w", stderr);

	FILE* inputFile = NULL;
	fopen_s(&inputFile, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\script_parse_test.gsc", "r");
	yyin = inputFile;

	// parse the game script
	// loop through the raw bo1 folder to parse the game scripts
	//recursive_yyparse("E:\\Program Files (x86)\\Steam\\steamapps\\common\\call of duty black ops\\raw\\*");

	Preyyparse("maps/mp/gametypes/_rank.gsc", "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\script_parse_test_out.gsc", false);
	yyparse();
	Postyyparse();

	cin.get();

	// close file handles & exit
	fclose(inputFile);
	fclose(stderrlog);
	return 0;
}