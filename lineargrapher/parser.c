#include "parser.h"


//bool parseString(inputstring_t* is) {
//	/*summary: parses the string according
//	to the given grammar;
//	args:
//		inputstring_t* is -> pointer to the input
//		string;
//	*/
//
//	/*looping through the string; till the end*/
//	int tSize = 0;
//	while (is->size >= tSize) {
//		printf("%d %c", tSize, is->string[tSize]);
//		tSize++;
//	}
//	return true;
//}


bool isvalidgrammar(inputstring_t* is) {
	/*summary: checks if the user has
	inputted valid grammar;
	example:
		add (4,5) this function checks 
	if `add` is valid grammar;
	return: boolean; true if grammar is valid
	else false.
	*/
	
	/*
	always the first three characters of the
	string should be consist of the grammar
	*/
	char tgrammarstr[GRAMMARSTRLEN + 1];
	/*populating the temp grammar string*/
	for (int i = 0; i < GRAMMARSTRLEN; i++) {
		tgrammarstr[i] = is->string[i];
	}
	/*
	looping through the grammar to check
	if valid string is present
	*/
	for (int i = 0; i < GRAMMARCNT; i++) {
		// need to fix here
		// doesnt compare properly
		if (strcmp(GRAMMARLIST[i],
			tgrammarstr) == 0) {
			return false;
		}
	}
	return strcmp(GRAMMARLIST[0], tgrammarstr);
}
