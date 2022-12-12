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
    matrix* testM = 
        createMatrix(3, 3, \
            1, 2, 3, 4, 5, 6, 7, 8, 9);
    for (int i = 0; i < 9; i++) {
        ck_assert_float_eq(
            (float)i + 1, testM->matrixptr[i]);
    }
    freeMatrix(testM);
}
END_TEST

START_TEST(test_m_getData) {
    /*summary:
    test for getData function
        float getData(matrix* m, int row, int col);
    */
    matrix* testM = 
        createMatrix(3, 3, \
            1, 2, 3, 4, 5, 6, 7, 8, 9);
    float d1 = getData(testM, 1, 1);
    float d2 = getData(testM, 3, 3);
    // obtaining data normally
    ck_assert_int_eq((int)d1, 1);

    // obtaining data at the end
    ck_assert_int_eq((int)d2, 9);

    freeMatrix(testM);
    
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
    tcase_add_test(tc_core, test_m_getData);
    suite_add_tcase(s, tc_core);
    return s;
}
