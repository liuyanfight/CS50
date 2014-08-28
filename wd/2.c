// 九度教程第二题
// 成绩排序
// quick sort
// 超时！！！！！！！！！！！！！！！！！！

#include <stdio.h>
#include <string.h>

struct student
{
    char name[100];
    int age;
    int grade;
}
s;

void quickSort(struct student *s, int low, int high);
int Partition(struct student *s, int low, int high);

int main(void)
{
    // input numbers
    int n;
    while (scanf("%d",&n) != EOF)
    {
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", s[i].name, &s[i].age, &s[i].grade);
    }
    //quick sort
    quickSort(s, 0, n - 1);
    // print the result
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d\n", s[i].name, s[i].age, s[i].grade);
    }
    }
    return 0;
}

//quick sort
void quickSort(struct student *s, int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(s, low, high);
        quickSort(s, low, pivotpos - 1);
        quickSort(s, pivotpos + 1, high);
    }
}
// divided
int Partition(struct student *s, int low, int high)
{
    struct student pivot = s[low];
    while (low < high)
    {
        // by grade         // grade equals, by name         // name equals, by age
        while ((pivot.grade < s[high].grade && low < high) || 
            (pivot.grade == s[high].grade && low < high && strcmp(pivot.name,s[high].name) < 0) ||
            (pivot.grade == s[high].grade && low < high && strcmp(pivot.name,s[high].name) == 0 && pivot.age > s[high].age))  
        {
            --high;
        }
        s[low] = s[high];
        while ((s[low].grade < pivot.grade && low < high) ||
            (s[low].grade == pivot.grade && low < high && strcmp(s[low].name,pivot.name) < 0) ||
            (s[low].grade == pivot.grade && low < high && strcmp(s[low].name,pivot.name) == 0 && pivot.age > s[high].age))
        {
            ++low;
        }
        s[high] = s[low];
    }
    s[low] = pivot;
    return low;
}
/*//cmp*/
/*int charCmp(char *a,char *b)*/
/*{*/
/*//同:-1 前小:1 后小：0*/
/*//        int lena=strlen(a),lenb=strlen(b);*/
/*        int i;*/
/*        for(i=0;;i++){*/
/*                if(a[i]=='\0'&&b[i]=='\0')*/
/*                        return -1;*/
/*                if(a[i]=='\0')        //a为b前缀*/
/*                        return 1;*/
/*                if(b[i]=='\0')        //b为a前缀*/
/*                        return 0;*/
/*                if(a[i]!=b[i])        //*/
/*                        return a[i]<b[i];*/
/*        }*/
/*}*/

