/*test cases for gauss jordan module*/
#include <stdio.h>

#include "gaussjordan.h"

int main(int argc, char *argv[]){
	matrix* a = createMatrix(3,3,1,2,1,3,8,1,0,4,1);
	matrix* b = createMatrix(3,1,2,12,2);
	matrix* c = createMatrix(3,4,1,2,-1,1,1,1,-1,1,1,1,3,-1,1);
	matrix* d = createMatrix(3,1,3,1,5);

	augmatrix* aug_1 = createAugmentedMatrix(a, b);
	augmatrix* aug_2 = createAugmentedMatrix(c, d);

	int piv_1 = findPivotPoint(aug_1, 1);	
	int piv_2 = findPivotPoint(aug_2, 1);	
	printf("first pivot %d\n",piv_2);

	printmatrix(aug_2->arr_a);
	printmatrix(aug_2->arr_b);


	freeAugmentedMatrix(aug_1);
	freeAugmentedMatrix(aug_2);
	freeMatrix(a);
	freeMatrix(b);
}
