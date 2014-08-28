/***************************************************
Pset1 standard edition (1)
jharvard@appliance (~/Dropbox/pset1): ./mario
Height: 8
       ##
      ###
     ####
    #####
   ######
  #######
 ########
#########
*****************************************************/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        printf("Height:");
        h = GetInt();
	}while(h > 23 || h < 0);
    if (h == 0) 
        return 0;
    int i, j;
    for(i = 0;i < h;i++)
    {
        for(j = 1;j < (h - i);j++)
            printf(" ");
        for(j = 0;j < i;j++)
            printf("#");
        printf("##\n");
	}
    return 0;
}
