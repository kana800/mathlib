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

	char* stringBuffer = createStringBuffer(is);

	/*checking if the grammar is valid*/
	if (g_isvalidgrammar(stringBuffer)) {
		return true;
	}

	return false;
}


bool g_isvalidgrammar(char* strbuffer) {
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
		tgrammarstr[i] = strbuffer[i];
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

void g_shiftleft(char* strbuffer, int i) {
	/*summary: shift content of inputstring_t
	string to one index left
	args:
		inputstring_t* is -> inputstring structure
		int i -> index to start the shift from
	Example:
		['a','d','d',' ','4']
		  0   1   2   3   4
	if i = 3; 
		this function will shift content after index 'i'
		to the left
	output:
		['a','d','d','4']
	*/
	printf("--------------g_shiftleft-------------\n");
	int tSize = i;
	char tCurrChar;
	char tNextChar;
	while (stringBufferCount > tSize) {
		tCurrChar = strbuffer[tSize];
		tNextChar = strbuffer[tSize + 1];
		printf("%c \n", tNextChar);
		tSize++;
	}

}

char* createStringBuffer(inputstring_t* is) {
	/*summary: creates a string buffer 
	and returns it
	return:
		char * -> char pointer
	*/
	char* temp = (char*)malloc(MAXCHARCOUNT * sizeof(char));
	int i = 0;
	int j = 0;
	/*loop and copy the string to temp*/
	while (is->size > i) {
		/*checking if there is any spaces*/
		if (is->string[i] != ' ') {
			temp[j] = is->string[i];
			j++;
		}
		i++;
	}

	stringBufferCount = i;
	return temp;
}
void freeStringBuffer(char* str) {
	/*summary: free the memory from the 
	heap
	args:
		char* str -> string array
	*/
	for (int i = 0; i < MAXCHARCOUNT; i++) {
		free(str[i]);
	}
	free(str);
}
