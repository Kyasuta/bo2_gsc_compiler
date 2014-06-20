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

void CompileError(char* errorString, ...)
{
	va_list ap;
	
	va_start(ap, errorString);
	int length = _vscprintf(errorString, ap);
	va_end(ap);

	char* allocatedString = (char*)malloc(length + 1);

	va_start(ap, errorString);
	_vsnprintf_s(allocatedString, length + 1, length + 1, errorString, ap);
	va_end(ap);

	MessageBoxA(NULL, allocatedString, NULL, MB_ICONERROR | MB_OK);

	free(allocatedString);
	ExitProcess(-1);
}

bool MustCompileString(sNode* stringNode)
{
	// check if its already compiled or its a keyword
	return stringNode->nodeType != TYPE_COMPILED_STRING
		&& strcmp(stringNode->stringValue, "level")
		&& strcmp(stringNode->stringValue, "anim")
		&& strcmp(stringNode->stringValue, "self")
		&& strcmp(stringNode->stringValue, "game"); // not sure if this last one is needed
}

void CompileStrings()
{
	sNode* curString;
	sNode* curString2;
	char* stringValue;

	// compile strings in compiler->strings
	for (std::vector<sNode*>::iterator it = compiler->strings.begin(); it < compiler->strings.end(); it++)
	{
		curString = *it;

		if (!MustCompileString(curString))
			continue;

		// backup string value
		stringValue = curString->stringValue;

		// allocate compiledString struct (overwrites stringValue)
		curString->compiledString = (sCompiledString*)malloc(sizeof(sCompiledString));

		// compile string
		curString->compiledString->type = curString->nodeType;
		curString->compiledString->stringValue = stringValue;
		curString->compiledString->offset = compiler->GetRelPos();
		compiler->AddBytes(curString->compiledString->stringValue, strlen(curString->compiledString->stringValue) + 1);
		curString->nodeType = TYPE_COMPILED_STRING;

		// check if there's any other string with the same content, if yes, then compile those too
		for (std::vector<sNode*>::iterator it2 = compiler->strings.begin(); it2 < compiler->strings.end(); it2++)
		{
			curString2 = *it2;

			if (curString2 != curString && !strcmp(curString2->stringValue, curString->compiledString->stringValue))
			{
				assert(curString2->nodeType != TYPE_COMPILED_STRING);

				stringValue = curString2->stringValue;

				curString2->compiledString = (sCompiledString*)malloc(sizeof(sCompiledString));

				curString2->compiledString->type = curString2->nodeType;
				curString2->compiledString->stringValue = stringValue;
				curString2->compiledString->offset = curString->compiledString->offset;
				curString2->nodeType = TYPE_COMPILED_STRING;
			}
		}
	}
}

void EmitIncludes()
{
	COD9_GSC* gsc = compiler->gsc;
	sNode* curInclude;
	sNode* curInclude2;
	includeStruct curIncludeStruct;

	compiler->AlignPos(16);

	gsc->includeStructs = compiler->GetRelPos();

	for (std::vector<sNode*>::iterator it = compiler->sourceCode->begin(); it < compiler->sourceCode->end(); it++)
	{
		curInclude = *it;

		if (curInclude->nodeType == TYPE_COMPILED_STRING && curInclude->compiledString->type == TYPE_INCLUDE)
		{
			// make sure the include isn't duplicated, if it is then throw an error
			for (std::vector<sNode*>::iterator it2 = compiler->sourceCode->begin(); it2 < compiler->sourceCode->end(); it2++)
			{
				curInclude2 = *it2;

				if (curInclude2->nodeType == TYPE_COMPILED_STRING && curInclude2->compiledString->type == TYPE_INCLUDE &&
					curInclude2 != curInclude && curInclude2->compiledString->offset == curInclude->compiledString->offset)
					CompileError("CompileError: duplicate include \"%s\"", curInclude->compiledString->stringValue);
			}
			// set up the includeStruct and write it to the stream
			curIncludeStruct.string = curInclude->compiledString->offset;
			compiler->AddBytes(&curIncludeStruct, sizeof(includeStruct));

			gsc->numOfIncludes++;
		}
	}
}

void EmitFuncDefinitions()
{
	COD9_GSC* gsc = compiler->gsc;

	compiler->AlignPos(16);

	sNode* curNode;
	for (std::vector<sNode*>::iterator it = compiler->sourceCode->begin(); it < compiler->sourceCode->end(); it++)
	{
		curNode = *it;
	}
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
	9.	usinganimtreeStructs
	10.	want more data? well no, fuck you
*/

void OnParsingComplete()
{
	COD9_GSC* gsc = compiler->gsc;

	memcpy(&gsc->identifier, COD9_GSC_IDENTIFIER, sizeof(COD9_GSC_IDENTIFIER));

	// add relative path of compiled gsc
	gsc->name = (WORD)compiler->GetRelPos();
	compiler->AddBytes(compiler->relativePath, strlen(compiler->relativePath) + 1);

	// for nodes which are strings, sets up compiledString member
	CompileStrings();

	EmitIncludes();

	EmitFuncDefinitions();
}

void Preyyparse(char* relativePath, char* outputDir)
{
	lineCount = 1;

	compiler = new sCompiler();

	// fix relative path slashes
	compiler->relativePath = _strdup(relativePath);
	for (char* c = compiler->relativePath; *c; c++)
	{
		if (*c == '\\')
			*c = '/';
	}
	
	// open output file
	compiler->outputDir = outputDir;
	fopen_s(&compiler->outputFile, compiler->outputDir, "wb");
}

void Postyyparse()
{
	fwrite(compiler->buf, 1, compiler->GetRelPos(), compiler->outputFile);
	fclose(compiler->outputFile);

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

	Preyyparse("maps/mp/gametypes/_rank.gsc", "C:\\Users\\Ignacio\\Documents\\GitHub\\bo2_gsc_compiler\\bo2_gsc_lexer\\Release\\script_parse_test_out.gsc");
	yyparse();
	Postyyparse();

	//cin.get();

	// close file handles & exit
	fclose(inputFile);
	fclose(stderrlog);
	return 0;
}