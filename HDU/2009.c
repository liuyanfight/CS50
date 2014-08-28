// 求数列的和
#include <stdio.h>
#include <math.h>

int main(void)
{
    double n,m;
    while (scanf("%lf %lf",&n,&m) != EOF && n < 10000 && m < 1000)
    {
        int i;
        double sum = n;
        for (i = 1; i < m; i++)
        {
            n = sqrt(n);
            sum += n;
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
