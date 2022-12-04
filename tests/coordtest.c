/**/
#include <check.h>
#include <stdio.h>


#include "../lib/coordinate.h"

START_TEST(test_parser_c_addcoordinate) {
    /*summary:
    coord c_addcoordinate(coord c1, coord c2, ...)
    */

    // test coordinates
    coord t1 = { .x = 1, .y = 0 };
    coord t3 = { .x = 2, .y = 0 };

    coord t2 = c_addcoordinate(3, t1, t1, t1);
    printf("coordinate (%d, %d)", t2.x, t2.y);
    ck_assert_int_eq(t2.x, t1.x);
}
END_TEST

Suite* coordinate_suite(void) {
    /*TEST SUITE for inputstring test cases*/
    Suite* s;
    TCase* tc_core;

    s = suite_create("CoordinateLibTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_parser_c_addcoordinate);
    //tcase_add_test(tc_core, test_inputstring_addchar);
    //tcase_add_test(tc_core, test_inputstring_removechar);
    //tcase_add_test(tc_core, test_inputstring_addchar_edgecases);
    suite_add_tcase(s, tc_core);
    return s;
}



int main(void)
{
    int number_failed;
	Suite *s;
    SRunner *sr;

	s = coordinate_suite();

	sr = srunner_create(s);
    //srunner_add_suite(sr);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);

    /*freeing the resources*/
    srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
