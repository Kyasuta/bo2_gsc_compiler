#include "stdafx.h"

/* compiler struct */

sCompiler* compiler;

/* nodes */
sNode* AllocNode(ENodeType nodeType)
{
	sNode* allocatedNode = (sNode*)malloc(sizeof(sNode));
	assert(allocatedNode != NULL);

	switch (nodeType)
	{
	case TYPE_FUNC_DEFINITION:
		allocatedNode->funcDefinition = (sFuncDefinition*)malloc(sizeof(sFuncDefinition));
		assert(allocatedNode->funcDefinition != NULL);
		break;
	case TYPE_FUNC_CALL_EXPRESSION:
		allocatedNode->funcCallExpression = (sFuncCallExpression*)malloc(sizeof(sFuncCallExpression));
		assert(allocatedNode->funcCallExpression != NULL);
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
	case TYPE_STATEMENT:
		allocatedNode->statement = (sStatement*)malloc(sizeof(sStatement));
		assert(allocatedNode->statement != NULL);
		break;
	}

	allocatedNode->nodeType = nodeType;

	compiler->nodes.push_back(allocatedNode);

	return allocatedNode;
}

sNode* IdentifierNode(char* identifierVal)
{
	sNode* allocatedNode = AllocNode(TYPE_IDENTIFIER);
	allocatedNode->stringValue = identifierVal;

	compiler->strings.push_back(allocatedNode);

	return allocatedNode;
}

sNode* PathNode(char* pathVal)
{
	sNode* allocatedNode = AllocNode(TYPE_PATH);
	allocatedNode->stringValue = pathVal;

	compiler->strings.push_back(allocatedNode);

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

	compiler->strings.push_back(allocatedNode);

	return allocatedNode;
}

sNode* LocStringNode(char* locStringVal)
{
	sNode* allocatedNode = AllocNode(TYPE_LOC_STRING);
	allocatedNode->stringValue = locStringVal;

	compiler->strings.push_back(allocatedNode);

	return allocatedNode;
}

// DJB2 algorithm
DWORD generateHashValue(char* str)
{
	DWORD result = 5381;
	int c;
	
	while (c = *str++)
		result = ((result << 5) + result) + c; /* hash * 33 + c */
	
	return result;
}

sNode* HashStringNode(char* hashStringVal)
{
	sNode* allocatedNode = AllocNode(TYPE_HASH_STRING);
	allocatedNode->intValue = generateHashValue(hashStringVal);

	return allocatedNode;
}

/* node allocation */

sNode* AllocInclude(char* filedir)
{
	sNode* allocatedNode = AllocNode(TYPE_INCLUDE);
	allocatedNode->stringValue = filedir;

	compiler->strings.push_back(allocatedNode);

	return allocatedNode;
}

sNode* AllocUsingAnimTree(char* animtree)
{
	sNode* allocatedNode = AllocNode(TYPE_USINGANIMTREE);
	allocatedNode->stringValue = animtree;

	compiler->strings.push_back(allocatedNode);

	return allocatedNode;
}

sNode* AllocFuncDefinition(sNode* funcName, std::vector<sNode*>* parameterList, sNode* compoundStatement)
{
	sNode* result = AllocNode(TYPE_FUNC_DEFINITION);

	result->funcDefinition->funcName = funcName;
	result->funcDefinition->parameterList = parameterList;
	result->funcDefinition->compoundStatement = compoundStatement;

	return result;
}

sNode* AllocFuncCallExpression(sNode* funcName, sNode* gscOfFunc, std::vector<sNode*>* argumentList, int isPtr, sNode* ptrExpression, int isMethod, sNode* methodObject, int isThread)
{
	sNode* result = AllocNode(TYPE_FUNC_CALL_EXPRESSION);

	result->funcCallExpression->funcName = funcName;
	result->funcCallExpression->gscOfFunc = gscOfFunc;
	result->funcCallExpression->argumentList = argumentList;
	result->funcCallExpression->isPtr = isPtr;
	result->funcCallExpression->ptrExpression = ptrExpression;
	result->funcCallExpression->isMethod = isMethod;
	result->funcCallExpression->methodObject = methodObject;
	result->funcCallExpression->isThread = isThread;

	return result;
}

sNode* AllocArraySubscriptingExpression(sNode* arrayName, sNode* index)
{
	sNode* result = AllocNode(TYPE_ARRAY_SUBSCRIPTING_EXPRESSION);

	result->arraySubscriptingExpression->arrayName = arrayName;
	result->arraySubscriptingExpression->index = index;

	return result;
}

sNode* AllocElementSelectionExpression(int isSize, sNode* selection, sNode* selectedElement)
{
	sNode* result = AllocNode(TYPE_ELEMENT_SELECTION_EXPRESSION);

	result->elementSelectionExpression->isSize = isSize;
	result->elementSelectionExpression->object = selection;
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
	case TYPE_EXPR_FLOAT:
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
	case TYPE_EXPR_TERNARY_OP:
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		result->expression->nodeList->push_back(va_arg(vl, sNode*));
		break;
	}

	result->expression->type = type;

	va_end(vl);

	return result;
}

sNode* AllocStatement(EStatementType type, ...)
{
	va_list vl;
	va_start(vl, type);

	sNode* result = AllocNode(TYPE_STATEMENT);
	
	if (type == TYPE_STMT_COMPOUND)
		result->statement->nodeList = va_arg(vl, std::vector<sNode*>*);
	else
	{
		result->statement->nodeList = new std::vector<sNode*>();

		switch (type)
		{
		case TYPE_STMT_DEFAULT:
		case TYPE_STMT_CONTINUE:
		case TYPE_STMT_BREAK:
		case TYPE_STMT_WAITTILLFRAMEEND:
			break;
		case TYPE_STMT_INC:
		case TYPE_STMT_DEC:
		case TYPE_STMT_CASE:
		case TYPE_STMT_RETURN:
		case TYPE_STMT_WAIT:
		case TYPE_STMT_EXPRESSION_STATEMENT:
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
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
		case TYPE_STMT_IF:
		case TYPE_STMT_SWITCH:
		case TYPE_STMT_WHILE:
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			break;
		case TYPE_STMT_IF_ELSE:
		case TYPE_STMT_FOREACH:
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			result->statement->nodeList->push_back(va_arg(vl, sNode*));
			break;
		case TYPE_STMT_FOR:
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