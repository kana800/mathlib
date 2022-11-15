/*
This file consist of the test cases that test components of the linear grapher
module
*/
#include "../lineargrapher/inputstring.h"

#include "Windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

static inputstring_t* is;
static COORD* tempCursor;

START_TEST (test_createinputstringstruct) {
    /*
    test cases for the create input 
    string struct method
    */
    tempCursor = (COORD*)malloc(sizeof(COORD));

    tempCursor->X = 0;
    tempCursor->Y = 0;
    
    is = CreateInputStringStruct(tempCursor);

    ck_assert_int_eq(is->size, 0);
    ck_assert_int_eq(is->cursorpos->X, tempCursor->X);
    ck_assert_int_eq(is->cursorpos->Y, tempCursor->Y);
}
END_TEST

START_TEST (test_inputstring_addchar) {
    /*
    test cases for the
    input string addChar method
    */ 

    /*add char to the input string*/
    char a = 'a';
    addChar(is, a);
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
    */ 

    /*
    remove the character inputted from the 
    previous test 'test_inputstring_addchar'
    */
    char a = 'a';
    removePrevChar(is);
    /*size should be decrement by 1*/
    ck_assert_int_eq(is->size, 0);
    /*cursor 'X' should be move backwards by 1*/
    ck_assert_int_eq(is->cursorpos->X, 0);
    ck_assert_int_eq(is->cursorpos->Y, 0);
    /*
    calling this function should do nothing because
    there are no characters;
    */
    removePrevChar(is);
    ck_assert_int_eq(is->cursorpos->X, 0);
    ck_assert_int_eq(is->cursorpos->Y, 0);
}
END_TEST

START_TEST (test_inputstring_addchar_edgecases) {
    /*test cases for the input string addChar (edgecases)*/ 

    /*add char to the input string*/
    char* testarr1[] = { 'a','b','c','d','e','f','g','h',
        'i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int sizearr1 = 25;
    int i;
    for (i = 0; i <= sizearr1; i++) {
        if (!addChar(is, testarr1[i])) break;
    }

    /*size should be equal to `i`*/
    ck_assert_int_eq(is->size, i);
    /*cursor 'X' should be move backwards by 1*/
    ck_assert_int_eq(is->cursorpos->X, i);
    ck_assert_int_eq(is->cursorpos->Y, 0);

    /*remove characters more than 10*/
    for (int j = 0; (j <= MAXCHARCOUNT + 1); j++) {
        removePrevChar(is);
    }

    /*size should be zero after removing all the characters*/
    ck_assert_int_eq(is->size, 0);
    /*cursor 'X' should be move backwards by 1*/
    ck_assert_int_eq(is->cursorpos->X, 0);
    ck_assert_int_eq(is->cursorpos->Y, 0);

    free(tempCursor);
    free(is);
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

Suite* coordinates_suite(void) {
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


int main(void)
{
    int number_failed;
	Suite *s;
	SRunner *sr;

	s = inputstring_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
