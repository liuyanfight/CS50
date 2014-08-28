// Lowest Common Multiple Plus
//  注意算法
#include <stdio.h>

int LCM(int a, int b);
int GCD(int a, int b);

int main(void)
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        int i, num[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        for (i = 1; i < n; i++)
        {
           num[i] = LCM(num[i - 1],num[i]);
        }
        printf("%d\n",num[n - 1]);
    }
    return 0;
}
/* Lowest Common Multiple */
int LCM(int a, int b)
{
    /* 注意注意***：a*b可能超过int类型 */
    return a / GCD(a, b) * b ;
}
/* greatest common divisor */
int GCD(int a, int b)
{
     int c = a % b;
     while (c != 0)
     {
        a = b;
        b = c;
        c = a % b;
     }
     return b;
}
