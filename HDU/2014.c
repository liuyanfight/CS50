// 青年歌手大奖赛_评委会打分
#include <stdio.h>

int main(void)
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        int score[n], i,min = 0,max = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d",&score[i]);
            if (score[i] < score[min])
                min = i;
            if (score[i] > score[max])
                max = i;
        }
        double sum = 0;
        for (i = 0; i < n; i++)
        {
            if (i != min && i != max)
                sum += score[i];
        }
        printf("%.2lf\n",sum / (n - 2));
    }
    return 0;
}
