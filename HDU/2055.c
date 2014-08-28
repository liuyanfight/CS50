#include <stdio.h>
#include <ctype.h>

int f(char letter);

int main(void)
{
    int n, y;
    char letter;
    scanf("%d", &n);
    while (n--)
    {
        getchar();
        scanf("%c %d", &letter, &y);
        printf("%d\n", y + f(letter));
    }
    return 0;
}

int f(char letter)
{
    if (isupper(letter))
        return letter - 64;
    else 
        return -(letter - 96);
}
