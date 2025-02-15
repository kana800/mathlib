/*https://projecteuler.net/problem=6*/

#include <stdio.h>

int main(int argc, char **argv)
{

    long int sq_sum = 0;
    long int sum = 0;

    for ( int i = 1; i <= 100; i++)
    {
        sq_sum += (i * i);
        sum += i;
    }

    printf("sum of squares %ld\n", sq_sum);
    printf("square of the sum %ld\n", sum * sum);
    printf("difference %ld\n", (sum*sum) - sq_sum);

    return 0;
}
