#include <stdio.h>

int main(void)
{
    int n, i;
    double sum[51] = {0, 3, 6, 6};
    for ( i = 4; i < 51; i ++)
    {
        sum[i] = sum[i - 1] + 2 * sum[i - 2];
    }
    while (scanf("%d", &n) != EOF)
    {
       printf("%.lf\n", sum[n]);
    }
    return 0;
}
