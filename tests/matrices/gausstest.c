/*test cases for gauss jordan module*/
#include <assert.h>
#include <stdio.h>

#include "gaussjordan.h"
#include "../../../lib/matrix/matrix.h"

void compareMatrices(matrix* a, matrix* b)
{
	/*summary: compare matrix a with b
	 *args: matrix * a -> pointer to matrix a
	 	matrix * b -> pointer to matrix b
	 *ret:NIL*/
	//comparing the sizes
	assert(a->size == b->size);
	//comparing the rows and columns
	assert(a->rowc == b->rowc);
	assert(a->colc == b->colc);
	//comparing data inside the matrices
	for (int i = 0; i < a->size; i++){
		assert(a->arr[i] == b->arr[i]);	
	}
	return;
}

void compareMatricesWithArr(matrix* a, int* arr,int size){
	/*summary: compare matrix a's arr with arr 
	 *args: matrix * a -> pointer to matrix a
	 	int* arr -> int pointer
		int size -> size of the array
	 *ret: NIL*/
	for (int i = 0; i < size; i++){
		assert(a->arr[i] == arr[i]);	
	}
	return;
}

int main(int argc, char *argv[])
{
	/*gaussjordan.h*/

	/* creating matrices 
	 * a = [1 2 1]
	 *     [3 8 1]
	 *     [0 4 1]*/
	matrix* a = createMatrix(3,3,0,2,1,3,8,1,0,4,1);
	 /* b = [2 ]
	 *      [12]
	 *      [2 ]*/
	matrix* b = createMatrix(3,1,2,12,2);
	/* c = [1 2 -1 1]
	 *     [1 1 -1 1]
	 *     [1 1 3 -1]*/
	matrix* c = createMatrix(3,4,1,2,-1,1,1,1,-1,1,1,1,3,-1);
	/* d = [3]
	 *     [1]
	 *     [5]*/
	matrix* d = createMatrix(3,1,3,1,5);
	/* e = [1 2 1]
	 *     [3 0 1]
	 *     [0 4 1]*/
	matrix* e = createMatrix(3,3,1,2,1,3,0,1,0,4,1);
	/* f = [3 2 5 6]
	 *     [7 3 5 1]
	 *     [2 3 4 2]*/
	matrix* f = createMatrix(3,4,3,2,5,6,7,3,5,1,2,3,4,2);
	/* g = [0 2 5 6]
	 *     [0 3 0 1]
	 *     [0 3 0 2]*/
	matrix* g = createMatrix(3,4,0,2,5,6,0,3,0,1,0,3,0,2);


	/*aug_1 = [a|b]
	 *aug_1 = [0 2 1 | 2 ]
	 *        [3 8 1 | 12]
	 *        [0 4 1 | 2 ]*/
	augmatrix* aug_1 = createAugmentedMatrix(a, b);
	
	/*aug_2 = [c|d]
	 *aug_2 = [1 2 -1 1 | 3]
	 *        [1 1 -1 1 | 1]
	 *        [1 1 3 -1 | 5]*/
	augmatrix* aug_2 = createAugmentedMatrix(c, d);

	/*aug_3 = [e|b]
	 *aug_3 = [1 2 1| 2 ]
	 *        [3 8 1| 12]
	 *        [0 4 1| 3 ]*/
	augmatrix* aug_3 = createAugmentedMatrix(e, b);
	
	/*aug_4 = [g| b]
	 *aug_4 = [0 2 5 6| 3]
	 *        [0 3 0 1| 1]
	 *        [0 3 0 2| 5]*/
	augmatrix* aug_4 = createAugmentedMatrix(g, b);

	/*tests for findPivotPoint(augmatrix* a, piv)*/
	
	/*aug_1 = [0 2 1 | 2 ]
	 *        [3 8 1 | 12] <- piv (1)
	 *        [0 4 1 | 2 ]
	 *swapped will occur
	 *aug_1 = [3 8 1 | 12 ] <- piv (1)
	 *        [0 2 1 | 2 ]
	 *        [0 4 1 | 2 ]*/
	int aug_1_piv_1_arra[] = {3,8,1,0,2,1,0,4,1};
	int aug_1_piv_1_arrb[] = {12,2,2};
	int aug_1_piv_1 = findPivotPoint(aug_1, 1);
	compareMatricesWithArr(aug_1->arr_a, aug_1_piv_1_arra, 9);
	compareMatricesWithArr(aug_1->arr_b, aug_1_piv_1_arrb, 3);
	assert(aug_1_piv_1 ==  0);
	performRowReduction(aug_1, 
			getRow(aug_1->arr_a, aug_1_piv_1), 
			getCol(aug_1->arr_a, aug_1_piv_1), 1);
	/*aug_1 = [3 8 1 | 12 ] <- piv (1)
	 *        [0 2 1 | 2]
	 *        [0 4 1 | 2 ]
	 *after row reduction 
	 *aug_1 = [3 8 1 | 12 ] 
	 *        [0 2 1 | 2]
	 *        [0 4 1 | 2 ]*/
	compareMatricesWithArr(aug_1->arr_a, aug_1_piv_1_arra, 9);
	compareMatricesWithArr(aug_1->arr_b, aug_1_piv_1_arrb, 3);
	
	/*aug_1 = [3 8 1 | 12]
	 *        [0 2 1 | 2 ] <- piv (2)
	 *        [0 4 1 | 2 ]*/
	int aug_1_piv_2_arra[] = {3,8,1,0,2,1,0,0,-1};
	int aug_1_piv_2_arrb[] = {12,2,-2};
	int aug_1_piv_2 = findPivotPoint(aug_1, 2);
	assert(aug_1_piv_2 ==  4);
	performRowReduction(aug_1, 
			getRow(aug_1->arr_a, aug_1_piv_2), 
			getCol(aug_1->arr_a, aug_1_piv_2), 2);
	/*aug_1 = [3 8 1 | 12] 
	 *        [0 2 1 | 2 ] <- piv (2)
	 *        [0 4 1 | 2 ]
	 *after row reduction 
	 *aug_1 = [3 8 1 | 12] 
	 *        [0 2 1 | 2 ]
	 *        [0 0 -1| -6]*/
	compareMatricesWithArr(aug_1->arr_a, aug_1_piv_2_arra, 9);
	compareMatricesWithArr(aug_1->arr_b, aug_1_piv_2_arrb, 3);

	/*aug_2 = [c|d]
	 *aug_2 = [1 2 -1 1 | 3]
	 *        [1 1 -1 1 | 1]
	 *        [1 1 3 -1 | 5]*/
	int aug_2_piv_1_arra[] = {1,2,-1,1,0,-1,0,0,0,-1,4,-2};
	int aug_2_piv_1_arrb[] = {3, -2, 2};
	int aug_2_piv_1 = findPivotPoint(aug_2, 1);
	assert(aug_2_piv_1 ==  0);
	performRowReduction(aug_2, 
			getRow(aug_2->arr_a, aug_2_piv_1), 
			getCol(aug_2->arr_a, aug_2_piv_1), 1);
	compareMatricesWithArr(aug_2->arr_a, aug_2_piv_1_arra, 12);
	compareMatricesWithArr(aug_2->arr_b, aug_2_piv_1_arrb, 3);
	/*aug_2 = [1 2 -1 1 | 3 ]
	 *        [0 -1 0 0 | -2]
	 *        [0 -1 4 -2| 2 ]*/
	int aug_2_piv_2 = findPivotPoint(aug_2, 2);
	assert(aug_2_piv_2 ==  5);
	/*aug_2 = [1 2 -1 1 | 3 ]
	 *        [0 1 0 0 | -2]
	 *        [0 0 4 -2| 0 ]*/
	int aug_2_piv_2_arra[] = {1,2,-1,1,0,1,0,0,0,0,4,-2};
	int aug_2_piv_2_arrb[] = {3, -2, 0};
	performRowReduction(aug_2, 
			getRow(aug_2->arr_a, aug_2_piv_2), 
			getCol(aug_2->arr_a, aug_2_piv_2), 2);
	compareMatricesWithArr(aug_2->arr_a, aug_2_piv_2_arra, 12);
	compareMatricesWithArr(aug_2->arr_b, aug_2_piv_2_arrb, 3);

	/*aug_3 = [e|b]
	 *aug_3 = [1 2 1| 2 ]
	 *        [3 8 1| 12]
	 *        [0 4 1| 3 ]*/
	int aug_3_piv_1_arr[] = {1,2,1,0,6,-2,0,4,1};
	performGaussianElimination(aug_3);
	compareMatricesWithArr(aug_3->arr_a, aug_3_piv_1_arr, 9);

	/*aug_4 = [g| b]
	 *aug_4 = [0 2 5 6| 3]
	 *        [0 3 0 1| 1]
	 *        [0 3 0 2| 5]*/
	int aug_4_piv_2_arr[] = {0,2,5,6,0,3,0,1,0,0,0,1};
	printmatrix(aug_4->arr_a);
	printmatrix(aug_4->arr_b);
	performGaussianElimination(aug_4);
	compareMatricesWithArr(aug_4->arr_a, aug_4_piv_2_arr, 12);
	printmatrix(aug_4->arr_a);
	printmatrix(aug_4->arr_b);
	

	freeAugmentedMatrix(aug_1);
	freeAugmentedMatrix(aug_2);
	freeAugmentedMatrix(aug_3);
	freeAugmentedMatrix(aug_4);

	freeMatrix(a);
	freeMatrix(b);
	freeMatrix(c);
	freeMatrix(d);
	freeMatrix(e);
	freeMatrix(f);
	freeMatrix(g);
}
