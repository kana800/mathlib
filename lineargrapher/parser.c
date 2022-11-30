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

	/*
	TODO:
	- parse the string
	- process the string
		- call appopriate function

	*/

	/*checking if the grammar is valid*/
	int validGrammar = g_isvalidgrammar(stringBuffer);
	switch (validGrammar) {
	case 0:
		//g_parseCoordinate(stringBuffer);
	default:
		return false;
	}

	return false;
}

bool isDigit(char c) {
	/*summary: returns if the given
	argument c is a digit
	args:
		char c
	return:
		bool
		True -> digit
		False -> not digit
	*/

	/*
	alternative would be isDigit in std library;
	*/
	for (int i = 0; i < 10; i++) {
		if (Digits[i] == c)
			return true;
	}
	return false;
}

#if TEST
int g_parseCoordinate(char* str) {
#else
static int g_parseCoordinate(char* str){
#endif
	/*summary: parses the coordinate value
	args:
		stringBuffer -> command
	return:
		int
		1 -> Success
		-1 -> Failed
	*/

	/*
	start to iterate through the '2' index because
	all commands are '3' lettered
	a d d ( 4 , 5 )
	0 1 2 3 3 4 5 6 
	*/
	int start = 3;
#if TEST
	int end = strlen(str);
#else 
	int end = stringBufferCount;
#endif
	/*
	checking for invalid syntax;
	if the given input has 
	valid enclosures
	*/
	if ((str[start] != '(') || (str[end - 1] != ')')) {
		printf("start -> %c | end -> %c\n", str[start], str[end - 1]);
		return -1;
	}

	/*stores the given coordinates*/
	int x;
	int y;
	/*stores the location of the separator*/
	int commaIndex = -1;
	/*
	find the location of the comma in the given
	string; finds the first comma, if mutiple commas
	are present then its the wrong syntax.
	*/
	for (int i = start; i < end; i++) {
		printf("%c ", str[i]);
		if (str[i] == ',') {
			commaIndex = i;
			break;
		}
	}
	printf("\n");
	printf("commaIndex %d\n", commaIndex);
	/*
	checking for invalid syntax;
	Example:
		( 4 , t , 5 4 ) 
		0 1 2 3 4 5 6 7
		    ^---commaIndex
	first loop:
	loop:	1 to commaIndex
	data:	( 4 , 
	indx:	0 1 2
		TRUE
	second loop:
	loop:	commaIndex to end
	data:	t , 5 4
	indx:	3 4 5 6
		FALSE
	*/
	for (int i = start + 1; i < commaIndex; i++) {
		printf("l1 %c\n", str[i]);
		if (!isDigit(str[i])) {
			return -1;
		}
	}
	for (int i = commaIndex + 1; i < end - 1; i++) {
		printf("l2 %c\n", str[i]);
		if (!isDigit(str[i])) {
			return -1;
		}
	}
	/*
	TODO:
		find a way to change characters to a number
		'524' -> 524
	*/


	return 1;
}

int g_isvalidgrammar(char* strbuffer) {
	/*summary: checks if the user has
	inputted valid grammar;
	args:
		char* strbuffer -> string buffer
	example:
		add (4,5) this function checks 
	if `add` is valid grammar;
	return: 
		int -> index of the grammar list;
		no valid grammar -> -1
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
			GRAMMARLIST[i])) return i;
	}
	return -1;
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

char* createStringBuffer(inputstring_t* is) {
	/*summary: creates a string buffer 
	and returns it
	args:
		inputstring_t* is -> input string structure
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
