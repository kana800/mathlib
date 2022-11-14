#ifndef INPUTSTRING_H

#include <Windows.h>
#include <stdio.h>

#define MAXCHARCOUNT 10

/*
structure that holds the information
about the input string
*/
typedef struct InputString {
	char string[MAXCHARCOUNT]; /*input string*/
	short size; /*current word count*/
	COORD* currcursorpos; /*current cursor position*/
} inputstring_t;

void InitInputString(inputstring_t* is, int ccount, COORD* cp);
void FreeInputString(inputstring_t* is);

void addChar(inputstring_t* inputstruct, char c);
void removePrevChar(inputstring_t* inputstruct);
void clearInputString(inputstring_t* inputstruct);
void parseString(inputstring_t* is);
void printString(inputstring_t* inputstruct);


#endif // !INPUTSTRING_H
