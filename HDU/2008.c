// 数值统计
#include <stdio.h>

int main(void)
{
    int n;
    while (scanf("%d",&n) != EOF && n != 0)
    {
        double nums[n];
        int i,a=0,b=0,c=0;
        for (i = 0; i < n; i++)
        {
            scanf("%lf",&nums[i]);
            if (nums[i] < 0)
                a++;
            else if (nums[i] == 0)
                b++;
            else
                c++;
        }
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
