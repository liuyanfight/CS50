/*******************************************
This is CS50.
Pset1 standard edition (2)
找零钱，用贪婪算法，最后算出找零的硬币数。
在这只有四种硬币quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).输入为$.
建一个文件greedy.c.示例如下：
jharvard@appliance (~/Dropbox/pset1): ./greedy
O hai!  How much change is owed?
0.41
4

PS：这题我可遇上了大麻烦
如果你用了float，那么你可以用round函数~
*********************************************/
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float moneys;
    printf("O hai!   How much change is owed?\n");
    moneys = GetFloat();
    while(moneys < 0)
    {
        printf("How much change is owed?\n");
        moneys = GetFloat();
    }
    const int quarters = 25;
    const int  dimes =10;
    const int nickels = 5;
    const int pennies = 1;
    int num = 0;
    int money=(int) round((moneys) * 100);
    while(money >= quarters)
    {
        money -= quarters;
        num++;
    }
    while(money >= dimes)
    {
        money -= dimes;
        num++;
    }
    while(money >= nickels)
    {
        money -= nickels;
        num++;
    }
    while(money >= pennies)
    {
        money -= pennies;
        num++;
    }
    printf("%d\n",num);
}
