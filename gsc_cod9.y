%{
#include <stdio.h>
#include <vector>
#include "compiler_helper.h"

extern int lineCount;
int yylex(void);

void CompileError(char* errorString, ...);
void yyerror(char const *s);

void OnParsingComplete();
%}

%union {
	int intValue;
	float floatValue;
	char* stringValue;
	sNode* nodeValue;
	std::vector<sNode*>* nodeArrayValue;
}

/* keyword tokens */
%token INCLUDE USING_ANIMTREE THREAD SWITCH CASE DEFAULT
%token IF ELSE FOR WHILE FOREACH IN BREAK RETURN CONTINUE
%token WAIT WAITTILLFRAMEEND UNDEFINED

/* other tokens */
%token SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN BIT_AND_ASSIGN BIT_EX_OR_ASSIGN BIT_OR_ASSIGN
%token SHIFT_RIGHT_OP SHIFT_LEFT_OP INC_OP DEC_OP LOGICAL_AND_OP LOGICAL_OR_OP LESS_EQUAL_OP GREATER_EQUAL_OP EQUALITY_OP INEQUALITY_OP
%token DEREFERENCE_FUNC_START REFERENCE_FUNC EMPTY_ARRAY

/* token & nonterminal types */
%token <intValue> INT_LITERAL
%token <floatValue> FLOAT_LITERAL
%token <stringValue> IDENTIFIER PATH STRING_LITERAL LOC_STRING_LITERAL HASH_STRING_LITERAL

%type <nodeValue> include using_animtree func_definition func_call_noptr func_call_ptr func_call_nothrd_expression func_call_thrd_expression func_valid_object
%type <nodeValue> array_valid_name array_subscripting_expression element_selection_expression element_valid_selection func_ref_expression expression
%type <nodeValue> parenthesized_expression statement inc_dec_statement assignment_statement operation_valid_lvalue labeled_statement jump_statement wait_statement
%type <nodeValue> expression_statement compound_statement selection_statement iteration_statement for_init_statement for_cond_expression for_loop_statement

%type <nodeArrayValue> source_code parameter_list_opt argument_list_opt statement_list

/* precedences (shift/reduce conflict resolving) */
%nonassoc IFX
%nonassoc ELSE

%right '?' ':'
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
	| source_code												{ compiler->sourceCode = $1; OnParsingComplete(); }
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
	: IDENTIFIER '(' parameter_list_opt ')' compound_statement	{ $$ = AllocFuncDefinition(IdentifierNode($1), $3, $5); }
	;

parameter_list_opt
	: /* empty */												{ $$ = 0; }
	| IDENTIFIER												{ $$ = new std::vector<sNode*>(1, IdentifierNode($1)); }
	| parameter_list_opt ',' IDENTIFIER							{ $$ = $1; $$->push_back(IdentifierNode($3)); }
	;

/* non-pointer function call */
func_call_noptr
	: IDENTIFIER '(' argument_list_opt ')'									{ $$ = AllocFuncCallExpression(IdentifierNode($1), 0, $3, 0, 0, 0, 0, 0); }
	| PATH REFERENCE_FUNC IDENTIFIER '(' argument_list_opt ')'				{ $$ = AllocFuncCallExpression(IdentifierNode($3), PathNode($1), $5, 0, 0, 0, 0, 0); }
	| IDENTIFIER REFERENCE_FUNC IDENTIFIER '(' argument_list_opt ')'		{ $$ = AllocFuncCallExpression(IdentifierNode($3), IdentifierNode($1), $5, 0, 0, 0, 0, 0); }
	;

/* pointer function call */
func_call_ptr
	: DEREFERENCE_FUNC_START expression ']' ']' '(' argument_list_opt ')'	{ $$ = AllocFuncCallExpression(0, 0, $6, 1, $2, 0, 0, 0); }
	;

argument_list_opt
	: /* empty */												{ $$ = 0; }
	| expression												{ $$ = new std::vector<sNode*>(1, $1); }
	| argument_list_opt ',' expression							{ $$ = $1; $$->push_back($3); }
	;

/* non-thread function call */
func_call_nothrd_expression
	: func_call_noptr											{ $$ = $1; $$->funcCallExpression->isThread = 0; }
	| func_call_ptr												{ $$ = $1; $$->funcCallExpression->isThread = 0; }
	| func_valid_object func_call_noptr							{ $$ = $2; $$->funcCallExpression->isThread = 0; $$->funcCallExpression->isMethod = 1; $$->funcCallExpression->methodObject = $1; }
	| func_valid_object func_call_ptr							{ $$ = $2; $$->funcCallExpression->isThread = 0; $$->funcCallExpression->isMethod = 1; $$->funcCallExpression->methodObject = $1; }
	;

/* thread function call */
func_call_thrd_expression
	: THREAD func_call_noptr									{ $$ = $2; $$->funcCallExpression->isThread = 1; }
	| THREAD func_call_ptr										{ $$ = $2; $$->funcCallExpression->isThread = 1; }
	| func_valid_object THREAD func_call_noptr					{ $$ = $3; $$->funcCallExpression->isThread = 1; $$->funcCallExpression->isMethod = 1; $$->funcCallExpression->methodObject = $1; }
	| func_valid_object THREAD func_call_ptr					{ $$ = $3; $$->funcCallExpression->isThread = 1; $$->funcCallExpression->isMethod = 1; $$->funcCallExpression->methodObject = $1; }
	;

/* things that are syntactically valid to be a function's method object */
func_valid_object
	: IDENTIFIER												{ $$ = IdentifierNode($1); }
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
	: IDENTIFIER												{ $$ = IdentifierNode($1); }
	| func_call_nothrd_expression								{ $$ = $1; }
	| array_subscripting_expression								{ $$ = $1; }
	| element_selection_expression								{ $$ = $1; }
	| parenthesized_expression									{ $$ = $1; }
	;

/* identifier might be a keyword, size */
element_selection_expression
	: element_valid_selection '.' IDENTIFIER					{
																	int isSize = !strcmp($3, "size");
																	$$ = AllocElementSelectionExpression(isSize, $1, isSize ? 0 : IdentifierNode($3));
																}
	;

/* things that are syntactically valid to be selected through "." */
element_valid_selection
	: IDENTIFIER												{ $$ = IdentifierNode($1); }
	| func_call_nothrd_expression								{ $$ = $1; }
	| array_subscripting_expression								{ $$ = $1; }
	| element_selection_expression								{ $$ = $1; }
	| parenthesized_expression									{ $$ = $1; }
	;

func_ref_expression
	: REFERENCE_FUNC IDENTIFIER									{ $$ = AllocFuncRefExpression(0, IdentifierNode($2)); }
	| IDENTIFIER REFERENCE_FUNC IDENTIFIER						{ $$ = AllocFuncRefExpression(IdentifierNode($1), IdentifierNode($3)); }
	| PATH REFERENCE_FUNC IDENTIFIER							{ $$ = AllocFuncRefExpression(PathNode($1), IdentifierNode($3)); }
	;

expression
	: IDENTIFIER												{ $$ = AllocExpression(TYPE_EXPR_IDENTIFIER, IdentifierNode($1)); }
	| INT_LITERAL												{ $$ = AllocExpression(TYPE_EXPR_INT, IntNode($1)); }
	| FLOAT_LITERAL												{ $$ = AllocExpression(TYPE_EXPR_FLOAT, FloatNode($1)); }
	| STRING_LITERAL											{ $$ = AllocExpression(TYPE_EXPR_STRING, StringNode($1)); }
	| LOC_STRING_LITERAL										{ $$ = AllocExpression(TYPE_EXPR_LOC_STRING, LocStringNode($1)); }
	| HASH_STRING_LITERAL										{ $$ = AllocExpression(TYPE_EXPR_HASH_STRING, HashStringNode($1)); }
	| '(' expression ',' expression ',' expression ')'			{ $$ = AllocExpression(TYPE_EXPR_VECTOR, $2, $4, $6); }
	| EMPTY_ARRAY												{ $$ = AllocExpression(TYPE_EXPR_EMPTY_ARRAY); }
	| UNDEFINED													{ $$ = AllocExpression(TYPE_EXPR_UNDEFINED); }
	| func_call_nothrd_expression								{ $$ = AllocExpression(TYPE_EXPR_FUNC_CALL_NOTHRD, $1); }
	| array_subscripting_expression								{ $$ = AllocExpression(TYPE_EXPR_ARRAY_SUBSCRIPTING, $1); }
	| element_selection_expression								{ $$ = AllocExpression(TYPE_EXPR_ELEMENT_SELECTION, $1); }
	| func_ref_expression										{ $$ = AllocExpression(TYPE_EXPR_FUNC_REF, $1); }
	| expression '?' expression ':' expression					{ $$ = AllocExpression(TYPE_EXPR_TERNARY_OP, $1, $3, $5); }
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
	| '-' INT_LITERAL %prec UNARY_MINUS							{ $$ = AllocExpression(TYPE_EXPR_INT, IntNode(-$2)); }
	| '-' FLOAT_LITERAL %prec UNARY_MINUS						{ $$ = AllocExpression(TYPE_EXPR_FLOAT, FloatNode(-$2)); }
	| '%' IDENTIFIER %prec UNARY_ANIMREF						{ $$ = AllocExpression(TYPE_EXPR_UANIMREF_OP, IdentifierNode($2)); }
	| parenthesized_expression									{ $$ = $1; }
	;

parenthesized_expression
	: '(' expression ')'										{ $$ = $2; }
	;

/* inc_dec_statement and assignment_statement are part of expression_statement or iteration_statement (for loop) only */
statement
	: labeled_statement											{ $$ = $1; }
	| jump_statement											{ $$ = $1; }
	| wait_statement											{ $$ = $1; }
	| expression_statement										{ $$ = $1; }
	| compound_statement										{ $$ = $1; }
	| selection_statement										{ $$ = $1; }
	| iteration_statement										{ $$ = $1; }
	;

inc_dec_statement
	: IDENTIFIER INC_OP											{ $$ = AllocStatement(TYPE_STMT_INC, IdentifierNode($1)); }
	| IDENTIFIER DEC_OP											{ $$ = AllocStatement(TYPE_STMT_DEC, IdentifierNode($1)); }
	| array_subscripting_expression INC_OP						{ $$ = AllocStatement(TYPE_STMT_INC, $1); }
	| array_subscripting_expression DEC_OP						{ $$ = AllocStatement(TYPE_STMT_DEC, $1); }
	| element_selection_expression INC_OP						{ $$ = AllocStatement(TYPE_STMT_INC, $1); }
	| element_selection_expression DEC_OP						{ $$ = AllocStatement(TYPE_STMT_DEC, $1); }
	;

assignment_statement
	: operation_valid_lvalue '=' expression						{ $$ = AllocStatement(TYPE_STMT_REGULAR_ASSIGN, $1, $3); }
	| operation_valid_lvalue PLUS_ASSIGN expression				{ $$ = AllocStatement(TYPE_STMT_PLUS_ASSIGN, $1, $3); }
	| operation_valid_lvalue MINUS_ASSIGN expression			{ $$ = AllocStatement(TYPE_STMT_MINUS_ASSIGN, $1, $3); }
	| operation_valid_lvalue MULTIPLY_ASSIGN expression			{ $$ = AllocStatement(TYPE_STMT_MULTIPLY_ASSIGN, $1, $3); }
	| operation_valid_lvalue DIVIDE_ASSIGN expression			{ $$ = AllocStatement(TYPE_STMT_DIVIDE_ASSIGN, $1, $3); }
	| operation_valid_lvalue MOD_ASSIGN expression				{ $$ = AllocStatement(TYPE_STMT_MOD_ASSIGN, $1, $3); }
	| operation_valid_lvalue SHIFT_LEFT_ASSIGN expression		{ $$ = AllocStatement(TYPE_STMT_SHIFT_LEFT_ASSIGN, $1, $3); }
	| operation_valid_lvalue SHIFT_RIGHT_ASSIGN expression		{ $$ = AllocStatement(TYPE_STMT_SHIFT_RIGHT_ASSIGN, $1, $3); }
	| operation_valid_lvalue BIT_AND_ASSIGN expression			{ $$ = AllocStatement(TYPE_STMT_BIT_AND_ASSIGN, $1, $3); }
	| operation_valid_lvalue BIT_EX_OR_ASSIGN expression		{ $$ = AllocStatement(TYPE_STMT_BIT_EX_OR_ASSIGN, $1, $3); }
	| operation_valid_lvalue BIT_OR_ASSIGN expression			{ $$ = AllocStatement(TYPE_STMT_BIT_OR_ASSIGN, $1, $3); }
	;

operation_valid_lvalue
	: IDENTIFIER												{ $$ = IdentifierNode($1); }
	| array_subscripting_expression								{ $$ = $1; }
	| element_selection_expression								{ $$ = $1; }
	;

labeled_statement
	: CASE INT_LITERAL ':'										{ $$ = AllocStatement(TYPE_STMT_CASE, IntNode($2)); }
	| CASE STRING_LITERAL ':'									{ $$ = AllocStatement(TYPE_STMT_CASE, StringNode($2)); }
	| DEFAULT ':'												{ $$ = AllocStatement(TYPE_STMT_DEFAULT); }
	;

jump_statement
	: CONTINUE ';'												{ $$ = AllocStatement(TYPE_STMT_CONTINUE); }
	| BREAK ';'													{ $$ = AllocStatement(TYPE_STMT_BREAK); }
	| RETURN ';'												{ $$ = AllocStatement(TYPE_STMT_RETURN, 0); }
	| RETURN expression ';'										{ $$ = AllocStatement(TYPE_STMT_RETURN, $2); }
	;

wait_statement
	: WAIT expression ';'										{ $$ = AllocStatement(TYPE_STMT_WAIT, $2); }
	| WAITTILLFRAMEEND ';'										{ $$ = AllocStatement(TYPE_STMT_WAITTILLFRAMEEND); }
	;

/* inc_and_statement and assignment_statement are an exception */
expression_statement
	: ';'														{ $$ = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, 0); }
	| inc_dec_statement ';'										{ $$ = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, $1); }
	| assignment_statement ';'									{ $$ = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, $1); }
	| func_call_nothrd_expression ';'							{ $$ = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, $1); }
	| func_call_thrd_expression ';'								{ $$ = AllocStatement(TYPE_STMT_EXPRESSION_STATEMENT, $1); }
	;

compound_statement
	: '{' '}'													{ $$ = AllocStatement(TYPE_STMT_COMPOUND, 0); }
	| '{' statement_list '}'									{ $$ = AllocStatement(TYPE_STMT_COMPOUND, $2); }
	;

statement_list
	: statement													{ $$ = new std::vector<sNode*>(1, $1); }
	| statement_list statement									{ $$ = $1; $$->push_back($2); }
	;

selection_statement
	: IF '(' expression ')' statement %prec IFX					{ $$ = AllocStatement(TYPE_STMT_IF, $3, $5); }
	| IF '(' expression ')' statement ELSE statement			{ $$ = AllocStatement(TYPE_STMT_IF_ELSE, $3, $5, $7); }
	| SWITCH '(' expression ')' compound_statement				{ $$ = AllocStatement(TYPE_STMT_SWITCH, $3, $5); }
	;

iteration_statement
	: FOR '(' for_init_statement ';' for_cond_expression ';' for_loop_statement ')' statement		{ $$ = AllocStatement(TYPE_STMT_FOR, $3, $5, $7, $9); }
	| WHILE '(' expression ')' statement						{ $$ = AllocStatement(TYPE_STMT_WHILE, $3, $5); }
	| FOREACH '(' IDENTIFIER IN expression ')' statement		{ $$ = AllocStatement(TYPE_STMT_FOREACH, $3, $5, $7); }
	;

for_init_statement
	: /* empty */												{ $$ = 0; }
	| assignment_statement										{ $$ = $1; }
	;

for_cond_expression
	: /* empty */												{ $$ = 0; }
	| expression												{ $$ = $1; }
	;

for_loop_statement
	: /* empty */												{ $$ = 0; }
	| inc_dec_statement											{ $$ = $1; }
	| assignment_statement										{ $$ = $1; }
	;

%%

void yyerror(char const *s)
{
	CompileError("yyerror: %s\nat line %d\n", s, lineCount);
}