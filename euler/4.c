/*
 * A palindromic number reads the same both ways. The largest
 * palindrome made from the product of two digit numbers is 9009 = 91 x 99
 * find the largest palindrome made from the product of two 3 digit numbers
 * */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int n)
{
    int temp = n;
    int reverse = 0;
    int lastdigit = 0;
    while (n > 0)
    {
        lastdigit = n % 10;
        reverse = reverse * 10 + lastdigit;
        n /= 10;
    }
    return temp == reverse;
}

int main(int argc, char** argv)
{
    int sum = 0;
    // 3 digit numbers -> 100 - 999 
    for (int i = 999; i >= 100; i--)
    {
        for ( int j = 999; j >= 100; j--)
        {
            sum = i * j;
            if (isPalindrome(sum))
            {
                printf("%dx%d=%d\n",i,j,i*j);
                break; 
            }
        }
    }

    return 0;
}
