// https://projecteuler.net/problem=10
#include <stdio.h>
#include "primes.h"

int main(int argc, char **argv)
{
	int len = sizeof(prime_table) / sizeof(long int);
	long int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += prime_table[i];
	}
	printf("sum %ld", sum);
	return 0;
}

