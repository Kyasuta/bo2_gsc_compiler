#pragma once

#include <cassert>
#include <cstdarg>

// need to add expressions here

/*struct sStatement;

enum EStatementType
{
	TYPE_LABELED_STATEMENT,
	TYPE_JUMP_STATEMENT,
	TYPE_WAIT_STATEMENT,
	TYPE_EXPRESSION_STATEMENT,
	TYPE_COMPOUND_STATEMENT,
	TYPE_SELECTION_STATEMENT,
	TYPE_ITERATION_STATEMENT
};

enum ELabelType
{
	TYPE_CASE,
	TYPE_DEFAULT
};

struct sLabeledStatement
{
	ELabelType type;
	char* labelName; // only if type is TYPE_CASE
};

enum EJumpType
{
	TYPE_CONTINUE,
	TYPE_BREAK,
	TYPE_RETURN,
	TYPE_RETURN_EXPRESSION
};

struct sJumpStatement
{
	EJumpType type;
	//gsc_expression* returnExpression; // only if type is TYPE_RETURN_EXPRESSION
};

enum EWaitType
{
	TYPE_WAIT,
	TYPE_WAITTILLFRAMEEND
};

struct sWaitStatement
{
	EWaitType type;
	int amount; // only if type is TYPE_WAIT
};

enum EExpressionStatementType
{
	TYPE_NOTHING,
	TYPE_INC_OR_DEC_EXPRESSION,
	TYPE_FUNCTION_CALL_NO_THRD_EXPRESSION,
	TYPE_FUNCTION_CALL_THRD_EXPRESSION,
	TYPE_ASSIGNMENT_EXPRESSION
};

struct sExpressionStatement
{
	EExpressionStatementType type;
	union
	{
		//gsc_inc_or_dec_expression* inc_or_dec_expression;
		//gsc_function_call_no_thrd_expression* function_call_no_thrd_expression;
		//gsc_function_call_thrd_expression* gsc_function_call_no_thrd_expression;
		//gsc_assignment_expression* assignment_expression;
	};
};

struct sCompoundStatement
{
	int numOfStatements;
	sStatement** statements;
};

enum ESelectionType
{
	TYPE_IF,
	TYPE_IF_ELSE,
	TYPE_SWITCH
};

struct sSelectionStatement
{
	ESelectionType type;
	//gsc_expression* expression; // need to implement expressions first
	int numOfStatements;
	sStatement* statements;
};

enum EIterationType
{
	TYPE_FOR,
	TYPE_WHILE,
	//TYPE_FOREACH // not implemented yet
};

enum EForModifyValueType
{
	TYPE_FORMODIFYVAL_INC_OR_DEC_EXPRESSION,
	TYPE_FORMODIFYVAL_ASSIGNMENT_EXPRESSION
};

struct sForModifyValue
{
	EForModifyValueType type;
	union
	{
		//gsc_inc_or_dec_expression* inc_or_dec_expression;
		//gsc_assignment_expression* assignment_expression; // need to implement expressions first
	};
};

struct sForLoop
{
	//gsc_assignment_expression* initValue;
	//gsc_expression* condition;
	sForModifyValue* modifyValue;

	int numOfStatements;
	sStatement** statements;
};

struct sWhileLoop
{
	//gsc_expression* condition;

	int numOfStatements;
	sStatement** statements;
};

struct sIterationStatement
{
	EIterationType type;
	union
	{
		sForLoop* forLoop;
		sWhileLoop* whileLoop;
	};
};

struct sStatement
{
	EStatementType type;
	union
	{
		sLabeledStatement* labeledStatement;
		sJumpStatement* jumpStatement;
		sWaitStatement* waitStatement;
		sExpressionStatement* expressionStatement;
		sCompoundStatement* compoundStatement;
		sSelectionStatement* selectionStatement;
		sIterationStatement* iterationStatement;
	};
};*/

/* nodes */

struct sNode;

enum ENodeType
{
	// literals
	TYPE_IDENTIFIER,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_STRING,
	TYPE_LOC_STRING,
	TYPE_HASH_STRING,
	TYPE_INCLUDE,
	TYPE_USINGANIMTREE,

	// structs
	TYPE_FUNC_DEFINITION,
	TYPE_INC_DEC_EXPRESSION,
	TYPE_FUNC_CALL,
	TYPE_ARRAY_SUBSCRIPTING_EXPRESSION,
	TYPE_ELEMENT_SELECTION_EXPRESSION,
	TYPE_FUNC_REF_EXPRESSION,
	TYPE_EXPRESSION
};

struct sFuncDefinition
{
	char* funcName;
	std::vector<char*>* parameterList;
	//sCompoundStatement* compoundStatement;
};

struct sIncDecExpression
{
	sNode* expression;
	int isDec;
};

struct sFuncCall
{
	char* funcName;
	char* gscOfFunc;

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
	char* selectedElement;
};

struct sFuncRefExpression
{
	char* gscOfFunc;
	char* funcName;
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
	union
	{
		int intValue;
		float floatValue;
		char* stringValue;
		std::vector<sNode*>* nodeList;
	};
};

struct sNode
{
	ENodeType nodeType;
	union
	{
		// literals
		int intValue;
		float floatValue;
		char* stringValue; // used for TYPE_LOC_STRING_LITERAL and TYPE_HASH_STRING_LITERAL too

		// structures
		sFuncDefinition* funcDefinition;
		sIncDecExpression* incDecExpression;
		sFuncCall* funcCall;
		sArraySubscriptingExpression* arraySubscriptingExpression;
		sElementSelectionExpression* elementSelectionExpression;
		sFuncRefExpression* funcRefExpression;
		sExpression* expression;
	};
};

/* node allocation */
sNode* AllocInclude(char* filedir);
sNode* AllocUsingAnimTree(char* animtree);
sNode* AllocFuncDefinition(char* funcName, std::vector<char*>* parameterList/*, sCompoundStatement* compoundStatement*/);
sNode* AllocIncDecExpression(sNode* expression, int isDec);
sNode* AllocFuncCall(char* funcName, char* gscOfFunc, std::vector<sNode*>* argumentList, int isPtr, sNode* ptrExpression, int isMethod, sNode* methodObject, int isThread);
sNode* AllocArraySubscriptingExpression(sNode* arrayName, sNode* index);
sNode* AllocElementSelectionExpression(sNode* selection, char* selectedElement);
sNode* AllocFuncRefExpression(char* gscOfFunc, char* funcName);
sNode* AllocExpression(EExpressionType type, ...);

sNode* IdentifierToNode(char* identifier);

/* node freeing */
void FreeNode(sNode* node);