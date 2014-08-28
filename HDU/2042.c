#include <stdio.h>

int main(void)
{
    int N, a, i;
    int sum[31];
    for (i = 0; i < 31; i++)
    {
        if(i == 0)
            sum[i] = 3;
        else
            sum[i] = (sum[i - 1] - 1) * 2;
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &a);
        printf("%d\n", sum[a]);
    }
    return 0;
}

