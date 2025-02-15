// https://projecteuler.net/problem=9
#include <stdio.h>
	

int main(int argc, char **argv)
{
	for ( int a = 1; a <= 1000; a++)
	{
		for ( int b = 1; b <= 1000; b++)
		{
			for ( int c = 1; c <= 1000; c++)
			{
				if ((a*a) + (b*b) == (c*c))
				{
//					printf("%d^2 + %d^2 == %d^2\n", a,b,c);
					if ( a + b + c == 1000)
					printf("%d + %d == %d (%d)\n", a,b,c, a*b*c);

				}
			}
		}
	}

	// from pier https://projecteuler.net/thread=9#284
	//a= 2mn; b= m^2 -n^2; c= m^2 + n^2;
	//a + b + c = 1000;
	//2mn + (m^2 -n^2) + (m^2 + n^2) = 1000;
	//2mn + 2m^2 = 1000;
	//2m(m+n) = 1000;
	//m(m+n) = 500;
	//m>n;
	//m= 20; n= 5;
	//a= 200; b= 375; c= 425;

	return 0;
}

