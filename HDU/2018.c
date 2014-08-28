/* 母牛的故事
   解题思路：
  １理解题意!出生的小母牛每活三年就能再生新的小母牛了。
　 ２f(1)＝1 f(2)=2 f(3)=3 f(4)=4 f(5)=6当第n年的时候，所有的牛应该有　第n-1年的牛+第n-3年的年（都能生），
　　推出f(n)=f(n-1)+f(n-3)
*/
#include <stdio.h>

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        int sum[n];
        int i;
        for (i = 1; i <= n; i++)
        {
            if (i < 4)
                sum[i] = i;
            else 
                sum[i] = sum[i - 1] + sum[i - 3];
        }
        printf("%d\n",sum[i - 1]);
    }
    return 0;
}
