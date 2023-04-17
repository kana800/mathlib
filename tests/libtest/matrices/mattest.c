/*test cases for the matrix library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "matrix.h"
#include "augmatrix.h"


void compareMatrices(matrix* a, matrix* b){
	/*summary: compare matrix a with b
	 *args: matrix * a -> pointer to matrix a
	 	matrix * b -> pointer to matrix b
	 ret:none*/
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


int main(int argc, char *argv[]){

	/* testing creation of matrices 
	 * creating an identity matrix*/
	matrix* id_3 = createIdentityMatrix(3);
	matrix* id_2 = createIdentityMatrix(2);

	/*creating an empty matrix*/
	matrix* empty = createEmptyMatrix(3, 3);

	/*creating a 3x3 matrix */
	matrix* m = createMatrix(3,3,1,2,3,4,5,6,7,8,9);
	matrix* n = createMatrix(3,5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
	
	/*creating an augmented matrix
	 * augmented matrices are struct is supposed
	 * to hold two deep copies of the matrices 
	 * passed to the function;*/
	augmatrix* aug = createAugmentedMatrix(m, n); 
	compareMatrices(m, aug->arr_a);
	compareMatrices(n, aug->arr_b);
	/*
	 * m = [1 2 3] n = [1  2  3  4  5]
	 *     [4 5 6]     [6  7  8  9 10]
	 *     [7 8 9]     [11 12 13 14 15]
	 * aug = [1 2 3 |  1  2  3  4  5]
	 * 	 [4 5 6 |  6  7  8  9 10]
	 * 	 [7 8 9 | 11 12 13 14 15]
	 */

	//addScalarToRow(aug, 2, 2);
	addRow(aug, 1, 2, 2);
	int augrow_a_1 = getIndex(aug->arr_a, 0, 1);
	int augrow_a_2 = getIndex(aug->arr_a, 0, 2);
	/*
	 *       r  1 2 3    4  5  6  7  8
	 * aug = 1 [1 2 3 |  1  2  3  4  5]
	 * 	 2 [4 5 6 |  6  7  8  9 10]
	 * 	 3 [7 8 9 | 11 12 13 14 15]
	 *
	 * after addRow(aug, 1, 2, 2) 
	 *       r  1 2 3    4  5  6  7  8
	 * aug = 1 [1 2 3 |  1   2   3   4  5]
	 * 	 2 [5 7 9 |  7   9  11  14 15]
	 * 	 3 [7 8 9 | 11  12  13  14 15]
	 *
	 */
	for (int i = 0; i < aug->arr_a->colc; i++){
		int element_a = 
			aug->arr_a->arr[augrow_a_2];
		assert(element_a  == m->arr[augrow_a_1] + 
				m->arr[augrow_a_2]);
		augrow_a_2++;
		augrow_a_1++;
	}
	subRow(aug, 1, 2, 2);
	/*
	 * after subRow(aug, 1, 2, 2) 
	 *       r  1 2 3    4  5  6  7  8
	 * aug = 1 [1 2 3   |   1   2   3   4  5]
	 * 	 2 [8 10 12 |  12  14  16  18 20]
	 * 	 3 [7 8 9   |  11  12  13  14 15]
	 *
	 */
	int augrow_a_3 = getIndex(aug->arr_a, 0, 1);
	int augrow_a_4 = getIndex(aug->arr_a, 0, 2);

	for (int i = 0; i < aug->arr_a->colc; i++){
		int element_a = 
			aug->arr_a->arr[augrow_a_4];
		int element_b = 
			aug->arr_a->arr[augrow_a_3];
		printf("%d %d %d\n",element_a, element_b, m->arr[augrow_a_3]);
		//assert(element_a  == m->arr[augrow_a_3] - 
		//		element_b);
		augrow_a_3++;
		augrow_a_4++;
	}
	//printmatrix(aug->arr_b);

	freeAugmentedMatrix(aug);

	int arr_3[] = {1,0,0,0,1,0,0,0,1};
	int arr_2[] = {1,0,0,1};
	int arr_4[] = {1,2,3,4,5,6,7,8,9};

	/*checking matrix size*/
	assert(id_3->size == 9);
	assert(id_3->rowc == 3);
	assert(id_3->colc == 3);

	assert(id_2->size == 4);
	assert(id_2->rowc == 2);
	assert(id_2->colc == 2);

	assert(empty->size == 9);
	assert(empty->rowc == 3);
	assert(empty->colc == 3);

	assert(m->size == 9);
	assert(m->rowc == 3);
	assert(m->colc == 3);

	// checking data in the matrices
	for (int i = 0; i < 9; i++){
		assert(id_3->arr[i] == arr_3[i]);
	}

	for (int i = 0; i < 4; i++){
		assert(id_2->arr[i] == arr_2[i]);
	}

	for (int i = 0; i < 9; i++){
		assert(empty->arr[i] == 0);
	}

	for (int i = 0; i < 9; i++){
		assert(m->arr[i] == arr_4[i]);
	}

	/* matrix operations*/
	/* multiplication*/
	matrix* c = multiplyMatrix(id_3, m);
	assert(c->size == 9);
	assert(c->rowc == 3);
	assert(c->colc == 3);
	for (int i = 0; i < c->size; i++){
		assert(c->arr[i] == arr_4[i]);
	}

	/* addition */
	matrix* d = addMatrix(id_2, id_2);
	assert(d->size == 4);
	assert(d->rowc == 2);
	assert(d->colc == 2);

	for (int i = 0; i < 4; i++){
		assert(d->arr[i] == arr_2[i] * 2);
	}

	/* substraction */
	matrix* e = subMatrix(id_2, id_2);
	assert(e->size == 4);
	assert(e->rowc == 2);
	assert(e->colc == 2);

	for (int i = 0; i < 4; i++){
		assert(e->arr[i] == arr_2[i] * 0);
	}

	/* test cases for the row index */
	// assert (getRowIndex(m,4) == -1);

	// test cases for the col index
	assert (getIndex(m, 1, 1) == 1);
	assert (getIndex(m, 1, 2) == 4);
	assert (getIndex(m, 1, 3) == 7);
	assert (getIndex(m, 2, 1) == 2);
	assert (getIndex(m, 2, 2) == 5);
	assert (getIndex(m, 2, 3) == 8);
	assert (getIndex(m, 3, 1) == 3);
	assert (getIndex(m, 3, 2) == 6);
	assert (getIndex(m, 3, 3) == 9);

	// permutation matrices
	int id_1[] = {1,0,0,0,0,1,0,1,0};
	matrix* p = getPermutation(3, 2, 3);
	for (int i = 0; i < p->size; i++){
		assert(p->arr[i] == id_1[i]);
	}
	
	matrix* pm = multiplyMatrix(p,m);

	// testing deepCopyMatrixes
	matrix* jj = createEmptyMatrix(m->rowc,m->colc); 
	copyMatrix(m, jj);
	
	for (int i = 0; i < m->size; i++){
		assert(m->arr[i] == jj->arr[i]);	
	}



	// freeing the matrices
	freeMatrix(id_3);
	freeMatrix(id_2);
	freeMatrix(m);
	freeMatrix(c);
	freeMatrix(d);
	freeMatrix(e);
	freeMatrix(pm);
	freeMatrix(jj);


	return 0;
}
