#include <stdio.h>
#include <stdlib.h>
int cmp (const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        n--;
        int folks[n],flag = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &folks[i]);
            if (--folks[i] < 0)
            {
                flag = 1;
            }
        }
        qsort(folks, n, sizeof(folks[0]), cmp);
        while (folks[0] > 0)
        {
            int k = 1;
            for (int j = folks[0]; j > 0; j--)
            {
                if (k < n)
                    folks[k++]--;
                else
                    flag = 1;
            }
            folks[0] = 0;  
            qsort(folks, n, sizeof(folks[0]), cmp);
        }
        for (int i = 0; i < n; i++)
        {
            if (folks[i] != 0)
                flag = 1;
        }
        if (flag == 1)
            printf("Lie absoulutely\n");
        else
            printf("Maybe truth\n");
    }
    return 0;
}
