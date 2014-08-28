#include <stdio.h>

int main(void)
{
    int n, m;
    while (scanf("%d %d",&n, &m) != EOF)
    {
        int grade[n][m], i, j, num = 0;
        double stuave[n], couave[m], sumcou = 0, sumstu = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%d", &grade[i][j]);
                sumcou += grade[i][j];
            }
            stuave[i] = sumcou / m;
            sumcou = 0;
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                sumstu += grade[j][i];
            }
            couave[i] = sumstu / n;
            sumstu = 0;
        }
        for (i = 0; i < n; i++)
        {
            int cnt = 0;
            for (j = 0; j < m; j++)
            {
                if (grade[i][j] >= couave[j])
                    ++cnt;
            }
            if (cnt == m)
                ++num;
            if (i != n - 1)
                printf("%.2lf ", stuave[i]);
            else
                printf("%.2lf\n", stuave[i]);
        }
        for (i = 0; i < m; i++)
        {
            if (i != m - 1)
                printf("%.2lf ", couave[i]);
            else
                printf("%.2lf\n", couave[i]);
        }
        // !!!空两行
        printf("%d\n\n",num);
    }
    return 0;
}
