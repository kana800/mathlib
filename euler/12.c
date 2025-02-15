/*https://projecteuler.net/problem=12*/
#include <stdio.h>
#include <math.h>
#include "primes.h"

long long int triangleNumber(long long int x)
{
	return (x*(x + 1)) / 2;
}


long long int tau(long long num) {

    if (num == 1) return 1;

    long long int n = num;
    long long int i = 2;
    long long int p = 1;

    for (long int i = 0; i < sqrt(num) ; i++)
    {
	long long int c = 1;
	while ( n % prime_table[i] == 0)
	{
	    n = n / prime_table[i];
	    c++;
	}
	p *= c;
    }

    if (n == num || n > 1) 
	p *= (1 + 1);

    return p;
}

int main(int argc, char **argv)
{
	long long int divisor = 0;
	long long int trianglenum;
	long int c = 0;
	for (long long int i = 1; i <= 1000000; i++)
	{
		trianglenum = triangleNumber(i);
		divisor = tau(trianglenum);
		if (divisor >= 500)
		{
			printf("%ld\n",trianglenum);
			break;
		}
	}
	return 0;
}

