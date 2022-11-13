#include "../lineargrapher/inputstring.h"

#include "Windows.h"


static inputstring_t* is = NULL;

int main(int argc, char* argv[]) {
	
	/*initialize the input string*/

	is = malloc(sizeof(inputstring_t));

	COORD tCoord = { 0,0 };
	short tCount = 0;

	initInputString(is, tCount, tCoord);

	printString(is);

	/*add some characters*/
	addChar(is, 'a');
	addChar(is, 'b');
	addChar(is, 'c');
	addChar(is, 'd');

	/*print characters*/
	printString(is);

	/*remove prevchar*/
	removePrevChar(is);

	/*print characters*/
	printString(is);

	free(is);



	return 0;
}

