// 亲和数
#include <stdio.h>

int main(void)
{
    int M, i, A, B, sum1, sum2;
    scanf("%d", &M);
    while (M--)
    {
        scanf("%d %d", &A, &B);
        sum1 = 0; sum2 = 0;
        for (i = 1; i <= A / 2; i++)
        {
            if (A % i == 0)
                sum1 += i;
        }
        for (i = 1; i <= B / 2; i++)
        {
            if (B % i == 0)
                sum2 += i;
        }
        if (sum1 == B && sum2 == A)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
