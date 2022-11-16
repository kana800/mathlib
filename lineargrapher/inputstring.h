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
inputstring_t* CreateInputStringStruct(COORD* cursorpos);
void FreeInputString(inputstring_t* is);

/*---helper functions---*/
bool addChar(inputstring_t* is, char c);
bool removePrevChar(inputstring_t* is);
bool clearInputString(inputstring_t* is);

/*---helper functions[debug]---*/
void printString(inputstring_t* is);


#endif // !INPUTSTRING_H
