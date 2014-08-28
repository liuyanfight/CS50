/*
 *王道程序员求职宝典p24 例3
 *What's the result of the following program?
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 char *f(char *str,char ch)
 {
    char *it1 = str;
    char *it2 = str;
    while (*it2 != '\0')
    {
        while (*it2 == ch)
        {
            it2++;
        }
        *it1++ = *it2++;
    }
    return str;
 }
 
 int main(void)
 {
    char *a = "abcdccd";
    printf("%s",f(a,'c'));
    free(a);
    return 0;
 }
