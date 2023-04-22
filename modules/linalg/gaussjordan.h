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

int findPivotPoint(augmatrix* a, int piv){
	/*summary: find the optimal 
	 * pivot point in an augmented matrix
	 * in the provided pivot position;
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
	for (i = piv; i <= a->arr_a->rowc; i++) {	
		index = getIndex(a->arr_a, i, piv);
		// pivot cannot be zero; we need to keep
		// traversing till we find the pivot
		if (a->arr_a->arr[index] != 0){
			break;
		} 
	}

	/*if the row and column values arent equal 
	 * then we need to some permutations and 
	 * switch the rows accordingly*/



	// whole column is zero
	return -1;
}


#endif // !GAUSS_H
