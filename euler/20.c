// https://projecteuler.net/problem=20
#include <stdio.h>
#include <assert.h>


long long int getFactorial(int d)
{
	long long int sum = 1;
	for (int i = d; i >= 1; i--)
	{
		sum = sum * i;
		printf("%d x %ld\n", i, sum);
	}
	return sum;
}

int main(int argc, char** argv)
{
	long long int fact = getFactorial(100);
	
	printf("100! is %d\n",fact);

	int digit = 0;
	int digitsum = 0;

	while ( fact > 0 )
	{
		digit = fact % 10;
		fact /= 10;
		digitsum += digit;
	}

	printf("sum of the digits %ld\n",digitsum);

	return 0;
}
