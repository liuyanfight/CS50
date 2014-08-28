// 第几天？

#include <stdio.h>
#define ISLEAP(x) (x%4==0 && x%100!=0) || (x%400 ==0) ? 1:0

int main(void)
{
    int year,month,day;
    int months[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
                       {31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    while (scanf("%4d/%2d/%2d",&year,&month,&day) != EOF)
    {
        int cnt = 0,i;
        int y = ISLEAP(year);
        for (i = 1;i < month;i++)
        {
            cnt += months[i][y];
        }
        cnt += day;
        printf("%d\n",cnt);
    }
    return 0;
}
