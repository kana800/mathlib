#include "inputstring.h"

void initInputString(
	inputstring_t* is, short ccount, COORD cp) {
	/*summary: (constructor) initialize the input string
	args:
		inputstring* is -> pointer to the input string structure
		short ccount -> current char count default = 0
		COORD cp -> current cursor position
	*/
	is->size = ccount;
	is->currcursorpos = cp;
}


void addChar(inputstring_t* inputstruct, char c) {
	/*summary: add character to the 
	input string
	args: 
		inputstring_t inputstruct -> structure you need to add
		the character to
		char c -> character you need to add
	*/
	short tCurrPos = inputstruct->size;
	inputstruct->string[tCurrPos] = c;
	/*incrementing size and cursor position*/
	inputstruct->currcursorpos.X++;
	inputstruct->size++;
}


void removePrevChar(inputstring_t* inputstruct) {
	/*summary: remove previous character from the 
	input struct
	args:
		inputstring_t inputstructure -> structure that you 
		need the character from
	*/
	inputstruct->currcursorpos.X--;
	inputstruct->size--;
}

void clearInputString(inputstring_t* inputstruct) {
	/*summary: clears the content in the string
	args:
		inputstring_t inputstructure -> structure that you 
		need the character from
	*/
	inputstruct->size = 0;
	inputstruct->currcursorpos.X = 0;
}


void parseString(inputstring_t* is) {
	/*summary: parses the string and clear
	args:
		inputstring_t is -> structure that you 
		need the character from
	*/
	is->currcursorpos.X = 0;
	is->size = 0;
}

void moveCursor(inputstring_t* is, const HANDLE hstdout) {
	/*summary: moves the curso
	args:
		inputstring_t inputstructure -> structure cursor
		HANDLE hstdout -> console output
	*/
	SetConsoleCursorPosition(
		hstdout, is->currcursorpos);
}

void printString(inputstring_t* inputstruct) {
	/*summary: prints the string;
	use this for DEBUGGING only;
	args:
		inputstring_t inputstructure -> structure print
	*/
	if (inputstruct->size == 0) {
		printf("Empty String\n");
		return;
	}
	else {
		printf(": ");
		for (int i = 0; i < inputstruct->size; i++) {
			printf("%c", inputstruct->string[i]);
		}
		printf("\n");
		return;
	}

}