/*test cases for the matrix library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"


int main(int argc, char *argv[]){
	matrix* m = createIdentityMatrix(3);
	matrix* i4 = createIdentityMatrix(4);
	printmatrix(m);
	
	matrix* m2 = createMatrix(3,3,1,2,3,4,5,6,7,8,9);
	matrix* m4 = createMatrix(4,4,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
	printmatrix(m2);
	
	matrix* m5 = multiplyMatrix(i4, m4);
	printmatrix(m5);

	freeMatrix(m);
	freeMatrix(m2);
	freeMatrix(m4);


	return 0;
}
