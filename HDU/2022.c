// 海选女主角
#include <stdio.h>

int Abs(int n);

int main(void)
{
    int m,n;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        int folks[m][n], i, j, maxx = 0, maxy = 0;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &folks[i][j]);
                if (Abs(folks[i][j]) > Abs(folks[maxx][maxy]))
                {
                    maxx = i;
                    maxy = j;
                }
            }
        }
        printf("%d %d %d\n", maxx + 1, maxy + 1, folks[maxx][maxy]);
    }
    return 0;
}

int Abs(int n)
{
    return n > 0 ? n : -n;
}
