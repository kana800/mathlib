/*test cases for the matrix library*/
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/matrix.h"

START_TEST(test_m_creatematrix) {
    /*summary:
    test for creation of the matrix
    test for size of the matrix
        matrix* m createMatrix(int row, int col, ...);
        int getSize(matrix* m);
    */
    matrix* testM = 
        createMatrix(3, 3, \
            1, 2, 3, 4, 5, 6, 7, 8, 9);

    ck_assert_int_eq(3 * 3, testM->size);

    // iterating through the matrix pointer
    elementcontainer* tempE = testM->matrixptr;
    printf("-------ElementContainerTest-------\n");
    while (tempE != NULL) {
        printf("(%d) Data at (%d, %d) : %.2f\n",
            tempE->e->index,
            tempE->e->row,
            tempE->e->col,
            tempE->e->d);
        tempE = tempE->next;
    }

    freeMatrix(testM);
    printf("----------------------------------\n");
}
END_TEST


START_TEST(test_m_getData) {
    /*summary:
    test for getData function
        float getData(matrix* m, int row, int col);
    */
    printf("------------getDataTest-----------\n");
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
    printf("----------------------------------\n");
}
END_TEST


START_TEST(test_m_arithmeticMatrix) {
    /*summary:
    test for addMatrix and subMatrix
        void addMatrix(matrix *a, matrix *c);
        void subMatrix(matrix *a, matrix *c);
    */
    matrix* a = createMatrix(3, 3, \
            1, 2, 3, 4, 5, 6, 7, 8, 9);
    matrix* b = createMatrix(3, 3, \
            10, 20, 30, 40, 50, 60, 70, 80, 90);
    matrix* c = createMatrix(3, 3, \
            11, 22, 33, 44, 55, 66, 77, 88, 99);
    matrix* d = createMatrix(2, 2, 1, 2, 3, 4);
    matrix* e = createMatrix(2, 2, 2, 3, 4, 5, 6);
    matrix* f = createMatrix(2, 2, 1, 1, 1, 1, 1);

    addMatrix(a, b);
    subMatrix(e, d);
    // addition of matrix
    elementcontainer* tempA = a->matrixptr;
    elementcontainer* tempC = c->matrixptr;
    while ((tempA != NULL) 
        || (tempC != NULL)) {

        ck_assert_float_eq(tempA->e->d, tempC->e->d);
        tempA = tempA->next;
        tempC = tempC->next;
    }
    // substraction of matrix
    elementcontainer* tempE = e->matrixptr;
    elementcontainer* tempF = f->matrixptr;
    while ((tempE != NULL) 
        || (tempF != NULL)) {

        ck_assert_float_eq(tempE->e->d, tempF->e->d);
        tempE = tempE->next;
        tempF = tempF->next;
    }
    // addition should fail in this matrix
    // substraction should fail in this matrix
    addMatrix(a, d);
    subMatrix(a, d);

    freeMatrix(a);
    freeMatrix(b);
    freeMatrix(c);
    freeMatrix(d);
}


START_TEST(test_m_getRowCol) {
    /*summary:
    tests for getRow and getCol
        elementcontainer* getRow(matrix* m, int row);
        elementcontainer* getCol(matrix* m, int col);
    */
    matrix* testM = 
        createMatrix(3, 3, \
            1, 2, 3, 4, 5, 6, 7, 8, 9);

    elementcontainer* row_1 = getRow(testM, 1);
    elementcontainer* col_1 = getCol(testM, 1);

    printf("--------------RowTest-------------\n");
    // iterating through the elementcontainer
    elementcontainer* tempE = row_1;
    while (tempE != NULL) {
        printf("(%d) Data at (%d, %d) : %.2f\n",
            tempE->e->index,
            tempE->e->row,
            tempE->e->col,
            tempE->e->d);
        tempE = tempE->next;
    }

    printf("--------------ColTest-------------\n");
    // iterating through the elementcontainer
    elementcontainer* tempC = col_1;
    while (tempC != NULL) {
        printf("(%d) Data at (%d, %d) : %.2f\n",
            tempC->e->index,
            tempC->e->row,
            tempC->e->col,
            tempC->e->d);
        tempC = tempC->next;
    }

    freeMatrix(testM);
    freeContainer(row_1);
    freeContainer(col_1);
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
    tcase_add_test(tc_core, test_m_arithmeticMatrix);
    tcase_add_test(tc_core, test_m_getRowCol);
    suite_add_tcase(s, tc_core);
    return s;
}
