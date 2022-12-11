/*test cases for the coordinate library*/
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/coordinate.h"

START_TEST(test_c_createcoordinate) {
    /*summary:
    test for creation of cartesian and polar
    coordinate in the heap;
    */
}
END_TEST

START_TEST(test_c_arithmeticcoordinate) {
    /*summary:
    test for basic arithmetic functions of coordinates
    cartesiancoord c_addcoordinate(int count, ...)
    cartesiancoord c_subcoordinate(int count, ...)
    cartesiancoord c_divcoordinate(int count, ...)
    */

    // test coordinates
    cartesiancoord t1 = { .x = 1, .y = 2 };
    cartesiancoord t2 = { .x = 3, .y = 4 };
    cartesiancoord t3 = { .x = 2, .y = 5 };

    cartesiancoord t5 = addcartesiancoordinate(3, t1, t2, t3);
    ck_assert_int_eq(t5.x, 6);
    ck_assert_int_eq(t5.y, 11);
    printf("---\n");

    cartesiancoord t6 = subcartesiancoordinate(3, t1, t2, t3);
    ck_assert_int_eq(t6.x, -4);
    ck_assert_int_eq(t6.y, -7);
    printf("---\n");

    cartesiancoord t7 = divcartesiancoordinate(3, t1, t2, t3);
    ck_assert_int_eq(t7.x, 0);
    ck_assert_int_eq(t7.y, 0);
    printf("---\n");

    cartesiancoord t9 = multcartesiancoordinate(3, t1, t2, t3);
    ck_assert_int_eq(t9.x, 6);
    ck_assert_int_eq(t9.y, 40);
    printf("---\n");

    // edge cases for variadic functions

    // providing count value more than given
    // amount of arguments.
    // to avoid this we need to have a counter
    // of arguments in the given function for this 
    // check line: coordinate.h 26
    // Implementation is only valid for GCC; MSVC is 
    // bit weird
    //coord t8 = addcoordinate(10, t1, t2, t3);
    //ck_assert_int_eq(t8.x, 6);
    //ck_assert_int_eq(t8.y, 11);
    //printf("---\n");
}
END_TEST

START_TEST(test_c_findmidpoint) {
    /*summary:
    coord c_subcoordinate(coord c1, coord c2, ...)
    */

    // test coordinates
    cartesiancoord t1 = { .x = 1, .y = 2 };
    cartesiancoord t2 = { .x = 3, .y = 4 };

    cartesiancoord t5 = c_findmidpoint(t1, t2);
    ck_assert_int_eq(t5.x, 2);
    ck_assert_int_eq(t5.y, 3);

}
END_TEST

Suite* coordinate_suite(void) {
    /*TEST SUITE for inputstring test cases*/
    Suite* s;
    TCase* tc_core;

    s = suite_create("CoordinateLibTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_c_arithmeticcoordinate);
    tcase_add_test(tc_core, test_c_findmidpoint);
    suite_add_tcase(s, tc_core);
    return s;
}