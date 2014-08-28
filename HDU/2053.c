#include <stdio.h>

int main(void)
{
    int n, i, j;
    while (scanf("%d", &n) != EOF)
    {
        j = 0;
        for (i = 1; i <= n; i++)
        {
            if (n % i == 0)
                j++;
        }
        printf("%d\n", j % 2);
    }
    return 0;
}
