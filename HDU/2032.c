// 杨辉三角
#include <stdio.h>

int main(void)
{
    int n, i, j;
    while (scanf("%d", &n) != EOF)
    {
        int q[n][n];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < i + 1; j++)
            {
                if (j != 0 && j != i)
                    q[i][j] = q[i - 1][j - 1] + q[i - 1][j];
                else
                    q[i][j] = 1;
                if (j != i)
                    printf("%d ", q[i][j]);
                else
                    printf("%d", q[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
