#include <stdio.h>
#include <string.h>
void del(char *a, int n);
int main(void)
{
    char a[12001], b[12001];
    int i;
    char *flag;
    while (scanf("%s %s", a, b) != EOF)
    {
        flag = "YES";
        del(a, strlen(a));
        del(b, strlen(b));
        int n = strlen(a);
        for (i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                flag = "NO";
            }
        }        
        printf("%s\n", flag);
    }
    return 0;
}
void del(char *a, int n)
{
    int i, j, k, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == '.')
        {
            break;
        }
    }
        while (a[0] == '0')
        {
            for (k = 0; k < n; k++)
            {
                a[k] = a[k + 1];
            }
            a[k] = '\0';
            n--;
            i--;
        }
        for (j = n - 1; j > i; j--)
        {
            if (a[j] != '0')
                break;
            else
            {
                a[j] = '\0';
                n--;
            }
        }
    for (i = 0; i < n; i++)
    {
        if (a[i] == '.' && a[i+1] == '\0')
        {
            a[i] = '\0';
        }
    }
}
