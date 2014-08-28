#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, top;
    int stack[100];
    while (scanf("%d", &n) != EOF)
    {
        top = 0;
        while (n)
        {
            stack[top++] = n % 2;
            n = n / 2;
        }
        top--;
        for (; top >= 0; top--)
        {
            printf("%d", stack[top]);
        }
        printf("\n");
    }
    return 0;
}
