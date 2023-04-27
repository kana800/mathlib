/*gaussjordan.h - v1.0 
 NOTES 
 	This version of gaussjordan elimination
 	is not optimized at all. Currently I am traversing
 	through the whole matrix to find optimal pivot 
 	points of the matrix;
 */
#ifndef GAUSS_H
#define GAUSS_H

#include "matrix.h"
#include "augmatrix.h"
#include <stdbool.h>
#include <stdio.h>


int findPivotPoint(augmatrix* a, int piv){
	/*summary: find the optimal 
	 * pivot point in an augmented matrix
	 * in the provided pivot position;
	 * rows will be swapped inplace if 
	 * needed
	 *args: augmatrix* a -> pointer to a 
	 	augmented matrix 
		int pivot -> pivot position
			** starts with 1
	 *example:
	 *piv-> 1 2 3
	 * m = [1 2 3]
	 *     [4 5 6]
	 *     [7 8 9]
	 *ret: int -> index of the row*/
	if (piv > a->arr_a->colc){
		fprintf(stderr, 
			"Given Pivot Is Greater \
			Than Column in Matrix");
		return -1;
	}

	int i, index;
	bool foundPivot = false;
	for (i = piv; i <= a->arr_a->rowc; i++) {	
		index = getIndex(a->arr_a, i, piv);
		// pivot cannot be zero; we need to keep
		// traversing till we find the pivot
		if (a->arr_a->arr[index] != 0){
			foundPivot = true;
			break;
		} 
	}
	// whole column is zero
	if (!foundPivot) return -1;

	/*if the row and column values arent equal 
	 * then we need to some permutations and 
	 * switch the rows accordingly*/
	if (piv != i){
		swapRows(a->arr_a, i, piv);
		swapRows(a->arr_b, i, piv);
	}
	return piv;
}

void performRowReduction(augmatrix* a, int piv){
	/*summary: performs row reduction to
	 * each row in the matrix to get the 
	 * zero in the pivot columns 
	 *args: augmatrix*a -> pointer to aug matrix 
	 	int piv -> pivot column 
	 *example: 
	 *piv-> 1 2 3  piv = 1
	 * m = [1 2 3]
	 *     [4 5 6]
	 *     [1 8 9]
	 *after performRowReduction(a, 1);
	 *piv-> 1 2 3
	 * m = [1  2  3]
	 *     [0 -3 -6] -> r2 - (r1 * 4)
	 *     [0  6  6] -> r3 - r1
	 *ret: NIL*/

	if (piv > a->arr_a->colc){
		fprintf(stderr, 
			"Given Pivot Is Greater \
			Than Column in Matrix");
		return;
	}
	int i,index;
	int pivotvalue = getIndex(a->arr_a, piv, piv);
	for (i = piv; i <= a->arr_a->rowc; i++) {	
		index = getIndex(a->arr_a, i, piv);
		int indexvalue = a->arr_a->arr[index];
		printf("index value %d\n", indexvalue);
	}

}

#endif // !GAUSS_H
