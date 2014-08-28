/* ASCII码排序

Problem Description
输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。
Input
输入数据有多组，每组占一行，有三个字符组成，之间无空格。
Output
对于每组输入数据，输出一行，字符中间用一个空格分开。
 
Sample Input
qwe
asd
zxc
Sample Output
e q w
a d s
c x z
*/
#include <stdio.h>

void quickSort(char s[],int low, int high);
int partition(char s[], int low, int high);

int main(void)
{
    char s[1001];
    while (scanf("%s",s) != EOF)
    {
        int i = 0;
        while (s[i] != '\0')
        {
            i++;
        }
        
        quickSort(s,0,i - 1);
        
        for (int j = 0; j < i; j++)
        {
            printf("%c",s[j]);
            if (j != i - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

void quickSort(char s[],int low, int high)
{
    if (high > low)
    {
        int pivot = partition(s, low, high);
        quickSort(s, low, pivot - 1);
        quickSort(s, pivot + 1, high);
    }
}
int partition(char s[], int low, int high)
{
    char tmp = s[low];
    while (low < high)
    {
        while (tmp < s[high] && low < high)
            --high;
        s[low] = s[high];
        while (s[low] < tmp && low < high) 
            ++low;
        s[high] = s[low];
    }
    s[low] = tmp;
    return low;
}
