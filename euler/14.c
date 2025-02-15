// https://projecteuler.net/problem=14
#include <stdio.h>



long int chainZ(long int n)
{
	int chaincount = 0;
	while (n > 1)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
		} 
		else 
		{
			n = 3 * n + 1;
		}
		chaincount++;
	}
	return chaincount;
}

// n = n / 2 when n is even
// n = 3n + 1 when n is odd
int main(int argc, char** argv[])
{
	int max = 0;
	int temp = 0;
	int c = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		temp = chainZ(i);
//		printf("%d -> %d\n",i,temp);
		if (temp > max) { 
			max = temp;
			c = i;
		}
	}
	printf("%d",c);

	return 0;
}
