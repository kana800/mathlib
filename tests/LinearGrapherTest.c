/*
This file consist of the test cases that test components of the linear grapher
module
*/
#include "../lineargrapher/inputstring.h"
#include "../lineargrapher/parser.h"

#include "Windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

static inputstring_t* is;
static COORD* tempCursor;

static void freeResources() {
    /*summary: free the resources*/
    free(tempCursor);
    free(is);
}

static void addcharmult(char* arr, int size) {
    /*summary: add multiple character to the string
    args:
        char* arr -> pointer to the arr
        int size -> size of the arr
    */
    for (int i = 0; i < size; i++) {
        printf("adding char %c \n", arr[i]);
        is_addChar(is, arr[i]);
    }
}

/*---INPUTSTRING---*/
START_TEST (test_createinputstringstruct) {
    /*
    test cases for the create input 
    string struct method
        inputstring_t * 
        is_createisstruct(COORD * cursorpos);
    */
    tempCursor = (COORD*)malloc(sizeof(COORD));

    tempCursor->X = 0;
    tempCursor->Y = 0;
    
    is = is_createisstruct(tempCursor);

    ck_assert_int_eq(is->size, 0);
    ck_assert_int_eq(is->cursorpos->X, tempCursor->X);
    ck_assert_int_eq(is->cursorpos->Y, tempCursor->Y);
}
END_TEST

START_TEST (test_inputstring_addchar) {
    /*
    test cases for the
    input string addChar method
        bool is_addChar(inputstring_t* is, char c);
    */ 

    /*add char to the input string*/
    char a = 'a';
    is_addChar(is, a);
    /*size should be incremented by 1*/
    ck_assert_int_eq(is->size, 1);
    /*cursor 'X' should be moved by 1*/
    ck_assert_int_eq(is->cursorpos->X, 1);
    ck_assert_int_eq(is->cursorpos->Y, 0);
    /*first character should be a*/
    char ts_0 = is->string[0];
    ck_assert_int_eq(ts_0, a);
}
END_TEST

START_TEST (test_inputstring_removechar) {
    /*
    test cases for the input string
    removeChar method
        bool is_addChar(inputstring_t* is, char c);
    */ 

    /*
    remove the character inputted from the 
    previous test 'test_inputstring_addchar'
    */
    char a = 'a';
    is_removePrevChar(is);
    /*size should be decrement by 1*/
    ck_assert_int_eq(is->size, 0);
    /*cursor 'X' should be move backwards by 1*/
    ck_assert_int_eq(is->cursorpos->X, 0);
    ck_assert_int_eq(is->cursorpos->Y, 0);
    /*
    calling this function should do nothing because
    there are no characters;
    */
    is_removePrevChar(is);
    ck_assert_int_eq(is->cursorpos->X, 0);
    ck_assert_int_eq(is->cursorpos->Y, 0);
}
END_TEST

START_TEST (test_inputstring_addchar_edgecases) {
    /*
    test cases for the input string addChar 
    (edgecases)
        bool is_addChar(inputstring_t* is, char c);
    */ 

    /*add char to the input string*/
    char* testarr1[] = { 'a','b','c','d','e','f','g','h',
        'i','k','l','m','n','o','p','q','r','s','t',
        'u','v','w','x','y','z'};
    int sizearr1 = 25;
    int i;
    for (i = 0; i <= sizearr1; i++) {
        if (!is_addChar(is, testarr1[i])) break;
    }

    /*size should be equal to `i`*/
    ck_assert_int_eq(is->size, i);
    /*cursor 'X' should be move backwards by 1*/
    ck_assert_int_eq(is->cursorpos->X, i);
    ck_assert_int_eq(is->cursorpos->Y, 0);

    /*remove characters more than 10*/
    for (int j = 0; (j <= MAXCHARCOUNT + 1); j++) {
        is_removePrevChar(is);
    }

    /*size should be zero after removing all the characters*/
    ck_assert_int_eq(is->size, 0);
    /*cursor 'X' should be move backwards by 1*/
    ck_assert_int_eq(is->cursorpos->X, 0);
    ck_assert_int_eq(is->cursorpos->Y, 0);
}
END_TEST

START_TEST(test_inputstring_removechar_edgecases) {
    /*
        bool is_removePrevChar(inputstring_t* is);
    */
}
END_TEST

START_TEST(test_inputstring_clearinputstring) {
    /*

    bool is_clearInputString(inputstring_t* is);
    */
}
END_TEST


/*---PARSER---*/
START_TEST(test_parser_parseString) {
    /*
    test cases for the parseString function
        bool parseString(inputstring_t* is);
    */
    is_clearInputString(is);

    char* testline = "add (4,3)";
    addcharmult(testline, 9);
    parseString(is);

}
END_TEST

START_TEST(test_parser_g_strcompare) {
    /*
    test cases for helper function:
        g_strcompare(const char* str1,
            const char* str2);
    */
    char* teststr1 = "add";
    char* teststr2 = "aDd";
    char* teststr3 = "rmv";

    /*add != aDd*/
    ck_assert_int_eq(g_strcompare(teststr1, teststr2), 0);
    /*add == add*/
    ck_assert_int_eq(g_strcompare(teststr1, teststr1), 1);
    /*add != rmv*/
    ck_assert_int_eq(g_strcompare(teststr1, teststr3), 0);
}

START_TEST(test_parser_g_isvalidgrammar) {
    /*
    test cases for the g_isvalidgrammar function
        g_isvalidgrammar(inputstring_t* is);
    */
    is_clearInputString(is);

    is_addChar(is, 'a');
    is_addChar(is, 'd');
    is_addChar(is, 'd');
    ck_assert_int_eq(g_isvalidgrammar(is), true);
    is_clearInputString(is);

}
END_TEST

Suite* inputstring_suite(void) {
    /*TEST SUITE for inputstring test cases*/
    Suite* s;
    TCase* tc_core;

    s = suite_create("InputStringTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_createinputstringstruct);
    tcase_add_test(tc_core, test_inputstring_addchar);
    tcase_add_test(tc_core, test_inputstring_removechar);
    tcase_add_test(tc_core, test_inputstring_addchar_edgecases);
    suite_add_tcase(s, tc_core);
    return s;
}

Suite* parser_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("ParserTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_parser_parseString);
    tcase_add_test(tc_core, test_parser_g_isvalidgrammar);
    tcase_add_test(tc_core, test_parser_g_strcompare);
    suite_add_tcase(s, tc_core);
    return s;
}


int main(void)
{
    int number_failed;
	Suite *s;
    Suite* parsersuite;
    SRunner *sr;

	s = inputstring_suite();
    parsersuite = parser_suite();

	sr = srunner_create(s);
    srunner_add_suite(sr, parsersuite);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);

    /*freeing the resources*/
    freeResources();
    srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
