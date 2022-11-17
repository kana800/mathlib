/*
The parser will go through each character
and compare it with the grammar and call the 
appropriate function.
*/
#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

#include "inputstring.h"

/*length of the given grammar syntax*/
#define GRAMMARSTRLEN 4
/*size of the grammar list*/
#define GRAMMARCNT 4

/*list containing the "grammar"*/
static const char* GRAMMARLIST[] = { 
	"add", "rmv", "plt", "grd" };

/*scan the given string*/
bool parseString(inputstring_t* is);

/*---helper functions---*/

/*check if the given grammar is valid*/
bool g_isvalidgrammar(inputstring_t* is);
/*compare grammar string with each other*/
int g_strcompare(const char* str1,
	const char* str2);

#endif // !PARSER_H
