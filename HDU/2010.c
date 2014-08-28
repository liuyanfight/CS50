// 水仙花数 Wrong answer
#include <stdio.h>
#include <math.h>

int main(void)
{
    int m,n;
    while (scanf("%d %d",&m,&n) != EOF  && 100 <= m && m <= n && n <=999) 
    {
        int i = 0;
        for (; m <= n; m++)
        {
            int f= 0;
            int num = m;
            while (num != 0)
            {
                f += pow(num % 10,3);
                num = num / 10;
            }
/*	        s1=i/100;*/
/*			s2=i%100/10;*/
/*			s3=i%100%10;*/
/*            f = pow(s1,3)+pow(s2,3)+pow(s3,3);*/
            if (f == m)
            {
                if (i == 1) 
                    printf(" ");
                printf("%d",m);
                i = 1;
            }
        }
        if (i == 0)
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}
