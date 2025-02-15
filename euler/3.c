// The prime factors of 13195 are 5, 7, 13 and 29
// What is the largest prime factor of the number 600851475143
#include <stdio.h>


// every composite number has at least one prime factor 
// less than or equal to its square root
void primefactors(long int n) {
    while (n % 2 == 0) 
    {
        printf("%ld ", 2);
        n = n / 2;
    }

    for (long int i = 3; i*i <= n; i += 2)
    {
        while (n % i == 0)
        {
            printf("%ld ", i);
            n = n / i;
        }
    }

    if (n > 2)
        printf("%ld ", n);
}


// trying out a solution from the thread
// https://projecteuler.net/thread=3#74
// x / 2 is 0 ? ( no add +1 )
// x / 3 is 0 ? ( no add +1 )
void bitRAKEsolution(long int number)
{
	int divisor = 2;
	while (number > 1) {
		if ((number % divisor) == 0) {
			number /= divisor;
			divisor--;
		}
		divisor++;
	}
    printf("\n%d", divisor);
}


int main(int argc, char* argv[])
{
    primefactors(600851475143);
    bitRAKEsolution(600851475143);
    bitRAKEsolution(13195);
    return 0;
}
