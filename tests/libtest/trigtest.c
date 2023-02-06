/*test cases for the trignometry library*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>

#include "../../lib/trig.h"



void outputdatafile(double minrange, double maxrange){
	/*summary: outputs a datafile in the 
	 * current directory with the ranges
	 *args:
	 	double minrange -> minimum range
		double maxrange -> maximum range
	*/
	FILE *f1 = fopen("mathlib.csv", "w");
	FILE *f2 = fopen("math_h.csv", "w");
	double step = 0.001;
	for (double i = minrange; i < maxrange; i += step){
		fprintf(f1, "%.3f,%.3f\n",i,cos_taylor(i));	
		fprintf(f2, "%.3f,%.3f\n",i,cos(i));	
	}
}


int main(int argc, char** argv){
	float test_val_1 = roundf(cos_taylor(0.2)) / 100;
	float ans_val_1 = roundf(cos(0.2))/100;
	assert(test_val_1 == ans_val_1);
	printf("cos_taylor = %.4f cos_math = %.4f\n", test_val_1, ans_val_1);
	outputdatafile(-5,5);
	return 0;
}

