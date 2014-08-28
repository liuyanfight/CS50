// 九度教程第六题
// 日期差值

#include <stdio.h>
// 定义宏判断是否是闰年，方便计算每月天数
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
// 预存每月的天数，注意二月配合宏定义作特殊处理
int dayOfMonth[13][2] = {0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};
// 日期类，方便日期的推移
struct Date
{
    int Day;
    int Month;
    int Year;
};
// 计算下一天的日期
void nextDay(struct Date tmp)
{
    tmp.Day++;
    // 若日期超过了当月最大天数
    if (tmp.Day > dayOfMonth[tmp.Month][ISYEAP(tmp.Year)])
    {
        tmp.Day = 1;
        tmp.Month++;
        if (tmp.Month > 12)
        {
            tmp.Month =1;
            tmp.Year++;
        }
    }
}
// 保存预处理的天数
int buf[5001][13][32];
// 求绝对值
int Abs(int x)
{
    return x < 0 ? -x : x;
}
void count()
{
    struct Date tmp;
    // 天数
    int cnt = 0;
    // 初始化日期类对象为0年1月1日
    tmp.Day = 1;
    tmp.Month = 1;
    tmp.Year = 0;
    while (tmp.Year != 5001)
    {
        // 将该日与0年1月1日的天数差保存起来
        buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
        // 计算下一天日期
        tmp.Day++;
        // 若日期超过了当月最大天数
        if (tmp.Day > dayOfMonth[tmp.Month][ISYEAP(tmp.Year)])
        {
            tmp.Day = 1;
            tmp.Month++;
            if (tmp.Month > 12)
            {
                tmp.Month =1;
            tmp.Year++;
            }
        }
        cnt++;        
    }
}
int main(void)
{
    count();
    int d1,m1,y1;
    int d2,m2,y2;
    while (scanf("%4d%2d%2d",&y1,&m1,&d1) != EOF)
    {
        scanf("%4d%2d%2d",&y2,&m2,&d2);
        printf("%d\n",Abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1);
    }
    return 0;
}
