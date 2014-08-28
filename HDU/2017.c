// 字符串统计
#include <stdio.h>

int main(void)
{
    int n, i;
    scanf("%d",&n);
    char s[1000];
    for (i = 0; i < n; i++)
    {
        scanf("%s",s);
        int i = 0,cnt = 0;
        while(s[i] != '\0')
        {
            /* ASCII 0-48 9-57*/
            if ('0' <= s[i] && s[i] <= '9')
            {
                cnt++;
            }
            i++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
