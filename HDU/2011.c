#include <stdio.h>
#include <math.h>

int main(void)
{
   int m;
   scanf("%d",&m);
   int i,n,a,j;
   double sum;
   for (i = 1; i <= m; i++)
   {
        scanf("%d",&n);
        a = 1;sum = 0;
        for (j = 1; j <= n; j++)
        {
            sum = sum + (j % 2 == 1 ? 1 : -1)*(double) 1/ (a++);
        }
        printf("%.2lf\n",sum);
   }
   return 0; 
}
