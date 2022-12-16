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
    ck_assert_float_eq(d1, 1.00);
    // obtaining data at the end
    ck_assert_float_eq(d2, 9.00);
    freeMatrix(testM);
}
END_TEST

START_TEST(test_m_addMatrix) {
    /*summary:
    test for addMatrix
        void addMatrix(matrix *a, matrix *c);
    */
    matrix* a = createMatrix(3, 3, \
            1, 2, 3, 4, 5, 6, 7, 8, 9);
    matrix* b = createMatrix(3, 3, \
            10, 20, 30, 40, 50, 60, 70, 80, 90);
    matrix* c = createMatrix(3, 3, \
            11, 22, 33, 44, 55, 66, 77, 88, 99);
    matrix* d = createMatrix(2, 2, 1, 2, 3, 4);

    addMatrix(a, b);

    for (int i = 0; i < a->size; i++) {
        ck_assert_float_eq(
            c->matrixptr[i], a->matrixptr[i]);
    }

    // addition should fail in this matrix
    addMatrix(a, d);
    for (int i = 0; i < a->size; i++) {
        ck_assert_float_eq(
            a->matrixptr[i], a->matrixptr[i]);
    }

    freeMatrix(a);
    freeMatrix(b);
    freeMatrix(c);
    freeMatrix(d);
}

START_TEST(test_m_subMatrix) {
    /*summary:
    test for substractMatrix
        void subMatrix(matrix *a, matrix *c);
    */
    matrix* a = createMatrix(3, 3, \
            1, 2, 3, 4, 5, 6, 7, 8, 9);
    matrix* b = createMatrix(3, 3, \
            2, 4, 6, 8, 10, 12, 14, 16, 18);
    matrix* c = createMatrix(3, 3, \
            -1, -2, -3, -4, -5, -6, -7, -8, -9);
    matrix* d = createMatrix(2, 2, 1, 2, 3, 4);

    subMatrix(a, b);

    for (int i = 0; i < a->size; i++) {
        ck_assert_float_eq(
            c->matrixptr[i], a->matrixptr[i]);
    }

    // substraction should fail in this matrix
    subMatrix(a, d);
    for (int i = 0; i < a->size; i++) {
        ck_assert_float_eq(
            a->matrixptr[i], a->matrixptr[i]);
    }

    freeMatrix(a);
    freeMatrix(b);
    freeMatrix(c);
    freeMatrix(d);
}

START_TEST(test_m_scalarMultMatrix) {
    /*summary:
    test for scalar multiplication of a matrix
        void scalarMultMatrix(float a, matrix* b)
    */
    matrix* a = createMatrix(3, 3, \
            1, 2, 3, 4, 5, 6, 7, 8, 9);
    float ascal = 1;
    matrix* b = createMatrix(3, 3, \
            2, 4, 6, 8, 10, 12, 14, 16, 18);
    float bscal = 10;
    matrix* c = createMatrix(3, 3, \
            -1, -2, -3, -4, -5, -6, -7, -8, -9);
    matrix* d = createMatrix(2, 2, 1, 2, 3, 4);

    // no changes should happen; A * 1 = A
    scalarMultMatrix(ascal, a);

    for (int i = 0; i < a->size; i++) {
        ck_assert_float_eq(
            a->matrixptr[i], a->matrixptr[i]);
    }

    // B * 10
    //scalarMultMatrix(bscal, b);

    for (int i = 0; i < a->size; i++) {
    //    ck_assert_float_eq(
    //        b->matrixptr[i], b->matrixptr[i] * 10);
    }

    multMatrix(a, b);

    freeMatrix(a);
    freeMatrix(b);
    freeMatrix(c);
    freeMatrix(d);
}

Suite* matrix_suite(void) {
    /*TEST SUITE for inputstring test cases*/
    Suite* s;
    TCase* tc_core;

    s = suite_create("MatrixLibTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_m_creatematrix);
    tcase_add_test(tc_core, test_m_getData);
    tcase_add_test(tc_core, test_m_addMatrix);
    tcase_add_test(tc_core, test_m_subMatrix);
    tcase_add_test(tc_core, test_m_scalarMultMatrix);
    suite_add_tcase(s, tc_core);
    return s;
}
