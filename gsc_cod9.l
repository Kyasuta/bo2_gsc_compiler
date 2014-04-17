D					[0-9]
L					[a-zA-Z_]
P					[a-zA-Z_\\]

%{
#include <io.h>
#include "y.tab.h" // generated by yacc/bison

// windows fix
#define YY_NO_UNISTD_H
#define isatty _isatty // <io.h>
#define fileno _fileno // <stdio.h>

void comment(void);
int another_opening_square_bracket(void);
int next_closing_square_bracket(void);
void invalid_identifier(void);
void unexpected_character(void);

int lineCount = 1;
%}

%%
"/*"				{ comment(); }
"//"[^\n]*			{ /* consume //-comment */; }

"#include"			{ return(INCLUDE); }
"#using_animtree"	{ return(USING_ANIMTREE); }
"break"				{ return(BREAK); }
"case"				{ return(CASE); }
"continue"			{ return(CONTINUE); }
"default"			{ return(DEFAULT); }
"else"				{ return(ELSE); }
"false"				{
						yylval.intValue = 0;
						return(INT_LITERAL);
					}
"for"				{ return(FOR); }
"foreach"			{ return(FOREACH); }
"if"				{ return(IF); }
"return"			{ return(RETURN); }
"switch"			{ return(SWITCH); }
"thread"			{ return(THREAD); }
"true"				{
						yylval.intValue = 1;
						return(INT_LITERAL);
					}
"undefined"			{ return(UNDEFINED); }
"wait"				{ return(WAIT); }
"while"				{ return(WHILE); }

					/* invalid identifier e.g 123myVar, we have to throw an error */
{D}+{L}				{
						invalid_identifier();
					}

					/*	if PATH was defined before IDENTIFIER, then the lexer would return the PATH token always
						when IDENTIFIER has the same size as PATH because its defined first */

					/* identifier e.g. var name, function name... */
{L}({L}|{D})*		{
						yylval.stringValue = _strdup(yytext);
						return(IDENTIFIER);
					}

					/* gsc file path e.g. maps\mp\_utility */
{P}({P}|{D})*		{
						yylval.stringValue = _strdup(yytext);
						return(PATH);
					}

					/* integer e.g. 10 */
{D}+				{
						sscanf_s(yytext, "%d", &yylval.intValue);
						return(INT_LITERAL);
					}

					/* float e.g. 1.5 or .5 */
{D}*"."{D}+			{
						sscanf_s(yytext, "%f", &yylval.floatValue);
						return(FLOAT_LITERAL);
					}

						/* string e.g. "myString" */
\"(\\.|[^\\"\n])*\"		{
							yylval.stringValue = _strdup(yytext);

							// remove last " and skip "
							yylval.stringValue[strlen(yylval.stringValue)] = '\0';
							memmove(yylval.stringValue, yylval.stringValue + 1, strlen(yylval.stringValue));

							return(STRING_LITERAL);
						}

						/* localized string e.g. &"myString" */
&\"(\\.|[^\\"\n])*\"	{
							yylval.stringValue = _strdup(yytext);

							// remove last " and skip &"
							yylval.stringValue[strlen(yylval.stringValue)] = '\0';
							memmove(yylval.stringValue, yylval.stringValue + 2, strlen(yylval.stringValue));

							return(LOC_STRING_LITERAL);
						}

						/* hashed string e.g. #"myString" */
#\"(\\.|[^\\"\n])*\"	{
							yylval.stringValue = _strdup(yytext);

							// remove last " and skip #"
							yylval.stringValue[strlen(yylval.stringValue)] = '\0';
							memmove(yylval.stringValue, yylval.stringValue + 2, strlen(yylval.stringValue));

							return(HASH_STRING_LITERAL);
						}

">>="			{ return(SHIFT_RIGHT_ASSIGN); }
"<<="			{ return(SHIFT_LEFT_ASSIGN); }
"+="			{ return(PLUS_ASSIGN); }
"-="			{ return(MINUS_ASSIGN); }
"*="			{ return(MULTIPLY_ASSIGN); }
"/="			{ return(DIVIDE_ASSIGN); }
"%="			{ return(MOD_ASSIGN); }
"&="			{ return(BIT_AND_ASSIGN); }
"^="			{ return(BIT_EX_OR_ASSIGN); }
"|="			{ return(BIT_OR_ASSIGN); }
">>"			{ return(SHIFT_RIGHT_OP); }
"<<"			{ return(SHIFT_LEFT_OP); }
"++"			{ return(INC_OP); }
"--"			{ return(DEC_OP); }
"&&"			{ return(LOGICAL_AND_OP); }
"||"			{ return(LOGICAL_OR_OP); }
"<="			{ return(LESS_EQUAL_OP); }
">="			{ return(GREATER_EQUAL_OP); }
"=="			{ return(EQUALITY_OP); }
"!="			{ return(INEQUALITY_OP); }
"::"			{ return(REFERENCE_FUNC); }
"/#"			{ return(DEVBLOCK_START); }
"#/"			{ return(DEVBLOCK_END); }
";"				{ return(';'); }
"{"				{ return('{'); }
"}"				{ return('}'); }
","				{ return(','); }
":"				{ return(':'); }
"="				{ return('='); }
"("				{ return('('); }
")"				{ return(')'); }
"["				{ return(another_opening_square_bracket()?DEREFERENCE_FUNC_START:(next_closing_square_bracket()?EMPTY_ARRAY:'[')); }
"]"				{ return(']'); }
"."				{ return('.'); }
"&"				{ return('&'); }
"!"				{ return('!'); }
"~"				{ return('~'); }
"-"				{ return('-'); }
"+"				{ return('+'); }
"*"				{ return('*'); }
"/"				{ return('/'); }
"%"				{ return('%'); }
"<"				{ return('<'); }
">"				{ return('>'); }
"^"				{ return('^'); }
"|"				{ return('|'); }
"?"				{ return('?'); }

[ \t]			{ ; }
\n				{ lineCount++; }
.				{ unexpected_character(); }

%%

int yywrap(void)
{
	return 1;
}

void comment(void)
{
	char c, prev = 0;
	
#ifdef __cplusplus
	while ((c = yyinput()) != 0)	/* (EOF maps to 0) */
#else
	while ((c = input()) != 0)		/* (EOF maps to 0) */
#endif
	{
		if (c == '/' && prev == '*')
			return;
		else if (c == '\n')
			lineCount++;
		prev = c;
	}
	yyerror("unterminated comment");
}

int another_opening_square_bracket(void)
{
	char c = 0;

#ifdef __cplusplus
	while ((c = yyinput()) != 0)	/* (EOF maps to 0) */
#else
	while ((c = input()) != 0)		/* (EOF maps to 0) */
#endif
	{
		if (c == '[')
			return 1;
		else if (c != ' ' && c != '\t' && c != '\n')
		{
			unput(c);
			return 0;
		}
	}
	yyerror("EOF follows after opening square bracket");
	return 0;
}

int next_closing_square_bracket(void)
{
	char c = 0;

#ifdef __cplusplus
	while ((c = yyinput()) != 0)	/* (EOF maps to 0) */
#else
	while ((c = input()) != 0)		/* (EOF maps to 0) */
#endif
	{
		if (c == ']')
			return 1;
		else if (c != ' ' && c != '\t' && c != '\n')
		{
			unput(c);
			return 0;
		}
	}
	yyerror("EOF follows after opening square bracket");
	return 0;
}

void invalid_identifier(void)
{
	yyerror("invalid identifier");
}

void unexpected_character(void)
{
	yyerror("unexpected character");
}