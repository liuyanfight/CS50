#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int M, i, sum;
    char s[50];
    scanf("%d", &M);
    while (M--)
    {
        scanf("%s", s);
        i = 0; 
        int flag[4] = {0};
        while (s[i] != '\0')
        {
            if (isupper(s[i]))
                flag[0] = 1;
            else if (islower(s[i]))
                flag[1] = 1;
            else if (isdigit(s[i]))
                flag[2] = 1;
            if (s[i] == '~' || s[i] == '!' || s[i] == '@' ||
                s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '^')
                flag[3] = 1;
            i++;
        }
        sum = flag[0] + flag[1] + flag[2] +flag[3];
        if (i < 8 || i > 16 || sum < 3)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
