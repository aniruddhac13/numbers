/* C program to check prime numbers */

#include "prime.h"


/* Check whether a number is prime or not */
/* Returns 1 if the number is prime otherwise 0 */

int isPrime(int num)
{
    int fact;

    if(num == 0 || num == 1)
        return 0;

    for(fact = 2; fact < num - 1; fact++)
    {
        if(num % fact == 0)
        {
            return 0;
        }
    }

    return 1;
}

