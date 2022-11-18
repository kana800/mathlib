#include "parser.h"


bool parseString(inputstring_t* is) {
	/*summary: parses the string according
	to the given grammar;
	args:
		inputstring_t* is -> pointer to the input
		string;
	*/

	/*looping through the string; till the end*/
	int tSize = 0;
	while (is->size > tSize) {
		printf("tokenid: %d - %c\n", tSize, is->string[tSize]);
		tSize++;
	}

	/*checking if the grammar is valid*/
	if (g_isvalidgrammar(is)) {
		return true;
	}

	return false;
}


bool g_isvalidgrammar(inputstring_t* is) {
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
	char tgrammarstr[GRAMMARSTRLEN];
	/*populating the temp grammar string*/
	for (int i = 0; i < GRAMMARSTRLEN - 1; i++) {
		tgrammarstr[i] = is->string[i];
	}

	for (int i = 0; i < GRAMMARCNT; i++) {
		if (g_strcompare(tgrammarstr,
			GRAMMARLIST[i])) return true;
	}
	return false;
}

int g_strcompare(const char* str1, 
	const char* str2) {
	/*summary: compare the given two strings
	and return whether its equal or not;
	args:
		str1 -> string one
		str2 -> string two
	str1 will be compared against str2
	return:
		ret val 1; string is equal
		ret val 0; string is not equal
	*/

	/*looping through the string*/
	for (int i = 0; i < GRAMMARSTRLEN - 1; i++) {
		if (str1[i] != str2[i]) return 0;
	}
	return 1;
}
