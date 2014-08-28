// 超级楼梯
#include <stdio.h>

/*int f(int n);*/

int main(void)
{
    int N, M, i;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &M);
        int sum[M + 1];
        for (i = 1; i <= M; i++)
        {
            if (i == 1)
                sum[i] = 0;
            else if (i == 2)
                sum[i] = 1;
            else if (i == 3)
                sum[i] = 2;
            else
                sum[i] = sum[i - 1] + sum[i - 2];
        }
        printf("%d\n", sum[M]);
    }
    return 0;
}

/*int f(int n)*/
/*{*/
/*    if (n == 1)*/
/*    {*/
/*        return 0;*/
/*    }*/
/*    else if (n == 2)*/
/*    {*/
/*        return 1;*/
/*    } if (n == 3)*/
/*    {*/
/*        return 2;*/
/*    }*/
/*    else*/
/*    {*/
/*        return f(n - 1) + f(n - 2);*/
/*    }*/
/*}*/
