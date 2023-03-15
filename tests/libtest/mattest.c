/*test cases for the matrix library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "matrix.h"

int main(int argc, char *argv[]){

	// testing creation of matrices
	// creating an identity matrix
	matrix* id_3 = createIdentityMatrix(3);
	matrix* id_2 = createIdentityMatrix(2);

	// creating an empty matrix
	matrix* empty = createEmptyMatrix(3, 3);

	// creating a 3x3 matrix
	matrix* m = createMatrix(3,3,1,2,3,4,5,6,7,8,9);

	int arr_3[] = {1,0,0,0,1,0,0,0,1};
	int arr_2[] = {1,0,0,1};
	int arr_4[] = {1,2,3,4,5,6,7,8,9};

	// checking matrix size
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
		assert(id_3->matrix[i] == arr_3[i]);
	}

	for (int i = 0; i < 4; i++){
		assert(id_2->matrix[i] == arr_2[i]);
	}

	for (int i = 0; i < 9; i++){
		assert(empty->matrix[i] == 0);
	}

	for (int i = 0; i < 9; i++){
		assert(m->matrix[i] == arr_4[i]);
	}

	// operations 
	// multiplication
	matrix* c = multiplyMatrix(id_3, m);
	assert(c->size == 9);
	assert(c->rowc == 3);
	assert(c->colc == 3);
	for (int i = 0; i < c->size; i++){
		assert(c->matrix[i] == arr_4[i]);
	}

	// addition
	matrix* d = addMatrix(id_2, id_2);
	assert(d->size == 4);
	assert(d->rowc == 2);
	assert(d->colc == 2);

	for (int i = 0; i < 4; i++){
		assert(d->matrix[i] == arr_2[i] * 2);
	}

	// substraction
	matrix* e = subMatrix(id_2, id_2);
	assert(e->size == 4);
	assert(e->rowc == 2);
	assert(e->colc == 2);

	for (int i = 0; i < 4; i++){
		assert(e->matrix[i] == arr_2[i] * 0);
	}

	// freeing the matrices
	freeMatrix(id_3);
	freeMatrix(id_2);
	freeMatrix(m);
	freeMatrix(c);
	freeMatrix(d);
	freeMatrix(e);


	return 0;
}
