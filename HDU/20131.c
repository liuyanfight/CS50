#include <stdio.h>

int main(void)
{
    int n, h1, m1, s1, h2, m2, s2;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d:%d:%d", &h1, &m1, &s1);
        scanf("%d:%d:%d", &h2, &m2, &s2);
        if (s1 >= s2)
        {
            s1 -= s2;
        }
        else
        {
            s1 = s1 + 60 - s2;
            m1--;
        }
        if (m1 >= m2)
        {
            m1 -= m2;
        }
        else
        {
            m1 = m1 + 60 - m2;
            h1--;
        }
        h1 = h1 % 12 - h2 % 12;
        h1 = h1 > 0 ? h1 : -h1;
        printf("%02d:%02d:%02d\n", h1, m1, s1);
    }
    return 0;
}
