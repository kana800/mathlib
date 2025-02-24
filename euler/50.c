#include <stdio.h>
#include "primes.h"

int main(int argc, char** argv)
{
	long int size = sizeof(prime_table)/sizeof(long int);
	int max = 0;
	int prime = 0;
	int j = 0;

	for (int i = 0; i <= size; i++)
	{
		if (prime_table[i] >= 1000000) break;
		long int sum = 0;
		for (;j <= i; j++)
		{
			sum += prime_table[j];
			if (sum == prime_table[i])
			{
				break;
			}
		}
		if (i == (j - 1)) j = 0;
		if ((j + 1) > max) { 
//			printf("max %d %d\n", max, prime);
			prime = prime_table[i];
			max = j + 1;
		}
		j = 0;
	}
	printf("max %d %d", max, prime);

	return 0;
}
