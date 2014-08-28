// 王道机试宝典
// 九度教程第一题
// 排序 
// Bubble sort

#include <stdio.h>

int main(void)
{
    int n;
    int buf[100];
    while (scanf("%d",&n) != EOF)
    {
        // input the number
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&buf[i]);
        }
        // bubble sort
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (buf[j] > buf[j + 1])
                {
                    int tmp = buf[j];
                    buf[j] = buf[j + 1];
                    buf[j + 1] = tmp;
                }                
            }
        }
        // print the buf
        for (int i = 0; i < n; i++)
        {
            printf("%d ",buf[i]);
        }
        printf("\n");
    }
    return 0;
}


