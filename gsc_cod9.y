%{
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
	int lineCount;
	int yylex(void);
}
#else
int lineCount;
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
%token SWITCH CASE DEFAULT
%token IF ELSE
%token FOR WHILE FOREACH
%token BREAK RETURN CONTINUE WAIT
%token IDENTIFIER UNDEFINED EMPTY_ARRAY INT_LITERAL FLOAT_LITERAL STRING_LITERAL LOC_STRING_LITERAL HASH_STRING_LITERAL
%token SHIFT_RIGHT_ASSIGN SHIFT_LEFT_ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN BIT_AND_ASSIGN BIT_EX_OR_ASSIGN BIT_OR_ASSIGN
%token SHIFT_RIGHT_OP SHIFT_LEFT_OP INC_OP DEC_OP LOGICAL_AND_OP LOGICAL_OR_OP LESS_EQUAL_OP GREATER_EQUAL_OP EQUALITY_OP INEQUALITY_OP
%token THREAD DEREFERENCE_FUNC_START REFERENCE_FUNC DEVBLOCK_START DEVBLOCK_END

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

%start translation_unit

%%

/* need to add support for parenthesized expressions */

translation_unit
	: include
	| using_animtree
	| function_definition
	| translation_unit include
	| translation_unit using_animtree
	| translation_unit function_definition
	;

include
	: INCLUDE PATH ';'
	;

using_animtree
	: USING_ANIMTREE '(' STRING_LITERAL ')' ';'
	;

function_definition
	: IDENTIFIER '(' parameter_list_opt ')' compound_statement
	;

parameter_list_opt
	: /* empty */
	| IDENTIFIER
	| parameter_list_opt ',' IDENTIFIER
	;

vector_literal
	: '(' vector_valid_member ',' vector_valid_member ',' vector_valid_member ')'
	;

/* things that are syntactically valid to be a member of a vector */
vector_valid_member
	: INT_LITERAL
	| FLOAT_LITERAL
	;

/* add function_call_expression inc_or_dec ? */
inc_or_dec_expression
	: IDENTIFIER inc_or_dec
	| array_subscripting_expression inc_or_dec
	| element_selection_expression inc_or_dec
	;

inc_or_dec
	: INC_OP
	| DEC_OP
	;

/* non-pointer function call */
function_call_noptr
	: IDENTIFIER '(' argument_expression_list_opt ')'
	| PATH REFERENCE_FUNC IDENTIFIER '(' argument_expression_list_opt ')'
	;

/* pointer function call */
function_call_ptr
	: DEREFERENCE_FUNC_START func_valid_ptr ']' ']' '(' argument_expression_list_opt ')'
	;

/* can it be reduced to 1 expression ? */
argument_expression_list_opt
	: /* empty */
	| func_valid_argument
	| argument_expression_list_opt ',' func_valid_argument
	;

/* non-thread function call */
function_call_nothrd_expression
	: function_call_noptr
	| function_call_ptr
	| func_valid_object function_call_noptr
	| func_valid_object function_call_ptr
	;

/* thread function call */
function_call_thrd_expression
	: THREAD function_call_noptr
	| THREAD function_call_ptr
	| func_valid_object THREAD function_call_noptr
	| func_valid_object THREAD function_call_ptr
	;

/* things that are syntactically valid to be a function's method object */
func_valid_object
	: IDENTIFIER
	| function_call_nothrd_expression /* hmm sure? :P */
	| array_subscripting_expression
	| element_selection_expression
	;

/* things that are syntactically valid to be a pointer of a function */
func_valid_ptr
	: IDENTIFIER
	| function_call_nothrd_expression
	| array_subscripting_expression
	| element_selection_expression
	;

/* things that are syntactically valid to be an argument passed to a function */
/* inc_or_dec_expression was removed */
func_valid_argument
	: operation_expression
	;

/* Need to add support for more array subscripting expressions */
array_subscripting_expression
	: array_valid_name '[' array_valid_subscripting ']'
	;

/* expressions that are syntactically valid to be a name of an array */
array_valid_name
	: IDENTIFIER
	| function_call_nothrd_expression
	| array_subscripting_expression
	| element_selection_expression
	;

/* expressions that are syntactically valid to be inside "[" and "]" in a subscript  */
/* inc_or_dec_expression was removed */
array_valid_subscripting
	: expression
	;

/* Need to add support for more element selection expressions */
element_selection_expression
	: element_valid_selection '.' IDENTIFIER /* identifier might be a keyword, size */
	;

/* things that are syntactically valid to be selected through "." */
element_valid_selection
	: IDENTIFIER
	| function_call_nothrd_expression
	| array_subscripting_expression
	| element_selection_expression
	;

/* how to add anims? (%) :P */

/* inc_or_dec_expression was removed */
operation_expression
	: IDENTIFIER
	| INT_LITERAL
	| FLOAT_LITERAL
	| STRING_LITERAL
	| LOC_STRING_LITERAL
	| HASH_STRING_LITERAL
	| vector_literal
	| function_call_nothrd_expression
	| array_subscripting_expression
	| element_selection_expression
	| operation_expression LOGICAL_OR_OP operation_expression
	| operation_expression LOGICAL_AND_OP operation_expression
	| operation_expression '|' operation_expression
	| operation_expression '^' operation_expression
	| operation_expression '&' operation_expression
	| operation_expression EQUALITY_OP operation_expression
	| operation_expression INEQUALITY_OP operation_expression
	| operation_expression '<' operation_expression
	| operation_expression '>' operation_expression
	| operation_expression LESS_EQUAL_OP operation_expression
	| operation_expression GREATER_EQUAL_OP operation_expression
	| operation_expression SHIFT_LEFT_OP operation_expression
	| operation_expression SHIFT_RIGHT_OP operation_expression
	| operation_expression '+' operation_expression
	| operation_expression '-' operation_expression
	| operation_expression '*' operation_expression
	| operation_expression '/' operation_expression
	| operation_expression '%' operation_expression
	| '!' operation_expression
	| '~' operation_expression
	| '-' operation_expression %prec UNARY_MINUS
	| '%' IDENTIFIER %prec UNARY_ANIMREF
	| '(' operation_expression ')'
	;

assignment_expression
	: operation_valid_lvalue '=' operation_expression
	| operation_valid_lvalue '=' EMPTY_ARRAY
	| operation_valid_lvalue PLUS_ASSIGN operation_expression
	| operation_valid_lvalue MINUS_ASSIGN operation_expression
	| operation_valid_lvalue MULTIPLY_ASSIGN operation_expression
	| operation_valid_lvalue DIVIDE_ASSIGN operation_expression
	| operation_valid_lvalue MOD_ASSIGN operation_expression
	| operation_valid_lvalue SHIFT_LEFT_ASSIGN operation_expression
	| operation_valid_lvalue SHIFT_RIGHT_ASSIGN operation_expression
	| operation_valid_lvalue BIT_AND_ASSIGN operation_expression
	| operation_valid_lvalue BIT_EX_OR_ASSIGN operation_expression
	| operation_valid_lvalue BIT_OR_ASSIGN operation_expression
	;

operation_valid_lvalue
	: IDENTIFIER
	| array_subscripting_expression
	| element_selection_expression
	;

expression
	: operation_expression
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
	: CASE INT_LITERAL ':' statement
	| CASE STRING_LITERAL ':' statement
	| DEFAULT ':' statement
	;

jump_statement
	: CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

wait_statement
	: WAIT INT_LITERAL ';'
	| WAIT FLOAT_LITERAL ';'
	| WAIT '(' INT_LITERAL ')' ';'
	| WAIT '(' FLOAT_LITERAL ')' ';'
	;

loop_init_value
	: ';'
	| operation_valid_lvalue '=' operation_expression ';'
	;

loop_condition
	: ';'
	| operation_expression ';'
	;

loop_modify_value
	: /* empty */
	| inc_or_dec_expression
	| assignment_expression
	;

/* not putting operation_expression here because it doesn't do anything */
expression_statement
	: inc_or_dec_expression ';'
	| function_call_nothrd_expression ';'
	| function_call_thrd_expression ';'
	| assignment_expression ';'
	| operation_valid_lvalue '=' UNDEFINED ';' /* special undefined case */
	;

compound_statement
	: '{' '}'
	| '{' block_item_list '}'
	;

block_item_list
	: statement
	| block_item_list statement
	;

selection_statement
	: IF '(' expression ')' statement %prec IFX
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' compound_statement /* forcing this one to have curly brackets */
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| FOR '(' loop_init_value loop_condition loop_modify_value ')' statement
	;

%%

void yyerror(char const *s)
{
	printf("error: %s\nat line %d", s, lineCount);
}