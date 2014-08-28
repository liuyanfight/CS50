// 汉字统计
// Hint:汉字码的特点
#include <stdio.h>

int main(void)
{
    int n, i, j, cnt;
    char s[1001];
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        gets(s);
        j = 0; cnt = 0;
        while (s[j] != '\0')
        {
            if (s[j] < 0)
                cnt++;
            j++;
        }
        printf("%d\n", cnt / 2);
    }
    return 0;
}
