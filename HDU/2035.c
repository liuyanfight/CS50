// 人见人爱A^B
#include <stdio.h>

int main(void)
{
    int A, B;
    while (scanf("%d %d", &A, &B) != EOF && (A!=0 || B!=0))
    {
        int s = 1, i;
        for (i = 0; i < B; i++)
        {
            s = s * A % 1000;
        }
        printf("%d\n", s);
    }
    return 0;
}
