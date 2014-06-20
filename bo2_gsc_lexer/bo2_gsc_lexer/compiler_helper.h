#pragma once

#include <cassert>
#include <cstdarg>
#include "bo2_gsc_file.h"

struct sNode;
struct sStatement;

/* compiler struct */

class sCompiler
{
public:
	COD9_GSC* gsc;

	char* relativePath;
	char* outputDir;
	FILE* outputFile;

	BYTE buf[0x100000]; // 1mb
	BYTE* bufPos;

	std::vector<sNode*>* sourceCode;	// main node
	std::vector<sNode*> nodes;			// every node in the source code !!! not sure if needed !!!
	std::vector<sNode*> strings;		// every identifier and string in the source code

	DWORD GetRelPos()
	{
		return bufPos - buf;
	}

	void AddBytes(void* bytes, DWORD amount)
	{
		memcpy(bufPos, bytes, amount);
		bufPos += amount;
	}

	void AlignPos(int mod)
	{
		bufPos = buf + ((bufPos - buf + mod - 1) & ~(mod - 1));
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
	TYPE_CASE_STATEMENT,
	TYPE_DEFAULT_STATEMENT,

	TYPE_CONTINUE_STATEMENT,
	TYPE_BREAK_STATEMENT,
	TYPE_RETURN_STATEMENT,

	TYPE_WAIT_EXPR_STATEMENT,
	TYPE_WAITTILLFRAMEEND_STATEMENT,

	TYPE_EXPRESSION_STATEMENT,

	TYPE_COMPOUND_STATEMENT,

	TYPE_IF_STATEMENT,
	TYPE_IF_ELSE_STATEMENT,
	TYPE_SWITCH_STATEMENT,

	TYPE_FOR_STATEMENT,
	TYPE_WHILE_STATEMENT,
	TYPE_FOREACH_STATEMENT
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
	/*union
	{
		sLabeledStatement* labeledStatement;
		sJumpStatement* jumpStatement;
		sWaitStatement* waitStatement;
		sExpressionStatement* expressionStatement;
		sCompoundStatement* compoundStatement;
		sIfStatement* ifStatement;
		sIfElseStatement* ifElseStatement;
		sSwitchStatement* switchStatement;
		sForStatement* forStatement;
		sWhileStatement* whileStatement;
		sForeachStatement* foreachStatement;
	};*/
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
	TYPE_INC_DEC_EXPRESSION,
	TYPE_FUNC_CALL,
	TYPE_ARRAY_SUBSCRIPTING_EXPRESSION,
	TYPE_ELEMENT_SELECTION_EXPRESSION,
	TYPE_FUNC_REF_EXPRESSION,
	TYPE_EXPRESSION,
	TYPE_ASSIGNMENT_EXPRESSION,
	TYPE_STATEMENT
};

struct sCompiledString
{
	ENodeType type;			// type of the string
	char* stringValue;		// pointer to the string itself !!! may be not needed !!!
	DWORD offset;			// offset in the compiled gsc file
	// will need to add the reference count here
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

struct sFuncCall
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

// for example, "self getshit().element", "self getshit()" is the selection and "element" is the selectedElement
struct sElementSelectionExpression
{
	sNode* selection;
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
	TYPE_EXPR_UMINUS_INT_OP,
	TYPE_EXPR_UMINUS_FLOAT_OP,
	TYPE_EXPR_UANIMREF_OP
};

struct sExpression
{
	EExpressionType type;
	std::vector<sNode*>* nodeList;
};

enum EAssignmentType
{
	TYPE_REGULAR_ASSIGN,
	TYPE_PLUS_ASSIGN,
	TYPE_MINUS_ASSIGN,
	TYPE_MULTIPLY_ASSIGN,
	TYPE_DIVIDE_ASSIGN,
	TYPE_MOD_ASSIGN,
	TYPE_SHIFT_LEFT_ASSIGN,
	TYPE_SHIFT_RIGHT_ASSIGN,
	TYPE_BIT_AND_ASSIGN,
	TYPE_BIT_EX_OR_ASSIGN,
	TYPE_BIT_OR_ASSIGN
};

struct sAssignmentExpression
{
	EAssignmentType type;
	sNode* lvalue;
	sNode* rvalue;
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
		sIncDecExpression* incDecExpression;
		sFuncCall* funcCall;
		sArraySubscriptingExpression* arraySubscriptingExpression;
		sElementSelectionExpression* elementSelectionExpression;
		sFuncRefExpression* funcRefExpression;
		sExpression* expression;
		sAssignmentExpression* assignmentExpression;
		sStatement* statement;
	};
};

/* node allocation */
sNode* AllocInclude(char* filedir);
sNode* AllocUsingAnimTree(char* animtree);
sNode* AllocFuncDefinition(sNode* funcName, std::vector<sNode*>* parameterList, sNode* compoundStatement);
sNode* AllocIncDecExpression(sNode* expression, int isDec);
sNode* AllocFuncCall(sNode* funcName, sNode* gscOfFunc, std::vector<sNode*>* argumentList, int isPtr, sNode* ptrExpression, int isMethod, sNode* methodObject, int isThread);
sNode* AllocArraySubscriptingExpression(sNode* arrayName, sNode* index);
sNode* AllocElementSelectionExpression(sNode* selection, sNode* selectedElement);
sNode* AllocFuncRefExpression(sNode* gscOfFunc, sNode* funcName);
sNode* AllocExpression(EExpressionType type, ...);
sNode* AllocAssignmentExpression(EAssignmentType type, sNode* lvalue, sNode* rvalue);
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