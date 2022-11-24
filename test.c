/* C program to check prime number functionality */

#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(int argc, char *argv[])
{
    FILE *inf = NULL, *outf = NULL;
    int status = 0, num[5], res[5], ares[5];
    
    if(argc < 2)
    {
        printf("Usage: %s input.txt expout.txt\n", argv[0]);   
    }
    
    inf = fopen(argv[1], "r");
    if(!inf)
    {
        printf("Test input missing\n");
    }
    
    outf = fopen(argv[2], "r");
    if(!inf)
    {
        printf("Test expected output missing\n");
    }

    for(int idx = 0; idx < 5; idx++)
    {
        fscanf(inf, "%d", &num[idx]);
        fscanf(outf, "%d", &res[idx]);

        ares[idx] = isPrime(num[idx]);
        if(ares[idx])
        {
            printf("%d is a Prime number\n", num[idx]);
        }
        else
        {
            printf("%d is not a Prime number\n", num[idx]);
        }
        if(ares[idx] == res[idx])
        {
            printf("Test passed\n");
        }
        else
        {
            printf("Test failed\n");
            status = -1;
        }
    }
    
    if(inf)
    {
        fclose(inf);
    }
    
    if(outf)
    {
        fclose(outf);
    }
    
    exit(status);
    
}

