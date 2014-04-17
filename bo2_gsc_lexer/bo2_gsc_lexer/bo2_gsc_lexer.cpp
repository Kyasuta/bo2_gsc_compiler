// bo2_gsc_lexer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

extern "C"
{
	extern int yydebug;

	extern FILE* yyin;
	extern int yyparse();
}

int main(int argc, char* argv[])
{
	// set debug mode so the stderr log is written by bison
	yydebug = 1;

	// create a stderr log
	FILE* stderrlog = NULL;
	freopen_s(&stderrlog, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\stderr.log", "w", stderr);

	// open a file handle to the game script
	FILE* inputFile = NULL;
	fopen_s(&inputFile, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\script_parse_test.gsc", "r");
	yyin = inputFile;

	// parse the game script
	yyparse();
	cin.get();

	// close both file handles & exit
	fclose(inputFile);
	fclose(stderrlog);
	return 0;
}