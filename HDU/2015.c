// 偶数求和
#include <stdio.h>

int main(void)
{
    int n,m;
    while (scanf("%d %d",&n,&m) != EOF)
    {
        int q[n], i, sum = 0;
        for (i = 1; i <= n; i++)
        {
            q[i] = i * 2;
            sum += q[i];
            if (i % m == 0)
            {
                printf("%d", sum/m);
                if (i != n)
                    printf(" ");
                sum = 0;
            }
            else if (i == n)
            {
                printf("%d", sum/(n % m));
                sum = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
