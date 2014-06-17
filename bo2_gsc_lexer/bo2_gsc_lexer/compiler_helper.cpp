#include "stdafx.h"

/* includes & animtrees */

char** includeList = 0;
char** usingAnimTreeList = 0;
int curIncludeCount = 0;
int curUsingAnimTreeCount = 0;

void AddInclude(char* filedir)
{
	if (!includeList)
	{
		includeList = (char**)malloc(sizeof(char*));
		includeList[0] = filedir;
		curIncludeCount = 1;
	}
	else
	{
		includeList = (char**)realloc(includeList, sizeof(char*) * (curIncludeCount + 1));
		includeList[curIncludeCount] = filedir;
		curIncludeCount++;
	}
}

void AddUsingAnimTree(char* animtree)
{
	if (!usingAnimTreeList)
	{
		usingAnimTreeList = (char**)malloc(sizeof(char*));
		usingAnimTreeList[0] = animtree;
		curUsingAnimTreeCount = 1;
	}
	else
	{
		usingAnimTreeList = (char**)realloc(includeList, sizeof(char*) * (curUsingAnimTreeCount + 1));
		usingAnimTreeList[curUsingAnimTreeCount] = animtree;
		curUsingAnimTreeCount++;
	}
}

/* function definitions */
sFuncDefinition** funcDefList = 0;
int curFuncDefCount = 0;

void AddFuncDefinition(char* funcName)
{
	curFuncDefCount++;
}

/* function argument lists */
sExpression** AllocExpressionList(int numOfExpressions)
{
	return (sExpression**)malloc(sizeof(sExpression*) * numOfExpressions);
}

sExpression* CreateExpression(EExpressionType type, ...)
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
		result->expressionList = AllocExpressionList(3);
		result->expressionList[0] = va_arg(vl, sExpression*);
		result->expressionList[1] = va_arg(vl, sExpression*);
		result->expressionList[2] = va_arg(vl, sExpression*);
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
		result->expressionList = AllocExpressionList(2);
		result->expressionList[0] = va_arg(vl, sExpression*);
		result->expressionList[1] = va_arg(vl, sExpression*);
		break;
	case TYPE_EXPR_BOOL_NOT_OP:
	case TYPE_EXPR_BOOL_COMPLEMENT_OP:
		result->expressionList = AllocExpressionList(1);
		result->expressionList[0] = va_arg(vl, sExpression*);
		break;
	}

	va_end(vl);

	return result;
}