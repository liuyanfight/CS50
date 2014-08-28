#include <stdio.h>

int main(void)
{
    int w, h, i, j;
    while (scanf("%d %d", &w, &h) != EOF)
    {
        printf("+");
        for (i = 0; i < w; i++)
        {
            printf("-");
        }
        printf("+\n");
        while (h--)
        {
            for (i = 0; i < w + 2; i++)
            {
                if (i == 0 || i == w + 1)
                    printf("|");
                else
                    printf(" ");          
            }
            printf("\n");
        }
        printf("+");
        for (i = 0; i < w; i++)
        {
            printf("-");
        }
        printf("+\n\n");
    }
    return 0;
}
