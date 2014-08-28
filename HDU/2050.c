#include <stdio.h>

int main(void)
{
    int C, n, i;
    scanf("%d", &C);
    while (C--)
    {
        scanf("%d", &n);
        int sum[n + 1];        
        for (i = 1; i<= n; i++)
        {
            if (i == 1)
                sum[i] = 2;
            else if (i == 2)
                sum[i] = 7;
            else
                sum[i] = sum[i - 1] + 4 * (i - 1) + 1;
        }
        printf("%d\n", sum[n]);
    }
    return 0;
}
