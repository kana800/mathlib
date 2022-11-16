/*
The parser will go through each character
and compare it with the grammar and call the 
appropriate function.
*/
#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

#include "inputstring.h"

#define GRAMMARSTRLEN 3
#define GRAMMARCNT 4

/*list containing the "grammar"*/
static char* GRAMMARLIST[GRAMMARCNT] = { 
	"add", "rmv", "plt", "grd" };

/*scan the given string*/
//bool parseString(inputstring_t* is);

/*---helper functions---*/
bool isvalidgrammar(inputstring_t* is);

#endif // !PARSER_H
