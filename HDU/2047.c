#include <stdio.h>

int main(void)
{
    int n, i;
    long double sum[41] = {0, 3, 8};
    for ( i = 3; i < 41; i ++)
    {
        sum[i] = 2 * sum[i - 1] + 2 * sum[i - 2];
    }
    while (scanf("%d", &n) != EOF)
    {
       printf("%.Lf\n", sum[n]);
    }
    return 0;
}
