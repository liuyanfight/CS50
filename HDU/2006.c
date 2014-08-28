// 求奇数的乘积

#include <stdio.h>

int main(void)
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        int num[n];
        int im = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&num[i]);
            if (num[i] % 2 == 1)
            {
                im *= num[i];
            }
        }
        printf("%d\n",im);
    }
    return 0;
}
