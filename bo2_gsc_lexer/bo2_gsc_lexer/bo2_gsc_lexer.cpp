// bo2_gsc_lexer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bo2_gsc_file.h"

using namespace std;

extern int lineCount;
extern int yydebug;

extern FILE* yyin;
extern int yyparse();

void recursive_yyparse(char* dir)
{
	char fileDir[MAX_PATH];
	strcpy_s(fileDir, dir);

	char* _dir = fileDir;
	char* tmp;
	while (true)
	{
		tmp = strchr(_dir, '\\');

		if (tmp)
			_dir = tmp + 1;
		else
			break;
	}

	HANDLE hFind;
	WIN32_FIND_DATAA data;
	FILE* fileHandle;
	
	hFind = FindFirstFileA(dir, &data);
	
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (strcmp(data.cFileName, ".") && strcmp(data.cFileName, ".."))
				{
					strcpy(_dir, data.cFileName);
					strcat(_dir + strlen(data.cFileName), "\\*");
					recursive_yyparse(fileDir);
				}
			}
			else if (!strcmp(PathFindExtensionA(data.cFileName), ".gsc") &&
				strcmp(data.cFileName, "_globallogic_utils.gsc") &&
				strcmp(data.cFileName, "_foliage_cover.gsc") &&
				strcmp(data.cFileName, "_menus.gsc") &&
				strcmp(data.cFileName, "_specialops.gsc") &&
				strcmp(data.cFileName, "_zombiemode_money.gsc"))
			{
				strcpy(_dir, data.cFileName);

				printf_s("parsing %s\n", fileDir);
				
				FILE* stderrlog = NULL;
				freopen_s(&stderrlog, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\stderr.log", "w", stderr);

				fopen_s(&fileHandle, fileDir, "r");
				yyin = fileHandle;
				lineCount = 1;
				yyparse();
				fclose(fileHandle);

				fclose(stderrlog);
				DeleteFileA("C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\stderr.log");
			}
		} while (FindNextFileA(hFind, &data));

		FindClose(hFind);
	}
}

// NOT ALL STRINGS
void CompileStrings()
{
	sNode* curString;
	for (std::vector<sNode*>::iterator it = compiler->strings.begin(); it < compiler->strings.end(); it++)
	{
		curString = *it;

		compiler->AddBytes(curString->stringValue, strlen(curString->stringValue) + 1);
	}
}

void EmitInclude(sNode* node)
{
	COD9_GSC* gsc = compiler->gsc;

	// need to actually compile the fucking strings first to know the offset of it

	gsc->numOfIncludes++;
}

void EmitUsingAnimTree(sNode* node)
{
	COD9_GSC* gsc = compiler->gsc;
}

void EmitFuncDefinition(sNode* node)
{
	COD9_GSC* gsc = compiler->gsc;
}

void CompileError(char* msg)
{
	MessageBoxA(NULL, msg, NULL, MB_OK | MB_ICONERROR);
	ExitProcess(-1);
}

/*
	IMPORTANT, COMPILED GSC DATA ORDER:

	1.	header
	2.	gsc name
	3.	string table
	4.	includeStructs
	5.	unknown code section start bullshit, most likely padding
	6.	function code -> there're some bytes before/after each function, but its most likely just weird padding
	7.	funcDefinitions
	8.	referencedFunctions (gonna rename this)
	9.	want more data? well no, fuck you
*/

void OnParsingComplete(std::vector<sNode*>* sourceCode)
{
	COD9_GSC* gsc = compiler->gsc;
	memcpy(&gsc->identifier, COD9_GSC_IDENTIFIER, sizeof(COD9_GSC_IDENTIFIER));

	// add relative path of compiled gsc
	gsc->name = (WORD)compiler->GetRelPos();
	compiler->AddBytes(compiler->relativePath, strlen(compiler->relativePath) + 1);

	// for nodes which are strings, sets up compiledString member
	CompileStrings();

	sNode* curNode;
	for (std::vector<sNode*>::iterator it = sourceCode->begin(); it < sourceCode->end(); it++)
	{
		curNode = *it;

		if (curNode->nodeType == TYPE_INCLUDE)
			EmitInclude(curNode);
		else if (curNode->nodeType == TYPE_USINGANIMTREE)
			EmitUsingAnimTree(curNode);
		else if (curNode->nodeType == TYPE_FUNC_DEFINITION)
			EmitFuncDefinition(curNode);
		else
			CompileError("CompileError: wrong nodeType at file scope");
	}
}

void Preyyparse(char* relativePath, FILE* outputFile)
{
	lineCount = 1;

	compiler = new sCompiler();

	compiler->relativePath = _strdup(relativePath);
	for (char* c = compiler->relativePath; c < compiler->relativePath + strlen(compiler->relativePath); c++)
	{
		if (*c == '\\')
			*c = '/';
	}

	compiler->outputFile = outputFile;
}

void Postyyparse()
{
	fwrite(compiler->buf, 1, compiler->GetRelPos(), compiler->outputFile);

	free(compiler->relativePath);
	delete compiler;
}

int main(int argc, char* argv[])
{
	// set debug mode so the stderr log is written by bison
	yydebug = 1;

	// create a stderr log
	FILE* stderrlog = NULL;
	freopen_s(&stderrlog, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\stderr.log", "w", stderr);

	FILE* inputFile = NULL;
	fopen_s(&inputFile, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\script_parse_test.gsc", "r");
	yyin = inputFile;

	// parse the game script
	// loop through the raw bo1 folder to parse the game scripts
	//recursive_yyparse("E:\\Program Files (x86)\\Steam\\steamapps\\common\\call of duty black ops\\raw\\*");

	FILE* outputFile = NULL;
	fopen_s(&outputFile, "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\script_parse_test_out.gsc", "wb");

	Preyyparse("maps/mp/gametypes/_rank.gsc", outputFile);
	yyparse();
	Postyyparse();

	cin.get();

	// close file handles & exit
	fclose(outputFile);
	fclose(inputFile);
	fclose(stderrlog);
	return 0;
}