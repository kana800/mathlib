/*test cases for gauss jordan module*/
#include <stdio.h>

#include "gaussjordan.h"

int main(int argc, char *argv[]){
	matrix* a = createMatrix(3,3,1,2,1,3,8,1,0,4,1);
	matrix* b = createMatrix(3,1,2,12,2);
	matrix* c = createMatrix(3,3,0,2,1,0,8,1,0,4,1);

	augmatrix* aug = createAugmentedMatrix(c, b);



	int piv = findPivotPoint(aug, 1);	
	printf("first pivot %d",piv);


	freeAugmentedMatrix(aug);
	freeMatrix(a);
	freeMatrix(b);
}
