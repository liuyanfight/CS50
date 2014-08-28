#include <stdio.h>

int main(void)
{
    int N, a, b, i;
    double sum[50] = {0, 1, 2};
    for (i = 3; i < 50; i ++)
    {
        sum[i] = sum[i - 1] + sum[i - 2];
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &a, &b);
        printf("%.lf\n", sum[b - a]);
    }
    return 0;
}
