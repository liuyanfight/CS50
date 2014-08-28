/******************************
Hail, Caesar!
ci = (pi + k) % 26
Ascii!!  ci = ((pi - 65 || 97) + k % 26) % 26 + 65 || 97

jharvard@appliance (~/Dropbox/pset2): ./caesar 13
Be sure to drink your Ovaltine!
Or fher gb qevax lbhe Binygvar!

jharvard@appliance (~/Dropbox): ./caesar 13
uggc://jjj.lbhghor.pbz/jngpu?i=bUt5FWLEUN0
http://www.youtube.com/watch?v=oHg5SJYRHA0
funny!^_^
******************************/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>// atoi
#include <string.h>
#include <ctype.h>// isupper islower

int main(int argc, char *argv[])
{
    if (argv[1] == NULL || argv[2] != NULL)
    {
        for(int i = 0;i < argc;i++) // if no,handles lack of argv[1]
        {
            printf("%s",argv[i]);
        }
        return 1;
    }
    // string k = argv[1];
    int k = atoi(argv[1]);// convert that string to an actual int,stdlib.h
    // You don’t have to worry about them typing, say, foo, just to be difficult; atoi will just return 0 in such cases.
    string s = GetString();
    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (isupper(s[i])) // ctyre.h
                printf("%c", (((s[i] - 65) + k % 26) % 26) + 65);
            else if (islower(s[i]))
                printf("%c",(((s[i] - 97) + k % 26) % 26) + 97);
            else
                printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
}
