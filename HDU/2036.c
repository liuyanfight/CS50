// 改革春风吹满地
#include <stdio.h>

struct node
{
    int x;
    int y;
}point[100];

int main(void)
{
    int n, i;
    double sum;
    while (scanf("%d", &n) != EOF && n != 0)
    {
       for (i = 0; i < n; i++)
       {
            scanf("%d %d", &point[i].x, &point[i].y);
       }
       point[n] = point[0];
       sum = 0;
       for (i = 1; i <= n; i++)
       {
            sum += point[i - 1].x * point[i].y - point[i].x * point[i - 1].y;
       }
       printf("%.1lf\n", sum / 2);
    }
    return 0;
}
