/*test cases for the trignometry library*/
#include "trigtest.h"

void outputdatafile(double (*functpointer)(double),
		double minrange, double maxrange){
	/*summary: outputs a datafile in the 
	 * current directory with the ranges
	 *args:
	 	double (*functpointer)(double) -> 
			function pointer
	 	double minrange -> minimum range
		double maxrange -> maximum range
	*/
	FILE *f1 = fopen("data.csv", "w");
	double step = 0.001;
	for (double i = minrange; i < maxrange; i += step){
		fprintf(f1, "%.3f,%.3f\n",i,functpointer(i));	
	}
}


int main(int argc, char** argv){
	float test_val_1 = roundf(cos_taylor(0.2)) / 100;
	float ans_val_1 = roundf(cos(0.2))/100;
	assert(test_val_1 == ans_val_1);
	printf("cos_taylor = %.4f cos_math = %.4f\n", test_val_1, ans_val_1);
	//outputdatafile(cos_taylor,-5,5);
	return 0;
}
