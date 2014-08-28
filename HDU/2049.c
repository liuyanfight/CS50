#include <stdio.h>

int main(void)
{
    int n, i, a, b;
    _int64 sum[21] = {0, 0, 1, 2}, s;
    _int64 aii[21] = {1, 1, 2};
    for (i = 3; i < 21; i++)
    {
        aii[i] = aii[i - 1] * i;
        sum[i] = (i - 1) * (sum[i - 1] + sum[i - 2]);
    }
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &a, &b);
        s = sum[b] *(aii[a] / (aii[b] * aii[a - b]));
        printf("%I64d\n", s);
    }
    return 0;
}
