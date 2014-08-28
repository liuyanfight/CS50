#include <stdio.h>

int isLeap(int year);
int Abs(int n);
int months (char month[10],int year);

int main(void)
{
    int cYear = 2014;
    int cMonth = 3;
    int cDay = 3;
    int cWeek = 1;
    int year,day;
    char month[10];
    while (scanf("%d %s %4d",&year,month,&day) != EOF)
    {
        int l = isLeap(year)?366:365;
        int d = Abs(year - cYear) * l;

        d += months(month,year) - ;
        d += 
        printf("%d\n",d);
    }

    return 0;
}

int isLeap(int year)
{
    // The leap years are years with number divisible by 4 
    // but not divisible by 100, or divisible by 400.
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    return 0;
}

int Abs(int n)
{
    return n > 0 ? n : -n;
}

int months (char month[10],int year)
{
        int d = 0
        if (strcmp(month,"January") != 0)
            d += 31;
        else
            return d;
            
        if (strcmp(month,"February") != 0)
            d += (28 + isLeap(year));
        else
            return d;
            
        if (strcmp(month,"March") != 0)
            d += 31;
        else
            return d;
            
        if (strcmp(month,"April") != 0)
            d += 30;
        else
            return d;
            
        if (strcmp(month,"May") == 0)
            d += 31;
        else
            return d;
            
        if (strcmp(month,"June") == 0)
            d += 30;
        else
            return d;
            
        if (strcmp(month,"July") == 0)
            d += 31;
        else
            return d;
            
        if (strcmp(month,"August") == 0)
            d += 31;
        else
            return d;
            
        if (strcmp(month,"September") == 0)
            d += 30;
        else
            return d;
            
        if (strcmp(month,"October") == 0)
            d += 31;
        else
            return d;
            
        if (strcmp(month,"November") == 0)
            d += 30;
        else
            return d;
            
        if (strcmp(month,"December") == 0)
            d += 31;
        else
            return d;
}
