// Palindromes _easy version
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, i, j;
    scanf("%d",&n);
    char s[101];
    for (i = 0; i < n; i++)
    {
        scanf("%s",s);
        int slen = strlen(s), flag = 0;
        for (j = 0; j < slen / 2; j++)
        {
            if (s[j] != s[slen - j - 1])
            {
                flag = 1;
            }
        }
        if (flag == 1)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
