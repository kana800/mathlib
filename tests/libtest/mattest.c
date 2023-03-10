/*test cases for the matrix library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"


int main(int argc, char *argv[]){
	matrix* m = createIdentityMatrix(4);
	printmatrix(m);
	freeMatrix(m);
	return 0;
}
