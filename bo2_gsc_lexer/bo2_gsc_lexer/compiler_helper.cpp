#include "stdafx.h"

/* nodes */
sNode* AllocNode(ENodeType nodeType)
{
	//printf("allocating node %d\n", nodeType);

	sNode* allocatedNode = (sNode*)malloc(sizeof(sNode));
	assert(allocatedNode != NULL);

	switch (nodeType)
	{
	case TYPE_FUNC_DEFINITION:
		allocatedNode->funcDefinition = (sFuncDefinition*)malloc(sizeof(sFuncDefinition));
		assert(allocatedNode->funcDefinition != NULL);
		break;
	case TYPE_INC_DEC_EXPRESSION:
		allocatedNode->incDecExpression = (sIncDecExpression*)malloc(sizeof(sIncDecExpression));
		assert(allocatedNode->incDecExpression != NULL);
		break;
	case TYPE_FUNC_CALL:
		allocatedNode->funcCall = (sFuncCall*)malloc(sizeof(sFuncCall));
		assert(allocatedNode->funcCall != NULL);
		break;
	case TYPE_ARRAY_SUBSCRIPTING_EXPRESSION:
		allocatedNode->arraySubscriptingExpression = (sArraySubscriptingExpression*)malloc(sizeof(sArraySubscriptingExpression));
		assert(allocatedNode->arraySubscriptingExpression != NULL);
		break;
	case TYPE_ELEMENT_SELECTION_EXPRESSION:
		allocatedNode->elementSelectionExpression = (sElementSelectionExpression*)malloc(sizeof(sElementSelectionExpression));
		assert(allocatedNode->elementSelectionExpression != NULL);
		break;
	case TYPE_FUNC_REF_EXPRESSION:
		allocatedNode->funcRefExpression = (sFuncRefExpression*)malloc(sizeof(sFuncRefExpression));
		assert(allocatedNode->funcRefExpression != NULL);
		break;
	case TYPE_EXPRESSION:
		allocatedNode->expression = (sExpression*)malloc(sizeof(sExpression));
		assert(allocatedNode->expression != NULL);
		break;
	case TYPE_ASSIGNMENT_EXPRESSION:
		allocatedNode->assignmentExpression = (sAssignmentExpression*)malloc(sizeof(sAssignmentExpression));
		assert(allocatedNode->assignmentExpression != NULL);
		break;
	case TYPE_STATEMENT:
		allocatedNode->statement = (sStatement*)malloc(sizeof(sStatement));
		assert(allocatedNode->statement != NULL);
		break;
	}

	allocatedNode->nodeType = nodeType;

	return allocatedNode;
}

sNode* IdentifierNode(char* identifierVal)
{
	sNode* allocatedNode = AllocNode(TYPE_IDENTIFIER);
	allocatedNode->stringValue = identifierVal;

	return allocatedNode;
}

sNode* PathNode(char* pathVal)
{
	sNode* allocatedNode = AllocNode(TYPE_PATH);
	allocatedNode->stringValue = pathVal;

	return allocatedNode;
}

sNode* IntNode(int intVal)
{
	sNode* allocatedNode = AllocNode(TYPE_INT);
	allocatedNode->intValue = intVal;

	return allocatedNode;
}

sNode* FloatNode(float floatVal)
{
	sNode* allocatedNode = AllocNode(TYPE_FLOAT);
	allocatedNode->floatValue = floatVal;

	return allocatedNode;
}

sNode* StringNode(char* stringVal)
{
	sNode* allocatedNode = AllocNode(TYPE_STRING);
	allocatedNode->stringValue = stringVal;

	return allocatedNode;
}

sNode* LocStringNode(char* locStringVal)
{
	sNode* allocatedNode = AllocNode(TYPE_LOC_STRING);
	allocatedNode->stringValue = locStringVal;

	return allocatedNode;
}

sNode* HashStringNode(char* hashStringVal)
{
	sNode* allocatedNode = AllocNode(TYPE_HASH_STRING);
	allocatedNode->stringValue = hashStringVal;

	return allocatedNode;
}

/*sNode* PathToNode(char* path)
{
	sNode* allocatedNode = AllocNode(TYPE_PATH);
	allocatedNode->path = path;

	return allocatedNode;
}

template <typename T>
sNode* LiteralToNode(ENodeType literalType, T literalValue)
{
	sNode* allocatedNode = AllocNode(literalType);

	switch (lteralType)
	{
	case TYPE_INT_LITERAL:
		allocatedNode->intLiteral = literalValue;
		break;
	case TYPE_FLOAT_LITERAL:
		allocatedNode->floatLiteral = literalValue;
		break;
	case TYPE_STRING_LITERAL:
	case TYPE_LOC_STRING_LITERAL:
	case TYPE_HASH_STRING_LITERAL:
		allocatedNode->stringLiteral = literalValue;
		break;
	}

	return allocatedNode;
}*/

/* node allocation */

sNode* AllocInclude(char* filedir)
{
	sNode* result = AllocNode(TYPE_INCLUDE);

	result->stringValue = filedir;

	return result;
}

sNode* AllocUsingAnimTree(char* animtree)
{
	sNode* result = AllocNode(TYPE_USINGANIMTREE);

	result->stringValue = animtree;

	return result;
}

sNode* AllocFuncDefinition(sNode* funcName, std::vector<sNode*>* parameterList, sNode* compoundStatement)
{
	sNode* result = AllocNode(TYPE_FUNC_DEFINITION);

	result->funcDefinition->funcName = funcName;
	result->funcDefinition->parameterList = parameterList;
	result->funcDefinition->compoundStatement = compoundStatement;

	return result;
}

sNode* AllocIncDecExpression(sNode* expression, int isDec)
{
	sNode* result = AllocNode(TYPE_INC_DEC_EXPRESSION);

	result->incDecExpression->expression = expression;
	result->incDecExpression->isDec = isDec;

	return result;
}

sNode* AllocFuncCall(sNode* funcName, sNode* gscOfFunc, std::vector<sNode*>* argumentList, int isPtr, sNode* ptrExpression, int isMethod, sNode* methodObject, int isThread)
{
	sNode* result = AllocNode(TYPE_FUNC_CALL);

	result->funcCall->funcName = funcName;
	result->funcCall->gscOfFunc = gscOfFunc;
	result->funcCall->argumentList = argumentList;
	result->funcCall->isPtr = isPtr;
	result->funcCall->ptrExpression = ptrExpression;
	result->funcCall->isMethod = isMethod;
	result->funcCall->methodObject = methodObject;
	result->funcCall->isThread = isThread;

	return result;
}

sNode* AllocArraySubscriptingExpression(sNode* arrayName, sNode* index)
{
	sNode* result = AllocNode(TYPE_ARRAY_SUBSCRIPTING_EXPRESSION);

	result->arraySubscriptingExpression->arrayName = arrayName;
	result->arraySubscriptingExpression->index = index;

	return result;
}

sNode* AllocElementSelectionExpression(sNode* selection, sNode* selectedElement)
{
	sNode* result = AllocNode(TYPE_ELEMENT_SELECTION_EXPRESSION);

	result->elementSelectionExpression->selection = selection;
	result->elementSelectionExpression->selectedElement = selectedElement;

	return result;
}

sNode* AllocFuncRefExpression(sNode* gscOfFunc, sNode* funcName)
{
	sNode* result = AllocNode(TYPE_FUNC_REF_EXPRESSION);

	result->funcRefExpression->gscOfFunc = gscOfFunc;
	result->funcRefExpression->funcName = funcName;

	return result;
}

sNode* AllocExpression(EExpressionType type, ...)
{
	va_list vl;
	va_start(vl, type);

	sNode* result = AllocNode(TYPE_EXPRESSION);
	result->expression->nodeList = new std::vector<sNode*>();

	switch (type)
	{
	case TYPE_EXPR_EMPTY_ARRAY:
	case TYPE_EXPR_UNDEFINED:
		break;
	case TYPE_EXPR_IDENTIFIER:
	case TYPE_EXPR_UANIMREF_OP:
	case TYPE_EXPR_STRING:
	case TYPE_EXPR_LOC_STRING:
	case TYPE_EXPR_HASH_STRING:
	case TYPE_EXPR_INT:
	case TYPE_EXPR_UMINUS_INT_OP:
	case TYPE_EXPR_FLOAT:
	case TYPE_EXPR_UMINUS_FLOAT_OP:
	case TYPE_EXPR_FUNC_CALL_NOTHRD:
	case TYPE_EXPR_ARRAY_SUBSCRIPTING:
	case TYPE_EXPR_ELEMENT_SELECTION:
	case TYPE_EXPR_FUNC_REF:
	case TYPE_EXPR_BOOL_NOT_OP:
	case TYPE_EXPR_BOOL_COMPLEMENT_OP:
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		break;
	case TYPE_EXPR_LOGICAL_OR_OP:
	case TYPE_EXPR_LOGICAL_AND_OP:
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
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		break;
	case TYPE_EXPR_VECTOR:
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		break;
	}

	result->expression->type = type;

	va_end(vl);

	return result;
}

sNode* AllocAssignmentExpression(EAssignmentType type, sNode* lvalue, sNode* rvalue)
{
	sNode* result = AllocNode(TYPE_ASSIGNMENT_EXPRESSION);

	result->assignmentExpression->lvalue = lvalue;
	result->assignmentExpression->rvalue = rvalue;

	return result;
}

sNode* AllocStatement(EStatementType type, ...)
{
	va_list vl;
	va_start(vl, type);

	sNode* result = AllocNode(TYPE_STATEMENT);
	
	if (type == TYPE_COMPOUND_STATEMENT)
		result->statement->nodeList = va_arg(vl, std::vector<sNode*>*);
	else
	{
		result->statement->nodeList = new std::vector<sNode*>();

		switch (type)
		{
		case TYPE_DEFAULT_STATEMENT:
		case TYPE_CONTINUE_STATEMENT:
		case TYPE_BREAK_STATEMENT:
		case TYPE_WAITTILLFRAMEEND_STATEMENT:
			break;
		case TYPE_CASE_STATEMENT:
		case TYPE_RETURN_STATEMENT:
		case TYPE_WAIT_EXPR_STATEMENT:
		case TYPE_EXPRESSION_STATEMENT:
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			break;
		case TYPE_IF_STATEMENT:
		case TYPE_SWITCH_STATEMENT:
		case TYPE_WHILE_STATEMENT:
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			break;
		case TYPE_IF_ELSE_STATEMENT:
		case TYPE_FOREACH_STATEMENT:
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			break;
		case TYPE_FOR_STATEMENT:
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			break;
		}
	}
	
	result->statement->type = type;

	va_end(vl);

	return result;
}

void FreeNode(sNode* node)
{

}

/* function definitions */
/*sFuncDefinition** funcDefList = 0;
int curFuncDefCount = 0;

void AddFuncDefinition(char* funcName)
{
	curFuncDefCount++;
}*/

/*sExpression* CreateExpression(EExpressionType type, ...)
{
	va_list vl;
	va_start(vl, type);

	sExpression* result = (sExpression*)malloc(sizeof(sExpression));
	result->type = type;

	switch (type)
	{
	case TYPE_EXPR_IDENTIFIER:
	case TYPE_EXPR_STRING:
	case TYPE_EXPR_LOC_STRING:
	case TYPE_EXPR_HASH_STRING:
	case TYPE_EXPR_UANIMREF_OP:
		result->stringValue = va_arg(vl, char*);
		break;
	case TYPE_EXPR_INT:
	case TYPE_EXPR_UMINUS_INT_OP:
		result->intValue = va_arg(vl, int);
		break;
	case TYPE_EXPR_FLOAT:
	case TYPE_EXPR_UMINUS_FLOAT_OP:
		result->floatValue = va_arg(vl, float);
		break;
	case TYPE_EXPR_VECTOR:
		result->expressionList = new std::vector<sExpression*>();
		result->expressionList->push_back(va_arg(vl, sExpression*));
		result->expressionList->push_back(va_arg(vl, sExpression*));
		result->expressionList->push_back(va_arg(vl, sExpression*));
		break;
	case TYPE_EXPR_EMPTY_ARRAY:
	case TYPE_EXPR_UNDEFINED:
		break;
	case TYPE_EXPR_FUNC_CALL_NOTHRD: // implement later
		break;
	case TYPE_EXPR_ARRAY_SUBSCRIPTING: // implement later
		break;
	case TYPE_EXPR_ELEMENT_SELECTION: // implement later
		break;
	case TYPE_EXPR_FUNC_REF: // implement later
		break;
	case TYPE_EXPR_LOGICAL_OR_OP:
	case TYPE_EXPR_LOGICAL_AND_OP:
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
		result->expressionList = new std::vector<sExpression*>();
		result->expressionList->push_back(va_arg(vl, sExpression*));
		result->expressionList->push_back(va_arg(vl, sExpression*));
		break;
	case TYPE_EXPR_BOOL_NOT_OP:
	case TYPE_EXPR_BOOL_COMPLEMENT_OP:
		result->expressionList = new std::vector<sExpression*>();
		result->expressionList->push_back(va_arg(vl, sExpression*));
		break;
	}

	va_end(vl);

	return result;
}*/