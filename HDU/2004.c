//  成绩转换
#include <stdio.h>

int main(void)
{
    int grade;
    while(scanf("%d",&grade) != EOF)
    {
        if (grade < 0 || grade > 100)
        {
            printf("Score is error!\n");
        }
        else if (grade >= 90)
        {
            printf("A\n");
        }
        else if (grade >= 80)
        {
            printf("B\n");
        }
        else if (grade >= 70)
        {
            printf("C\n");
        }
        else if (grade >= 60)
        {
            printf("D\n");
        }
        else
        {
            printf("E\n");
        }
    }
    return 0;
}
