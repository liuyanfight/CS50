// WA!!!!
#include <stdio.h>

void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main(void)
{
    int m, n, i, j, k;
    while (scanf("%d %d", &m, &n) != EOF && (m != 0 || n != 0))
    {
        int a[m], b[n];
        for (i = 0; i < m + n; i++)
        {
            if (i < m)
                scanf("%d", &a[i]);
            else
                scanf("%d", &b[i - m]);
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i] == b[j])
                {
                    for (k = i; k < n - 1; k++)
                    {
                        a[k] = a[k + 1];
                    }
                    if (m > 0)
                        m--;
                }
            }
        }
        quickSort(a, 0, m - 1);
        if (m == 0)
            printf("NULL\n");
        else
        {
            for (i = 0; i < m; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}
int partition(int a[], int low, int high)
{
    int tmp = a[low];
    while (low < high)
    {
        while(a[high] > tmp && low < high)    high--;
        a[low] = a[high];
        while (a[low] < tmp && low < high)    low++;
        a[high] = a[low];
    }
    a[low] = tmp;
    return low;
}
