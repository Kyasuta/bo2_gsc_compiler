#pragma once

#pragma warning ( disable : 4005 )

#include <inttypes.h>
#include <cassert>
#include <cstdarg>
#include "bo2_gsc_file.h"

void CompileError(char* errorString, ...);

struct sNode;
struct sStatement;

/* compiler struct */

class sCompiler
{
public:
	BYTE buf[0x100000]; // 1mb
	BYTE* bufPos;

	COD9_GSC* gsc;

	char* relativePath;
	char* outputDir;
	FILE* outputFile;

	std::vector<sNode*>* sourceCode;	// main node
	std::vector<sNode*> nodes;			// every node in the source code, used to free them
	std::vector<sNode*> strings;		// every identifier and string in the source code
	std::vector<WORD> localVars;		// local variables of the function that is being compiled

	bool devMode;

	BYTE* GetAbsPos()
	{
		return bufPos;
	}

	DWORD GetRelPos()
	{
		return bufPos - buf;
	}

	void AlignPos(int mod)
	{
		bufPos = buf + ((bufPos - buf + mod - 1) & ~(mod - 1));
	}

	BYTE* AlignedPos(int mod)
	{
		return buf + ((bufPos - buf + mod - 1) & ~(mod - 1));
	}

	void WriteSafeCheck(DWORD elementSize, DWORD elementCount)
	{
		// replace this by CompileError when its integrated into this class
		if (AlignedPos(elementSize)+elementSize*elementCount>buf+sizeof(buf))
			CompileError("sCompiler::WriteSafeCheck: safe check failed");
	}

	void AddBytes(void* bytes, DWORD amount)
	{
		WriteSafeCheck(1, amount);
		memcpy(bufPos, bytes, amount);
		bufPos += amount;
	}

	void AddByte(BYTE byte_)
	{
		WriteSafeCheck(sizeof(BYTE), 1);
		// no need for alignment here
		*(BYTE*)bufPos = byte_;
		bufPos += sizeof(BYTE);
	}

	void AddWord(WORD word_)
	{
		WriteSafeCheck(sizeof(WORD), 1);
		AlignPos(sizeof(WORD));
		*(WORD*)bufPos = word_;
		bufPos += sizeof(WORD);
	}

	void AddDword(DWORD dword_)
	{
		WriteSafeCheck(sizeof(DWORD), 1);
		AlignPos(sizeof(DWORD));
		*(DWORD*)bufPos = dword_;
		bufPos += sizeof(DWORD);
	}

	/*void AddInt16(int16_t int16_)
	{
		*(int16_t*)bufPos = int16_;
		bufPos += sizeof(int16_t);
	}*/

	void AddFloat(float float_)
	{
		WriteSafeCheck(sizeof(float), 1);
		AlignPos(sizeof(float));
		*(float*)bufPos = float_;
		bufPos += sizeof(float);
	}

	int16_t* ReserveInt16()
	{
		WriteSafeCheck(sizeof(int16_t), 1);
		AlignPos(sizeof(int16_t));
		int16_t* reserved = (int16_t*)GetAbsPos();
		bufPos += sizeof(int16_t);
		return reserved;
	}

	sCompiler()
	{
		gsc = (COD9_GSC*)buf;
		memset(gsc, 0, sizeof(COD9_GSC));
		bufPos = buf + sizeof(COD9_GSC);
	}
};

extern sCompiler* compiler;

enum EStatementType
{
	TYPE_STMT_INC,
	TYPE_STMT_DEC,

	TYPE_STMT_REGULAR_ASSIGN,
	TYPE_STMT_PLUS_ASSIGN,
	TYPE_STMT_MINUS_ASSIGN,
	TYPE_STMT_MULTIPLY_ASSIGN,
	TYPE_STMT_DIVIDE_ASSIGN,
	TYPE_STMT_MOD_ASSIGN,
	TYPE_STMT_SHIFT_LEFT_ASSIGN,
	TYPE_STMT_SHIFT_RIGHT_ASSIGN,
	TYPE_STMT_BIT_AND_ASSIGN,
	TYPE_STMT_BIT_EX_OR_ASSIGN,
	TYPE_STMT_BIT_OR_ASSIGN,

	TYPE_STMT_CASE,
	TYPE_STMT_DEFAULT,

	TYPE_STMT_CONTINUE,
	TYPE_STMT_BREAK,
	TYPE_STMT_RETURN,

	TYPE_STMT_WAIT,
	TYPE_STMT_WAITTILLFRAMEEND,

	TYPE_STMT_EXPRESSION_STATEMENT,

	TYPE_STMT_COMPOUND,

	TYPE_STMT_IF,
	TYPE_STMT_IF_ELSE,
	TYPE_STMT_SWITCH,

	TYPE_STMT_FOR,
	TYPE_STMT_WHILE,
	TYPE_STMT_FOREACH
};

/*struct sLabeledStatement
{
	union
	{
		int caseInt;		// TYPE_CASE_INT_STATEMENT
		char* caseString;	// TYPE_CASE_STRING_STATEMENT
	};
};

struct sJumpStatement
{
	sNode* returnExpr; // TYPE_RETURN_EXPR_STATEMENT
};

struct sWaitStatement
{
	sNode* waitExpr; // TYPE_WAIT_EXPR_STATEMENT
};

struct sExpressionStatement
{
	sNode* expression;
};

struct sCompoundStatement
{
	std::vector<sNode*>* statementList;
};

struct sIfStatement
{
	sNode* ifExpression;
	sNode* ifStatement;
};

struct sIfElseStatement
{
	sNode* ifExpression;
	sNode* ifStatement;
	sNode* elseStatement;
};

struct sSwitchStatement
{
	sNode* switchExpression;
	sNode* switchCompoundStatement;
};

struct sForStatement
{
	sNode* forInitExpression;
	sNode* forCondExpression;
	sNode* forLoopExpression;
};

struct sWhileStatement
{
	sNode* whileExpression;
	sNode* whileStatement;
};

struct sForeachStatement
{
	sNode* foreachElement;
	sNode* foreachExpression;
	sNode* foreachStatement;
};*/

struct sStatement
{
	EStatementType type;
	std::vector<sNode*>* nodeList;
};

/* nodes */

enum ENodeType
{
	// literals
	TYPE_IDENTIFIER,
	TYPE_PATH,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_STRING,
	TYPE_LOC_STRING,
	TYPE_HASH_STRING, // this one is intValue, not stringValue
	TYPE_COMPILED_STRING, // ALL string nodes are converted to this type in CompileStrings()
	TYPE_INCLUDE,
	TYPE_USINGANIMTREE,

	// structs
	TYPE_FUNC_DEFINITION,
	TYPE_FUNC_CALL_EXPRESSION,
	TYPE_ARRAY_SUBSCRIPTING_EXPRESSION,
	TYPE_ELEMENT_SELECTION_EXPRESSION,
	TYPE_FUNC_REF_EXPRESSION,
	TYPE_EXPRESSION,
	TYPE_STATEMENT
};

// size isn't a keyword because it can be used as a variable
enum EKeywordType
{
	TYPE_KWRD_ANIM,
	TYPE_KWRD_GAME,
	TYPE_KWRD_LEVEL,
	TYPE_KWRD_SELF
};

struct sCompiledString
{
	bool isKeyword;				// true if the string is a keyword ("anim", "game", "level" or "self")
	EKeywordType keywordType;	// type of the keyword if this string is a keyword

	ENodeType type;				// type of the string if this string isn't a keyword
	char* stringValue;			// pointer to the string itself
	WORD offset;				// offset in the compiled gsc file

	char* GetString()
	{
		if (isKeyword)
			CompileError("sCompiledString::GetString: trying to get the stringValue of a keyword");
		
		return stringValue;
	}

	WORD GetOffset()
	{
		if (isKeyword)
			CompileError("sCompiledString::GetString: trying to get the offset of a keyword");

		return offset;
	}
	// will need to add to compiler a function called AddStringRef
};

struct sFuncDefinition
{
	sNode* funcName;
	std::vector<sNode*>* parameterList;
	sNode* compoundStatement;
};

struct sIncDecExpression
{
	sNode* expression;
	int isDec;
};

struct sFuncCallExpression
{
	sNode* funcName;
	sNode* gscOfFunc;

	std::vector<sNode*>* argumentList;

	int isPtr;
	sNode* ptrExpression;

	int isMethod;
	sNode* methodObject;

	int isThread;
};

// for example, "level.myVar[self getindex()]", "level.myVar" is the arrayName and "self getindex()" is the index
struct sArraySubscriptingExpression
{
	sNode* arrayName;
	sNode* index;
};

// for example, "self getshit().element", "self getshit()" is the object and "element" is the selectedElement
struct sElementSelectionExpression
{
	int isSize;
	sNode* object;
	sNode* selectedElement;
};

struct sFuncRefExpression
{
	sNode* gscOfFunc;
	sNode* funcName;
};

enum EExpressionType
{
	TYPE_EXPR_IDENTIFIER,
	TYPE_EXPR_INT,
	TYPE_EXPR_FLOAT,
	TYPE_EXPR_STRING,
	TYPE_EXPR_LOC_STRING,
	TYPE_EXPR_HASH_STRING,
	TYPE_EXPR_VECTOR,
	TYPE_EXPR_EMPTY_ARRAY,
	TYPE_EXPR_UNDEFINED,
	TYPE_EXPR_FUNC_CALL_NOTHRD,
	TYPE_EXPR_ARRAY_SUBSCRIPTING,
	TYPE_EXPR_ELEMENT_SELECTION,
	TYPE_EXPR_FUNC_REF,
	TYPE_EXPR_TERNARY_OP,
	TYPE_EXPR_LOGICAL_OR_OP,
	TYPE_EXPR_LOGICAL_AND_OP,
	TYPE_EXPR_BIT_OR_OP,
	TYPE_EXPR_BIT_EX_OR_OP,
	TYPE_EXPR_BIT_AND_OP,
	TYPE_EXPR_EQUALITY_OP,
	TYPE_EXPR_INEQUALITY_OP,
	TYPE_EXPR_LESS_OP,
	TYPE_EXPR_GREATER_OP,
	TYPE_EXPR_LESS_EQUAL_OP,
	TYPE_EXPR_GREATER_EQUAL_OP,
	TYPE_EXPR_SHIFT_LEFT_OP,
	TYPE_EXPR_SHIFT_RIGHT_OP,
	TYPE_EXPR_PLUS_OP,
	TYPE_EXPR_MINUS_OP,
	TYPE_EXPR_MULTIPLY_OP,
	TYPE_EXPR_DIVIDE_OP,
	TYPE_EXPR_MOD_OP,
	TYPE_EXPR_BOOL_NOT_OP,
	TYPE_EXPR_BOOL_COMPLEMENT_OP,
	TYPE_EXPR_UANIMREF_OP
};

struct sExpression
{
	EExpressionType type;
	std::vector<sNode*>* nodeList;
};

// add string info for compiler?
// like sCompiledString* stringValue
struct sNode
{
	ENodeType nodeType;
	union
	{
		int intValue;
		float floatValue;
		char* stringValue; // used for TYPE_IDENTIFIER, TYPE_PATH, TYPE_LOC_STRING_LITERAL and TYPE_HASH_STRING_LITERAL too
		sCompiledString* compiledString;
		sFuncDefinition* funcDefinition;
		sFuncCallExpression* funcCallExpression;
		sArraySubscriptingExpression* arraySubscriptingExpression;
		sElementSelectionExpression* elementSelectionExpression;
		sFuncRefExpression* funcRefExpression;
		sExpression* expression;
		sStatement* statement;
	};
};

/* node allocation */
sNode* AllocInclude(char* filedir);
sNode* AllocUsingAnimTree(char* animtree);
sNode* AllocFuncDefinition(sNode* funcName, std::vector<sNode*>* parameterList, sNode* compoundStatement);
sNode* AllocFuncCallExpression(sNode* funcName, sNode* gscOfFunc, std::vector<sNode*>* argumentList, int isPtr, sNode* ptrExpression, int isMethod, sNode* methodObject, int isThread);
sNode* AllocArraySubscriptingExpression(sNode* arrayName, sNode* index);
sNode* AllocElementSelectionExpression(int isSize, sNode* selection, sNode* selectedElement);
sNode* AllocFuncRefExpression(sNode* gscOfFunc, sNode* funcName);
sNode* AllocExpression(EExpressionType type, ...);
sNode* AllocStatement(EStatementType type, ...);

sNode* IdentifierNode(char* identifierVal);
sNode* PathNode(char* pathVal);
sNode* IntNode(int intVal);
sNode* FloatNode(float floatVal);
sNode* StringNode(char* stringVal);
sNode* LocStringNode(char* locStringVal);
sNode* HashStringNode(char* hashStringVal);

/* node freeing */
void FreeNode(sNode* node);