/*************
jharvard@appliance (~/Dropbox/pset2): ./initials
Milo Banana
MB
jharvard@appliance (~/Dropbox/pset2): ./initials
robert thomas bowden
RTB
**************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>// toupper

int main(void)
{
    string s=GetString();
    if (s == NULL)
        return 0;
    int n = strlen(s);
    char c;
    int j = 0;
    for (int i = 0;i < n;i++)
    {
        if (i == 0)
            printf("%c",toupper(s[0]));// printf("%c",s[0] - ('a' - 'A'));           
        else   if (s[i] == ' ')
        {
            c = toupper(s[i + 1]);// s[i+1] - ('a' - 'A');
            j++;
            printf("%c",c);
        }
    }
    printf("\n");
    return 0;
}
