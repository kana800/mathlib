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



bool addChar(inputstring_t* is, char c) {
	/*summary: add character to the 
	input string
	args: 
		inputstring_t inputstruct -> structure you need to add
		the character to
		char c -> character you need to add
	*/
	if (is->size < MAXCHARCOUNT) {
		int tCurrPos = is->size;
		is->string[tCurrPos] = c;
		/*incrementing size and cursor position*/
		is->cursorpos->X++;
		is->size++;
		return true;
	}
	else {
		return false;
	}
}


bool removePrevChar(inputstring_t* is) {
	/*summary: remove previous character from the 
	input struct
	args:
		inputstring_t is -> structure that you 
		need the character from
	return: true/false
	*/
	if (is->size > 0) {
		is->cursorpos->X--;
		is->size--;
		return true;
	}
	else {
		return false;
	}
}

bool clearInputString(inputstring_t* is) {
	/*summary: clears the content in the string
	args:
		inputstring_t isure -> structure that you 
		need the character from
	*/
	is->size = 0;
	is->cursorpos->X = 0;
}


void parseString(inputstring_t* is) {
	/*summary: parses the string and clear
	args:
		inputstring_t is -> structure that you 
		need the character from
	*/

}


void printString(inputstring_t* is) {
	/*summary: prints the string;
	use this for DEBUGGING only;
	args:
		inputstring_t isure -> structure print
	*/
	if (is->size == 0) {
		printf("Empty String\n");
		return;
	}
	else {
		printf(": ");
		for (int i = 0; i < is->size; i++) {
			printf("%c", is->string[i]);
		}
		printf("\n");
		return;
	}
}