// 平方和与立方和

#include <stdio.h>

int main(void)
{
    int m,n;
    while (scanf("%d %d",&m,&n) != EOF)
    {
        int i;
        if(n<m)
		{
			i=n;n=m;m=i;
		}
        int x = 0,y = 0;
        for (; m <= n; m++)
        {
            if (m % 2 == 0)
            {
                x += m*m;
            }
            else
            {
                y += m*m*m;
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
