// 查找最大元素
#include <stdio.h>

int main(void)
{
    char s[101];
    while (scanf("%s",s) != EOF)
    {
        int i = 0;
        char max = s[0];
        while (s[i] != '\0')
        {
            if (s[i] > max)
                max = s[i];
            i++;
        }
        i = 0;
        while (s[i] != '\0')
        {
            printf("%c",s[i]);
            if (s[i] == max)
                printf("(max)");
            i++;
        }
        printf("\n");
    }
    return 0;
}
