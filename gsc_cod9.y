%{
#include <stdio.h>

#ifdef __cplusplus
extern "C" { int yylex(void); }
#else
int yylex(void);
#endif
void yyerror(char const *s);
%}

%union {
	int intValue;
	float floatValue;
	char* stringValue;
}

%token INCLUDE PATH USING_ANIMTREE
%token LEVEL SELF ANIM ARRAY_SIZE THREAD
%token SWITCH CASE DEFAULT
%token IF ELSE
%token FOR WHILE FOREACH CONTINUE
%token BREAK
%token RETURN
%token IDENTIFIER UNDEFINED TRUE FALSE EMPTY_ARRAY INT_LITERAL FLOAT_LITERAL STRING_LITERAL LOC_STRING_LITERAL HASH_STRING_LITERAL
%token SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN BIT_AND_ASSIGN BIT_EX_OR_ASSIGN BIT_OR_ASSIGN
%token SHIFT_RIGHT_OP SHIFT_LEFT_OP INC_OP DEC_OP LOGICAL_AND_OP LOGICAL_OR_OP LESS_EQUAL_OP GREATER_EQUAL_OP EQUALITY_OP INEQUALITY_OP
%token REFERENCE_FUNC DEREFERENCE_FUNC_START DEREFERENCE_FUNC_END DEVBLOCK_START DEVBLOCK_END

%right '='
%left '+' '-'
%left '*' '/' '%'

%start translation_unit

%%

translation_unit
	: translation_unit expression '\n'
	| /* empty */
	;

primary_expression
	: IDENTIFIER
	| UNDEFINED
	| INT_LITERAL
	| FLOAT_LITERAL
	| STRING_LITERAL
	| LOC_STRING_LITERAL
	| HASH_STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	;

arithmetic_operator
	: '+'
	| '-'
	| '*'
	| '/'
	| '%'
	;

assign_operator
	: PLUS_ASSIGN
	| MINUS_ASSIGN
	| MULTIPLY_ASSIGN
	| DIVIDE_ASSIGN
	| MOD_ASSIGN
	| SHIFT_RIGHT_ASSIGN
	| SHIFT_LEFT_ASSIGN
	| BIT_AND_ASSIGN
	| BIT_EX_OR_ASSIGN
	| BIT_OR_ASSIGN
	;

unary_postfix_operator
	: INC_OP
	| DEC_OP
	| '.'
	;

unary_prefix_operator
	: '~'
	| '!'
	| '+'
	| "-"
	| "%" /* anim */
	;

statement
	: labeled_statement
	| expression_statement
	| compound_statement
	| selection_statement
	| iteration_statement
	| jump_statement

labeled_statement
	: CASE ':' statement
	| DEFAULT ':' statement
	;

expression_statement
	: ';'
	| expression ';'
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
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: BREAK ';'
	| CONTINUE ';'
	| RETURN ';'
	| RETURN expression ';'
	;

%%

void yyerror(char const *s)
{
	printf("%s", s);
}