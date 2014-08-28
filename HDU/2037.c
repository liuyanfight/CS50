// 今年暑假不AC。贪心算法入门题目
#include <stdio.h>

int main(void)
{
    int n, i, cnt, time;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        // 输入节目表，并分别将开始和结束时间存入对应数组
        int Ti_s[n], Ti_e[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &Ti_s[i], &Ti_e[i]);
        }
        // 将时间表按照结束时间的先后顺序排序
        int flag = 1;
        while (flag == 1)
        {
            flag = 0;
            for (i = 1; i < n; i++)
            {
                if (Ti_e[i - 1] > Ti_e[i])
                {
                    int tmp = Ti_e[i];
                    Ti_e[i] = Ti_e[i - 1];
                    Ti_e[i - 1] = tmp;
                    
                    flag = 1;
                    
                    tmp = Ti_s[i];
                    Ti_s[i] = Ti_s[i - 1];
                    Ti_s[i - 1] = tmp;
                }
            }
        }
        // 贪心算法主要实现部分，一步一步的向后选择
        // 下一个的开始时间必须要小于等于上个节目的结束时间
        cnt = 0; time = 0;
        for (i = 0; i < n; i++)     
        {
            if (Ti_s[i] >= time)
            {
                cnt++;// 计数器
                time = Ti_e[i];
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

