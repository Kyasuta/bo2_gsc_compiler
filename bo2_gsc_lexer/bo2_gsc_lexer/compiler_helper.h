#pragma once

#include <cassert>
#include <cstdarg>

// need to add expressions here

struct sStatement;

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

struct sFuncDefinition
{
	char* functionName;

	int numOfParams;
	char** paramNames;

	int numOfStatements;
	sStatement** statements;
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
};

/* arrays */
/*template <class T>
class DynamicArray
{
private:
	// class variable members
	T* elementArray;
	unsigned int elementArraySize;
	unsigned int elementCount;

public:
	// element management
	void AddElement(T element)
	{
		if (this->elementArray)
		{
			if (this->elementArraySize < sizeof(T) * (this->elementCount + 1))
			{
				this->elementArray = (T*)realloc(this->elementArray, sizeof(T) * (this->elementCount + 1));
				assert(this->elementArray != NULL);

				this->elementArraySize = sizeof(T) * (this->elementCount + 1);
			}
			
			this->elementArray[this->elementCount] = element;
			this->elementCount++;
		}
		else
		{
			this->elementArray = (T*)malloc(sizeof(T));
			assert(this->elementArray != NULL);

			this->elementArraySize = sizeof(T);

			this->elementArray[0] = element;
			this->elementCount = 1;
		}
	}

	void RemoveElement()
	{
		if (this->elementArray && this->elementCount > 0)
			this->elementCount--;
	}

	T operator[](int index)
	{
		assert(index < this->elementCount);

		return this->elementArray[index];
	}

	// constructor & destructor
	DynamicArray()
	{
		this->elementArray		= 0;
		this->elementArraySize	= 0;
		this->elementCount		= 0;
	}
	DynamicArray(int elementCountInit, ...)
	{
		va_list vl;
		va_start(vl, elementCountInit);

		this->elementArray	= (T*)malloc(sizeof(T) * elementCountInit);
		assert(this->elementArray != NULL);

		this->elementArraySize = sizeof(T) * elementCountInit;

		for (int i = 0; i < elementCountInit; i++)
			this->elementArray[i] = va_arg(vl, T);

		this->elementCount	= elementCountInit;

		va_end(vl);
	}

	~DynamicArray()
	{
		if (this->elementArray)
			free(this->elementArray);
	}
};*/

/* includes & animtrees */
extern char** includeList;
extern char** usingAnimTreeList;
extern int curIncludeCount;
extern int curUsingAnimTreeCount;

void AddInclude(char* filedir);
void AddUsingAnimTree(char* animtree);

/* function definitions */
/*typedef struct _sFuncDefinition
{

} sFuncDefinition;*/

typedef enum _EExpressionType
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
} EExpressionType;

typedef struct _sExpression
{
	EExpressionType type;

	union
	{
		int intValue;
		float floatValue;
		char* stringValue;
		struct _sExpression** expressionList;
	};
} sExpression;

typedef struct _sArgumentList
{
	int numOfArguments;
	sExpression** expressionList;
} sArgumentList;

sExpression* CreateExpression(EExpressionType type, ...);