/*test cases for the trignometry library*/
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/trig.h"


START_TEST(test_m_sin_cos_taylor) {
    /*summary: test cases for:
        double sin_taylor(int x)
        double cos_taylor(int x)
    we will the benchmark the code here as 
    well
    */

    clock_t start_time;
    double testsine;
    double testcos;
    for (int i = 0; i < 10; i++) {
        start_time = clock();
        testsine = sine_taylor((float)i/10);
		double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
		printf("sin(%f) = %f timetaken -> %f\n",
			(float)i/10, testsine, elapsed_time);
    }

    for (int i = 0; i < 10; i++) {
        start_time = clock();
        testcos = cos_taylor((float)i/10);
		double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
		printf("cos(%f) = %f timetaken -> %f\n",
			(float)i/10, testcos, elapsed_time);
    }

}END_TEST

Suite* trig_suite(void) {
    /*TEST SUITE for inputstring test cases*/
    Suite* s;
    TCase* tc_core;

    s = suite_create("TrigLibTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_m_sin_cos_taylor);
    suite_add_tcase(s, tc_core);
    return s;
}
