//  C语言合法标识符
// 多亏杭电大神～～
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int n, i, j;
    char str[51];
    while (scanf("%d",&n) !=EOF)
    {
        for (i = 0; i < n; i++)
        {
            int flag = 0;
            /*scanf("%s",str); */
            if (i == 0)
                getchar();
            fgets(str, 51, stdin);
            if (isalpha(str[0]) == 0 && str[0] != '_')
            {
                flag = 1;
            }
            for (j = 0; str[j] != '\n' && str[j] != '\0'; j++)
            {
                if (isalnum(str[j]) == 0 && str[j] != '_')
                {
                    flag = 1;
                }                   
            }
            if (flag == 0)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
