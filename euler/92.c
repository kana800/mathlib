#include <stdio.h>


long int returnSqDigitSum(long int n)
{
	int lastdigit = 0;
	long int sqsum = 0;

	if (n <= 9) 
	{
		return n * n; 
	}

	while (n > 0)
	{
		lastdigit = n % 10;
		n = n / 10;
		sqsum += (lastdigit * lastdigit);
	}
	return sqsum;
}


int main(int argc, char** argv)
{
	long int starting_num = 0;
	for (long int i = 1; i <= 10000000; i++)
	{
		long int sqsum = returnSqDigitSum(i);
		while (1) 
		{
			if ((sqsum == 89) || (sqsum == 1)) 
			{
				if (sqsum == 89) 
				{
					starting_num += 1; 
				}
				break;
			}
			sqsum = returnSqDigitSum(sqsum);
		}
	}
	printf("%ld\n", starting_num);
}
