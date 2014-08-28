/*********************
jharvard@appliance (~/Dropbox/hacker1): ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
***********************/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        printf("Height:");
        h = GetInt();
    }while(h < 0 || h > 23);
    if (h == 0) 
        return 0;
    for(int i = h;i > 0;i--)
    {
        for(int j = i;j > 1;j--)
            printf(" ");
        for(int j = 0;j < (h - i + 1);j++)
            printf("#");
        printf("  ");
        for(int j = 0;j < (h - i + 1);j++)
            printf("#");
       // for(int j = i;j > 1;j--)  !!comment ,then,ok?!T-T
     //       printf(" ");
        printf("\n");
    }
    return 0;
}
