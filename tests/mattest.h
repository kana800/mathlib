/*test cases for the matrix library*/
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/matrix.h"

START_TEST(test_m_creatematrix) {
    /*summary:
    test for creation of matrix
        matrix* m createMatrix(int row, int col, ...);
    */
    createMatrix(2, 2, 1, 2, 3, 4);
}
END_TEST

Suite* matrix_suite(void) {
    /*TEST SUITE for inputstring test cases*/
    Suite* s;
    TCase* tc_core;

    s = suite_create("MatrixLibTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_m_creatematrix);
    suite_add_tcase(s, tc_core);
    return s;
}
