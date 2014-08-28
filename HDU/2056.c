#include <stdio.h>
float Abs(float n);
int main(void)
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    while (scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != EOF)
    {
        if (y3 < y2 && x3 < x2)
        {
            printf("%.2f\n", Abs(y2 - y3) * Abs(x2 - x3));
        }
        else if()
    }
    return 0;
}

float Abs(float n)
{
    return n > 0 ? n : -n;
}
