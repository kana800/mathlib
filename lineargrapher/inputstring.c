#include "inputstring.h"


inputstring_t* CreateInputStringStruct(COORD* cursorpos) {
	/*summary: allocates memory for input string struct
	and returns a pointer
	args:
		COORD* cp -> current cursor position
	*/
	inputstring_t* tis;
	tis = malloc(sizeof(inputstring_t));
	tis->size = 0;
	tis->cursorpos = cursorpos;
	return tis;
}

void FreeInputString(inputstring_t* is) {
	/*summary: free the memory 
	in the input string*/
	free(is);
	return;
}



bool addChar(inputstring_t* inputstruct, char c) {
	/*summary: add character to the 
	input string
	args: 
		inputstring_t inputstruct -> structure you need to add
		the character to
		char c -> character you need to add
	*/
	if (inputstruct->size < MAXCHARCOUNT) {
		int tCurrPos = inputstruct->size;
		inputstruct->string[tCurrPos] = c;
		/*incrementing size and cursor position*/
		inputstruct->cursorpos->X++;
		inputstruct->size++;
		return true;
	}
	else {
		return false;
	}
}


void removePrevChar(inputstring_t* inputstruct) {
	/*summary: remove previous character from the 
	input struct
	args:
		inputstring_t inputstructure -> structure that you 
		need the character from
	*/
	if (inputstruct->size > 0) {
		inputstruct->cursorpos->X--;
		inputstruct->size--;
		return;
	}
	else {
		return;
	}
}

void clearInputString(inputstring_t* inputstruct) {
	/*summary: clears the content in the string
	args:
		inputstring_t inputstructure -> structure that you 
		need the character from
	*/
	inputstruct->size = 0;
	inputstruct->cursorpos->X = 0;
}


void parseString(inputstring_t* is) {
	/*summary: parses the string and clear
	args:
		inputstring_t is -> structure that you 
		need the character from
	*/
	is->cursorpos->X = 0;
	is->size = 0;
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