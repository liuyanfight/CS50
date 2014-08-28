/**************************
Compared with initials1.c
But the user’s input might be sloppy, 
in which case there might be one or more spaces at the start and/or end of the user’s input or even multiple spaces in a row.
jharvard@appliance (~/Dropbox/hacker2): ./initials
Milo Banana
MB
jharvard@appliance (~/Dropbox/hacker2): ./initials
   robert   thomas bowden
RTB
**************************/

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
    for (int i = 0;i < n;i++)
    {
        if (i == 0 && s[0] != ' ')
            printf("%c",toupper(s[0]));
        else if (i != 0 && s[i] != ' ' && s[i - 1] == ' ')
            printf("%c",toupper(s[i]));
        else
            continue;
    }
    printf("\n");
    return 0;
}
