// 绝对值排序
#include <stdio.h>

void quickSort(int q[], int low, int high);
int partition(int q[], int low, int high);
int Abs(int n);

int main(void)
{
    int n;
    while (scanf("%d",&n) != EOF && n != 0)
    {
        int i,q[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d",&q[i]);
        }
        quickSort(q,0,n - 1);
        for (i = 0; i < n; i++)
        {
            if(i == n - 1)
                printf("%d\n",q[i]);
            else
                printf("%d ",q[i]);
        }
    }
    return 0;
}

void quickSort(int q[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(q, low, high);
        quickSort(q, low, pivot - 1);
        quickSort(q, pivot + 1, high);
    }
}
int partition(int q[], int low, int high)
{
    int tmp = q[high];
    while (low < high)
    {
    while (Abs(q[low]) > Abs(tmp) && low < high)
        low++;
    q[high] = q[low];
    while (Abs(tmp) > Abs(q[high]) && low < high)
        high--;
    q[low] = q[high];
    }
    q[high] = tmp;
    return high;
}
int Abs(int n)
{
    return n > 0 ? n : -n;
}
