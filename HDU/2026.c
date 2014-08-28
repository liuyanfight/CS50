// 首字母变大写
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char seq[101];
    while (fgets(seq, 101,stdin))
    {
        seq[0] = toupper(seq[0]);
        int i = 1;
        while (seq[i] != '\n')
        {
            if (seq[i - 1] == ' ')
                seq[i] = toupper(seq[i]);
            i++;
        }
        printf("%s",seq);
    }
    return 0;
}
