/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 *
 * 1)srand()给rand()提供种子 
 * 2)srand()中的seed一般由时间函数得,eg srand((UINT)GetCurrentTime()) 
     srand( (unsigned)time( NULL ) ) time()函数得到现在的系统时间...等等
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO:If program is not executed with  two or three command-line argument, 
    // the program will complain and exit immediately
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // TODO: convert the first command-line argument(string) to an integer
    int n = atoi(argv[1]);

    // TODO: if there has two arguments,then make the second argument as a seed for function srand.
    // otherwise,the seed will generate  random
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    // TODO: generate 10 random
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }

    // that's all folks
    return 0;
}
