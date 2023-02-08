/*
InputString is structure that holds information
about the user-input;
*/
#ifndef INPUTSTRING_H
#define INPUTSTRING_H

#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXCHARCOUNT 20

/*
structure that holds the information
about the input string
*/
typedef struct InputString {
	char string[MAXCHARCOUNT]; /*input string*/
	int size; /*current word count*/
	COORD* cursorpos; /*current cursor position*/
} inputstring_t;

/*---main functions---*/

/*construct a inputstring object*/
inputstring_t * is_createisstruct(COORD * cursorpos);
/*destruct the inputstring object*/
void is_freeis(inputstring_t* is);

/*---helper functions---*/

/*adds a character to the inputstring*/
bool is_addChar(inputstring_t* is, char c);
/*removes a character from the inputstring*/
bool is_removePrevChar(inputstring_t* is);
/*clears the inputstring buffer*/
bool is_clearInputString(inputstring_t* is);

/*---helper functions[debug]---*/
static void is_printString(inputstring_t* is);


#endif // !INPUTSTRING_H
