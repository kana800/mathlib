/*test cases for gauss jordan module*/
#include <assert.h>
#include <stdio.h>

#include "gaussjordan.h"
#include "matrix.h"

int main(int argc, char *argv[]){
	/*gaussjordan.h*/

	/* creating matrices 
	 * a = [1 2 1]
	 *     [3 8 1]
	 *     [0 4 1]*/
	matrix* a = createMatrix(3,3,1,2,1,3,8,1,0,4,1);
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
	matrix* g = createMatrix(3,4,3,0,5,6,0,3,0,1,0,3,0,2);



	/*aug_1 = [a|b]
	 *aug_1 = [1 2 1 | 2 ]
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
	/*aug_4 = [0 2 5 6| 3]
	 *        [0 3 0 1| 1]
	 *        [0 3 0 2| 5]*/
	augmatrix* aug_4 = createAugmentedMatrix(e, b);

	/*tests for findPivotPoint(augmatrix* a, piv)*/
	/*aug_1 = [1 2 1 | 2 ] <- piv (1)
	 *        [3 8 1 | 12]
	 *        [0 4 1 | 2 ]*/
	assert(findPivotPoint(aug_1, 1) ==  1);
	performRowReduction(aug_1, 1, 1, 1);
	/*aug_1 = [1 2 1 | 2 ] <- piv (1)
	 *        [0 2 -2| 12]    [3 8 1] - 3[1 2 1] = [0 2 -2]
	 *        [0 4 1 | 2 ]*/
	assert(findPivotPoint(aug_1, 2) ==  2);
	performRowReduction(aug_1, 2, 2, 2);
	/*aug_1 = [1 2 1 | 2 ] 
	 *        [0 2 -2| 12] <- piv (2)
	 *        [0 4 1 | 2 ] [0 4 1] -  2[0 2 -2] = [0 0 5]*/
	performRowReduction(aug_1, 2, 3, 3);

	/*aug_2 = [c|d]
	 *aug_2 = [1 2 -1 1 | 3]
	 *        [1 1 -1 1 | 1]
	 *        [1 1 3 -1 | 5]*/
	assert(findPivotPoint(aug_2, 1) ==  1);
	printf("%d %d\n",
		getRow(aug_2->arr_a, 1), 
		getCol(aug_2->arr_a, 1));
	performRowReduction(aug_2, 
			getRow(aug_2->arr_a, 1), 
			getCol(aug_2->arr_a, 1), 1);
	printmatrix(aug_2->arr_a);
	performRowReduction(aug_2, 
			getRow(aug_2->arr_a, 1), 
			getCol(aug_2->arr_a, 1), 1);
	printmatrix(aug_2->arr_a);
	printf("%d %d\n",getRow(aug_2->arr_a, 1), 
			getCol(aug_2->arr_a, 1));
	performRowReduction(aug_2, 
			getRow(aug_2->arr_a, 2), 
			getCol(aug_2->arr_a, 2), 1);
	printmatrix(aug_2->arr_a);
	
	//int piv_1 = findPivotPoint(aug_1, 1);	
	//int piv_2 = findPivotPoint(aug_2, 1);	

	//printmatrix(aug_3->arr_a);
	//printmatrix(aug_3->arr_b);
	//int piv_3 = findPivotPoint(aug_3, 2);
	//printmatrix(aug_1->arr_a);
	//printmatrix(aug_1->arr_b);

	//performRowReduction(aug_1, 1, 1, 1);

	//printmatrix(aug_1->arr_a);
	//printmatrix(aug_1->arr_b);
	//performRowReduction(aug_1, 2, 2, 2);

	//printmatrix(aug_1->arr_a);
	//printmatrix(aug_1->arr_b);

	//freeAugmentedMatrix(aug_1);
	//freeAugmentedMatrix(aug_2);

	freeMatrix(a);
	freeMatrix(b);
	freeMatrix(c);
	freeMatrix(d);
	freeMatrix(e);
	freeMatrix(f);
	freeMatrix(g);
}
