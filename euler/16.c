// https://projecteuler.net/problem=16

#include <stdio.h>
#include <math.h>


// python answer
// ans = sum([sum(i) for i in str(2**1000)])

int main(int argc, char** argv)
{
	long double ans = powl(2,1000);
//	printf("%Lf\n", ans);

	long double sum = 0;
	long double N = ans;

	long double digit = fmodl(N, 10.0);
	
	// double to string
	double x = 1.05;

//	printf("%d\n", (int)digit);
//	digit = fmodl(N, 100.0);
//	printf("%d\n", (int)digit);
//	digit = fmodl(N, 1000.0);
//	printf("%d\n", (int)digit);
//	sum += digit;
	


	return 0;
}
