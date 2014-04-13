// bo2_gsc_lexer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

extern "C" { extern int yyparse(); }

int main(int argc, char* argv[])
{
	yyparse();
	cin.get();
	return 0;
}