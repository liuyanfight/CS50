/****************************
Parlez-vous français?

jharvard@appliance (~/Dropbox/pset2): ./vigenere bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
****************************/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

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
    int n = strlen(argv[1]);
    int k[n];
    for (int i = 0;i < n;i++)
    {
        if (isupper(argv[1][i]))
            k[i] = argv[1][i] - 65;
        else if (islower(argv[1][i]))
            k[i] = argv[1][i] - 97;
        else  // not alpha
        {
            printf("%s",argv[1]);
            return 1; 
        }       
    } 
    int j = 0;
    string s = GetString();
    if (s != NULL)
    {
        for (int i = 0, ns = strlen(s); i < ns; i++)
        {
            if (isupper(s[i])) // ctyre.h
            {
                printf("%c", ((((s[i] - 65) + k[j]) % 26) + 65));
                j = (j + 1) % n;
            }
            else if (islower(s[i]))
            {
                printf("%c", ((((s[i] - 97) + k[j]) % 26) + 97));
                j = (j + 1) % n;
            }
            else
                printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
}
