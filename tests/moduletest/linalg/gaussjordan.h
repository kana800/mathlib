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
			"Given Row Is Greater \
			Than Rows in Matrix");
		return -1;
	}

	int i, index;
	bool foundPivot = false;
	for (i = piv; i <= a->arr_a->rowc; i++) {	
		index = getIndex(a->arr_a, i, piv);
		printf("i: %d piv %d %d %d\n",i,piv, index, a->arr_a->arr[index]);
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
		return piv;
	}
	return -1;
}


#endif // !GAUSS_H
