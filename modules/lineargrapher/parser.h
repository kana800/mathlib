/*
The parser will go through each character
and compare it with the grammar and call the 
appropriate function.
*/
#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>

#include "inputstring.h"

/*length of the given grammar syntax*/
#define GRAMMARSTRLEN 4
/*size of the grammar list*/
#define GRAMMARCNT 4

#define TEST 1

/*list containing the "grammar"*/
static const char* GRAMMARLIST[] = { 
	"add", "rmv", "plt", "grd" };

static const char* Digits[] = {
	'0','1','2','3','4','5','6','7','8','9'
};

/*string buffers*/

/*is->string without spaces*/
char* stringBuffer;
/*len of the stringbuffer*/
static int stringBufferCount = 0;

/*scan the given string*/
bool parseString(inputstring_t* is);

#if TEST
/*parses the coordinates in a given string*/
int g_parseCoordinate(char* str);
#else 
/*parses the coordinates in a given string*/
static int g_parseCoordinate(char* str);
#endif

/*---helper functions---*/
bool isDigit(char c);

/*check if the given grammar is valid*/
int g_isvalidgrammar(char* strbuffer);
/*compare grammar string with each other*/
int g_strcompare(const char* str1,
	const char* str2);


/*---string operations---*/

/*creates a static char* in the heap*/
char* createStringBuffer(inputstring_t* is);
void freeStringBuffer(char* str);



#endif // !PARSER_H
