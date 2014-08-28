/*
 * 题目：有一个文件 student.txt,文件当中包括一组学生的信息，
 *        包括名字、学号、英语成绩、语文成绩、数学成绩、科学成绩。
 *        从这个文件当中读入学生的信息，然后按照总成绩从高到低进行排序并输出学生信息。
 *
 * 总结：STL还不是很熟悉，再练练。
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[10];
    int sno;
    int eg;
    int cg;
    int mg;
    int sg;
    int total;
}stu[100];

int cmp (const void *a, const void *b)
{
    struct node *aa = (struct node *)a;
    struct node *bb = (struct node *)b;
    if (aa->total != bb->total)
        return aa->total > bb->total ? 1 : -1;
    else
        return aa->total - bb->total;
}

int main(void)
{
    FILE *fp;
    int i = 0;
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        printf("cannot open file\n");
        return 1;
    }
    int ncnt = fread(&stu[i], sizeof(stu[i]), 1, fp);    
    while (ncnt > 0)
    {
        stu[i].total = stu[i].eg + stu[i].cg + stu[i].mg + stu[i].sg;
        i++;
        ncnt = fread(&stu[i], sizeof(stu[i]), 1, fp);
    }
    qsort(stu, i, sizeof(stu[0]), cmp);
    while(i--)
    {
        printf("%s %d %d %d %d %d\n", stu[i].name, stu[i].sno, stu[i].eg,stu[i].cg, stu[i].mg, stu[i].sg);
    }
    fclose(fp);
    return 0;
}
