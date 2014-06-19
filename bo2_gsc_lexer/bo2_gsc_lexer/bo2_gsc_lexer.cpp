// bo2_gsc_lexer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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

// loop all nodes, check for all strings if its same as another string
// create sCompilerString* and change node type
void CompileStrings()
{

}

void OnParsingComplete(std::vector<sNode*>* sourceCode)
{
	sNode* curNode;
	for (std::vector<sNode*>::iterator it = sourceCode->begin(); it < sourceCode->end(); it++)
	{
		curNode = *it;

		if (curNode->nodeType == TYPE_FUNC_DEFINITION)
		{
			printf("%s\n", curNode->funcDefinition->funcName->stringValue);

			if (curNode->funcDefinition->compoundStatement->statement->nodeList)
			{
				for (std::vector<sNode*>::iterator it2 = curNode->funcDefinition->compoundStatement->statement->nodeList->begin();
					it2 < curNode->funcDefinition->compoundStatement->statement->nodeList->end(); it2++)
				{
					if ((*it2)->nodeType == TYPE_STATEMENT && (*it2)->statement->type == TYPE_EXPRESSION_STATEMENT && (*it2)->statement->nodeList->at(0)->nodeType == TYPE_FUNC_CALL)
						printf("%s\n", (*it2)->statement->nodeList->at(0)->funcCall->funcName->stringValue);
				}
			}
		}
	}

	printf("\n");
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
	lineCount = 1;
	yyparse();
	cin.get();

	// close both file handles & exit
	fclose(inputFile);
	fclose(stderrlog);
	return 0;
}