%{
#include <stdio.h>
#include <vector>
#include "compiler_helper.h"

extern int lineCount;
int yylex(void);

void yyerror(char const *s);

void OnParsingComplete(std::vector<sNode*>* sourceCode);
%}

%union {
	int intValue;
	float floatValue;
	char* stringValue;
	sNode* nodeValue;
	std::vector<char*>* stringArrayValue;
	std::vector<sNode*>* nodeArrayValue;
}

/* keyword tokens */
%token INCLUDE USING_ANIMTREE THREAD SWITCH CASE DEFAULT
%token IF ELSE FOR WHILE FOREACH IN BREAK RETURN CONTINUE
%token WAIT WAITTILLFRAMEEND UNDEFINED

/* other tokens */
%token SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN BIT_AND_ASSIGN BIT_EX_OR_ASSIGN BIT_OR_ASSIGN
%token SHIFT_RIGHT_OP SHIFT_LEFT_OP INC_OP DEC_OP LOGICAL_AND_OP LOGICAL_OR_OP LESS_EQUAL_OP GREATER_EQUAL_OP EQUALITY_OP INEQUALITY_OP
%token DEREFERENCE_FUNC_START REFERENCE_FUNC DEVBLOCK_START DEVBLOCK_END EMPTY_ARRAY

/* token & nonterminal types */
%token <intValue> INT_LITERAL
%token <floatValue> FLOAT_LITERAL
%token <stringValue> IDENTIFIER PATH STRING_LITERAL LOC_STRING_LITERAL HASH_STRING_LITERAL

%type <nodeValue> include using_animtree func_definition inc_dec_expression func_call_noptr func_call_ptr func_call_nothrd_expression func_call_thrd_expression
%type <nodeValue> func_valid_object array_valid_name array_subscripting_expression element_selection_expression element_valid_selection func_ref_expression
%type <nodeValue> expression parenthesized_expression assignment_expression operation_valid_lvalue

%type <intValue> inc_dec
%type <stringArrayValue> parameter_list_opt
%type <nodeArrayValue> source_code argument_list_opt

/* precedences (shift/reduce conflict resolving) */
%nonassoc IFX
%nonassoc ELSE

%left LOGICAL_OR_OP
%left LOGICAL_AND_OP
%left '|'
%left '^'
%left '&'
%left EQUALITY_OP INEQUALITY_OP
%left '<' '>' LESS_EQUAL_OP GREATER_EQUAL_OP
%left SHIFT_LEFT_OP SHIFT_RIGHT_OP
%left '+' '-'
%left '*' '/' '%'
%right '!' '~' UNARY_MINUS UNARY_ANIMREF

/* starting rule */
%start translation_unit

%%

translation_unit
	: /* empty */
	| source_code												{ OnParsingComplete($1); }
	;

source_code
	: include													{ $$ = new std::vector<sNode*>(1, $1); }
	| using_animtree											{ $$ = new std::vector<sNode*>(1, $1); }
	| func_definition											{ $$ = new std::vector<sNode*>(1, $1); }
	| source_code include										{ $$ = $1; $$->push_back($2); }
	| source_code using_animtree								{ $$ = $1; $$->push_back($2); }
	| source_code func_definition								{ $$ = $1; $$->push_back($2); }
	;

include
	: INCLUDE PATH ';'											{ $$ = AllocInclude($2); }
	| INCLUDE IDENTIFIER ';'									{ $$ = AllocInclude($2); }
	;

using_animtree
	: USING_ANIMTREE '(' STRING_LITERAL ')' ';'					{ $$ = AllocUsingAnimTree($3); }
	;

func_definition
	: IDENTIFIER '(' parameter_list_opt ')' compound_statement	{ $$ = AllocFuncDefinition($1, $3/*, $5*/); }
	;

parameter_list_opt
	: /* empty */												{ $$ = 0; }
	| IDENTIFIER												{ $$ = new std::vector<char*>(1, $1); }
	| parameter_list_opt ',' IDENTIFIER							{ $$ = $1; $$->push_back($3); }
	;

/* add func_call_expression inc_dec ? */
inc_dec_expression
	: IDENTIFIER inc_dec										{ $$ = AllocIncDecExpression(IdentifierToNode($1), $2); }
	| array_subscripting_expression inc_dec						{ $$ = AllocIncDecExpression($1, $2); }
	| element_selection_expression inc_dec						{ $$ = AllocIncDecExpression($1, $2); }
	;

inc_dec
	: INC_OP													{ $$ = 0; }
	| DEC_OP													{ $$ = 1; }
	;

/* non-pointer function call */
func_call_noptr
	: IDENTIFIER '(' argument_list_opt ')'									{ $$ = AllocFuncCall($1, 0, $3, 0, 0, 0, 0, 0); }
	| PATH REFERENCE_FUNC IDENTIFIER '(' argument_list_opt ')'				{ $$ = AllocFuncCall($3, $1, $5, 0, 0, 0, 0, 0); }
	| IDENTIFIER REFERENCE_FUNC IDENTIFIER '(' argument_list_opt ')'		{ $$ = AllocFuncCall($3, $1, $5, 0, 0, 0, 0, 0); }
	;

/* pointer function call */
func_call_ptr
	: DEREFERENCE_FUNC_START expression ']' ']' '(' argument_list_opt ')'	{ $$ = AllocFuncCall(0, 0, $6, 1, $2, 0, 0, 0); }
	;

argument_list_opt
	: /* empty */												{ $$ = 0; }
	| expression												{ $$ = new std::vector<sNode*>(1, $1); }
	| argument_list_opt ',' expression							{ $$ = $1; $$->push_back($3); }
	;

/* non-thread function call */
func_call_nothrd_expression
	: func_call_noptr											{ $$ = $1; $$->funcCall->isThread = 0; }
	| func_call_ptr												{ $$ = $1; $$->funcCall->isThread = 0; }
	| func_valid_object func_call_noptr							{ $$ = $2; $$->funcCall->isThread = 0; $$->funcCall->isMethod = 1; $$->funcCall->methodObject = $1; }
	| func_valid_object func_call_ptr							{ $$ = $2; $$->funcCall->isThread = 0; $$->funcCall->isMethod = 1; $$->funcCall->methodObject = $1; }
	;

/* thread function call */
func_call_thrd_expression
	: THREAD func_call_noptr									{ $$ = $2; $$->funcCall->isThread = 1; }
	| THREAD func_call_ptr										{ $$ = $2; $$->funcCall->isThread = 1; }
	| func_valid_object THREAD func_call_noptr					{ $$ = $3; $$->funcCall->isThread = 1; $$->funcCall->isMethod = 1; $$->funcCall->methodObject = $1; }
	| func_valid_object THREAD func_call_ptr					{ $$ = $3; $$->funcCall->isThread = 1; $$->funcCall->isMethod = 1; $$->funcCall->methodObject = $1; }
	;

/* things that are syntactically valid to be a function's method object */
func_valid_object
	: IDENTIFIER												{ $$ = IdentifierToNode($1); }
	| func_call_nothrd_expression								{ $$ = $1; }
	| array_subscripting_expression								{ $$ = $1; }
	| element_selection_expression								{ $$ = $1; }
	;

/* Need to add support for more array subscripting expressions */
array_subscripting_expression
	: array_valid_name '[' expression ']'						{ $$ = AllocArraySubscriptingExpression($1, $3); }
	;

/* expressions that are syntactically valid to be a name of an array */
array_valid_name
	: IDENTIFIER												{ $$ = IdentifierToNode($1); }
	| func_call_nothrd_expression								{ $$ = $1; }
	| array_subscripting_expression								{ $$ = $1; }
	| element_selection_expression								{ $$ = $1; }
	| parenthesized_expression									{ $$ = $1; }
	;

/* identifier might be a keyword, size */
element_selection_expression
	: element_valid_selection '.' IDENTIFIER					{ $$ = AllocElementSelectionExpression($1, $3); }
	;

/* things that are syntactically valid to be selected through "." */
element_valid_selection
	: IDENTIFIER												{ $$ = IdentifierToNode($1); }
	| func_call_nothrd_expression								{ $$ = $1; }
	| array_subscripting_expression								{ $$ = $1; }
	| element_selection_expression								{ $$ = $1; }
	| parenthesized_expression									{ $$ = $1; }
	;

func_ref_expression
	: REFERENCE_FUNC IDENTIFIER									{ $$ = AllocFuncRefExpression(0, $2); }
	| IDENTIFIER REFERENCE_FUNC IDENTIFIER						{ $$ = AllocFuncRefExpression($1, $3); }
	| PATH REFERENCE_FUNC IDENTIFIER							{ $$ = AllocFuncRefExpression($1, $3); }
	;

expression
	: IDENTIFIER												{ $$ = AllocExpression(TYPE_EXPR_IDENTIFIER, $1); }
	| INT_LITERAL												{ $$ = AllocExpression(TYPE_EXPR_INT, $1); }
	| FLOAT_LITERAL												{ $$ = AllocExpression(TYPE_EXPR_FLOAT, $1); }
	| STRING_LITERAL											{ $$ = AllocExpression(TYPE_EXPR_STRING, $1); }
	| LOC_STRING_LITERAL										{ $$ = AllocExpression(TYPE_EXPR_LOC_STRING, $1); }
	| HASH_STRING_LITERAL										{ $$ = AllocExpression(TYPE_EXPR_HASH_STRING, $1); }
	| '(' expression ',' expression ',' expression ')'			{ $$ = AllocExpression(TYPE_EXPR_VECTOR, $2, $4, $6); }
	| EMPTY_ARRAY												{ $$ = AllocExpression(TYPE_EXPR_EMPTY_ARRAY); }
	| UNDEFINED													{ $$ = AllocExpression(TYPE_EXPR_UNDEFINED); }
	| func_call_nothrd_expression								{ $$ = AllocExpression(TYPE_EXPR_FUNC_CALL_NOTHRD, $1); }
	| array_subscripting_expression								{ $$ = AllocExpression(TYPE_EXPR_ARRAY_SUBSCRIPTING, $1); }
	| element_selection_expression								{ $$ = AllocExpression(TYPE_EXPR_ELEMENT_SELECTION, $1); }
	| func_ref_expression										{ $$ = AllocExpression(TYPE_EXPR_FUNC_REF, $1); }
	| expression LOGICAL_OR_OP expression						{ $$ = AllocExpression(TYPE_EXPR_LOGICAL_OR_OP, $1, $3); }
	| expression LOGICAL_AND_OP expression						{ $$ = AllocExpression(TYPE_EXPR_LOGICAL_AND_OP, $1, $3); }
	| expression '|' expression									{ $$ = AllocExpression(TYPE_EXPR_BIT_OR_OP, $1, $3); }
	| expression '^' expression									{ $$ = AllocExpression(TYPE_EXPR_BIT_EX_OR_OP, $1, $3); }
	| expression '&' expression									{ $$ = AllocExpression(TYPE_EXPR_BIT_AND_OP, $1, $3); }
	| expression EQUALITY_OP expression							{ $$ = AllocExpression(TYPE_EXPR_EQUALITY_OP, $1, $3); }
	| expression INEQUALITY_OP expression						{ $$ = AllocExpression(TYPE_EXPR_INEQUALITY_OP, $1, $3); }
	| expression '<' expression									{ $$ = AllocExpression(TYPE_EXPR_LESS_OP, $1, $3); }
	| expression '>' expression									{ $$ = AllocExpression(TYPE_EXPR_GREATER_OP, $1, $3); }
	| expression LESS_EQUAL_OP expression						{ $$ = AllocExpression(TYPE_EXPR_LESS_EQUAL_OP, $1, $3); }
	| expression GREATER_EQUAL_OP expression					{ $$ = AllocExpression(TYPE_EXPR_GREATER_EQUAL_OP, $1, $3); }
	| expression SHIFT_LEFT_OP expression						{ $$ = AllocExpression(TYPE_EXPR_SHIFT_LEFT_OP, $1, $3); }
	| expression SHIFT_RIGHT_OP expression						{ $$ = AllocExpression(TYPE_EXPR_SHIFT_RIGHT_OP, $1, $3); }
	| expression '+' expression									{ $$ = AllocExpression(TYPE_EXPR_PLUS_OP, $1, $3); }
	| expression '-' expression									{ $$ = AllocExpression(TYPE_EXPR_MINUS_OP, $1, $3); }
	| expression '*' expression									{ $$ = AllocExpression(TYPE_EXPR_MULTIPLY_OP, $1, $3); }
	| expression '/' expression									{ $$ = AllocExpression(TYPE_EXPR_DIVIDE_OP, $1, $3); }
	| expression '%' expression									{ $$ = AllocExpression(TYPE_EXPR_MOD_OP, $1, $3); }
	| '!' expression											{ $$ = AllocExpression(TYPE_EXPR_BOOL_NOT_OP, $2); }
	| '~' expression											{ $$ = AllocExpression(TYPE_EXPR_BOOL_COMPLEMENT_OP, $2); }
	| '-' INT_LITERAL %prec UNARY_MINUS							{ $$ = AllocExpression(TYPE_EXPR_UMINUS_INT_OP, $2); }
	| '-' FLOAT_LITERAL %prec UNARY_MINUS						{ $$ = AllocExpression(TYPE_EXPR_UMINUS_FLOAT_OP, $2); }
	| '%' IDENTIFIER %prec UNARY_ANIMREF						{ $$ = AllocExpression(TYPE_EXPR_UANIMREF_OP, $2); }
	| parenthesized_expression									{ $$ = $1; }
	;

parenthesized_expression
	: '(' expression ')'										{ $$ = $2; }
	;

assignment_expression
	: operation_valid_lvalue '=' expression
	| operation_valid_lvalue PLUS_ASSIGN expression
	| operation_valid_lvalue MINUS_ASSIGN expression
	| operation_valid_lvalue MULTIPLY_ASSIGN expression
	| operation_valid_lvalue DIVIDE_ASSIGN expression
	| operation_valid_lvalue MOD_ASSIGN expression
	| operation_valid_lvalue SHIFT_LEFT_ASSIGN expression
	| operation_valid_lvalue SHIFT_RIGHT_ASSIGN expression
	| operation_valid_lvalue BIT_AND_ASSIGN expression
	| operation_valid_lvalue BIT_EX_OR_ASSIGN expression
	| operation_valid_lvalue BIT_OR_ASSIGN expression
	;

operation_valid_lvalue
	: IDENTIFIER												{ $$ = IdentifierToNode($1); }
	| array_subscripting_expression								{ $$ = $1; }
	| element_selection_expression								{ $$ = $1; }
	;

statement
	: labeled_statement
	| jump_statement
	| wait_statement
	| expression_statement
	| compound_statement
	| selection_statement
	| iteration_statement
	;

/* special statement lists that are for switch & loops only (special keywords: case, default, break, continue) */
labeled_statement
	: CASE INT_LITERAL ':'
	| CASE STRING_LITERAL ':'
	| DEFAULT ':'
	;

jump_statement
	: CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

wait_statement
	: WAIT expression ';'
	| WAITTILLFRAMEEND ';'
	;

for_init_value_opt
	: /* empty */
	| assignment_expression
	;

for_condition_opt
	: /* empty */
	| expression
	;

for_modify_value_opt
	: /* empty */
	| inc_dec_expression
	| assignment_expression
	;

/* not putting expression here because it doesn't do anything */
expression_statement
	: ';'
	| inc_dec_expression ';'
	| func_call_nothrd_expression ';'
	| func_call_thrd_expression ';'
	| assignment_expression ';'
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	;

statement_list
	: statement
	| statement_list statement
	;

selection_statement
	: IF '(' expression ')' statement %prec IFX
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' compound_statement
	;

iteration_statement
	: FOR '(' for_init_value_opt ';' for_condition_opt ';' for_modify_value_opt ')' statement
	| WHILE '(' expression ')' statement
	| FOREACH '(' IDENTIFIER IN expression ')' statement
	;

%%

void yyerror(char const *s)
{
	printf("error: %s\nat line %d\n", s, lineCount);
	system("pause");
}