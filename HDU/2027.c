// 元音字母 
#include <stdio.h>

int main(void)
{
    int n, i;
    char s[101];
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            getchar();
        fgets(s, 101, stdin);
        int j = 0;
        int sum[5] = {0};
        while (s[j] != '\n')
        {
            if (s[j] == 'a')
                sum[0]++;
            if (s[j] == 'e')
                sum[1]++;
            if (s[j] == 'i')
                sum[2]++;
            if (s[j] == 'o')
                sum[3]++;
            if (s[j] == 'u')
                sum[4]++;
            j++;
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", 
            sum[0],sum[1],sum[2],sum[3],sum[4]);
        if (i != n - 1)
            printf("\n");
    }
    return 0;
}
