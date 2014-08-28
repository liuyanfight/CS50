// 计算球体积

#include <stdio.h>
#include <math.h>
#define PI 3.1415927

int main(void)
{
    double r;
    while (scanf("%lf", &r) != EOF)
    {
        double v = 4 * PI /3 * pow(r, 3);
        printf("%.3lf\n", v);
    }
    return 0;
}
