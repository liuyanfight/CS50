// 进制转换
#include <stdio.h>

int main(void)
{
    int n, r, top, i;
    char stack[50];
    while (scanf("%d %d", &n, &r) != EOF)
    {
        top = 0;
        if (n < 0)
        {
            printf("-");
            n = -n;
        }
        while (n != 0)
        {
            i = n % r;
            n = n / r;
            if (i < 10)
            {
                // 数字ASCII码相差48
                stack[top++] = i + 48;
            }
            else
            {
                switch(i)
                {
                    case 10:    stack[top++] = 'A';break;
                    case 11:    stack[top++] = 'B';break;
                    case 12:    stack[top++] = 'C';break;
                    case 13:    stack[top++] = 'D';break;
                    case 14:    stack[top++] = 'E';break;
                    case 15:    stack[top++] = 'F';break;
                }
            }
        }
        for (i = top - 1; i >= 0; i--)
        {
            printf("%c", stack[i]);
        }
        printf("\n");
    }
    return 0;
}

