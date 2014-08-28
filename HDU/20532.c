#include <stdio.h>

int main(void)
{
    int n, i, j, lamp;
    while (scanf("%d", &n) != EOF)
    {
        lamp = 0;
        for (i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                if (lamp == 0)
                    lamp = 1;
                else
                    lamp = 0;
            }
        }
        printf("%d\n", lamp);
    }
    return 0;
}
