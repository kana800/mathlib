// Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
// By starting with 1 and 2, 
// the first 10 terms will be: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// By considering the terms in the Fibonacci sequence whose values 
// do not exceed four million, find the sum of the even-valued terms.
#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define LIMIT 4000000

int fib(int n) {

	int a = 0;
	int b = 1;
	int c = 0;
	int i = 1;

	while (i <= n) 
	{
		c = a + b;
		a = b;
		b = c;

		i++;
	}

	return c;
}

int main(int argc, char *argv[])
{
	int n = 2;
	int fb = 0;
	int sum = 0;

	while (true) 
	{
		fb = fib(n);
		if (fb > LIMIT) break;

		if (fb % 2 == 0) sum += fb;

		n++;
	}

	fprintf(stdout, 
			"sum of the even-valued terms %d ", sum);

	return EXIT_SUCCESS;
}
