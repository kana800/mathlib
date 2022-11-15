#ifndef INPUTSTRING_H

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

inputstring_t* CreateInputStringStruct(COORD* cursorpos);
void FreeInputString(inputstring_t* is);

bool addChar(inputstring_t* inputstruct, char c);
void removePrevChar(inputstring_t* inputstruct);
void clearInputString(inputstring_t* inputstruct);
void parseString(inputstring_t* is);
void printString(inputstring_t* inputstruct);


#endif // !INPUTSTRING_H
