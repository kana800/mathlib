// 2520 is the smallest number that can be divided by each of
// numbers from 1 to 10 without any remainders
// what is the smallest positive number that is evenly divisible
// from 1 to 20
#include <stdio.h>
#include <stdbool.h>


int main(int argc, char** argv)
{
    bool a = true;

    for (long int i = 1; i <= 100000000000; i++)
    {
        for (long int j = 1; j <= 20; j++)
        {
            if (((20 * i) % j ) != 0) 
            {
                a = false;
                break;
            } else {
                a = true;
            }
        }
        if (a) printf("%ld\n",20*i);
    }
}
