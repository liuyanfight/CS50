// 素数判定
#include <stdio.h>
#include <math.h>

int main(void)
{
    int x, y;
    while (scanf("%d %d",&x,&y) != EOF && (x != 0 || y != 0))
    {
        int i = 0;
        for (; x <= y; x++)
        {
            int m = sqrt(x * x + x + 41);
            int j;
            for (j = 2; j <= m;j++)
            {
                if ((x * x + x + 41) % j == 0)
                    i++;
            }
        }
        if (i == 0)
        {
            printf("OK\n");
        }
        else
            printf("Sorry\n");
    }
    return 0;
}
