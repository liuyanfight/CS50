#include <stdio.h>

int main(void)
{
    int n, i, a;
    double sum[21] = {0, 0, 1, 2};
    double aii[21] = {0, 1, 2};
    for (i = 3; i < 21; i++)
    {
        aii[i] = aii[i - 1] * i;
        sum[i] = (i - 1) * (sum[i - 1] + sum[i - 2]);
    }
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        printf("%.2lf%%\n", sum[a] * 100 / aii[a]);
    }
    return 0;
}
