/*test cases for the matrix library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "matrix.h"


int main(int argc, char *argv[]){

	// creating an identity matrix
	matrix* mident = createIdentityMatrix(3);
	// creating a 3x3 matrix
	matrix* m1 = createMatrix(3,3,1,2,3,4,5,6,7,8,9);

	// testing multiplication of matrices
	matrix* c = multiplyMatrix(mident, m1);
	for (int i = 0, j = 0; i < c->size; i++,j++){
		assert(c->matrix[i] == j + 1);
	}

	// freeing the matrices
	freeMatrix(mident);
	freeMatrix(m1);
	freeMatrix(c);


	return 0;
}
