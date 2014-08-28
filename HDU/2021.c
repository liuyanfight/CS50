// 发工资咯：）
#include <stdio.h>

int count(int n);

int main(void)
{
    int n, i;
    while (scanf("%d",&n) != EOF && n != 0)
    {
        int money[n], sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d",&money[i]);
            sum += count(money[i]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
int count(int n)
{
    int cnt = 0;
    while (n >= 100)
    {
        cnt++;
        n = n - 100;
    }
    while (n >= 50)
    {
        cnt++;
        n = n - 50;
    }
    while (n >= 10)
    {
        cnt++;
        n = n - 10;
    }
    while (n >= 5)
    {
        cnt++;
        n = n - 5;
    }
    while (n >= 2)
    {
        cnt++;
        n = n - 2;
    }
    while (n >= 1)
    {
        cnt++;
        n = n - 1;
    }
    return cnt;
}
