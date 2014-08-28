// 三角形 注意 边长为double
#include <stdio.h>

float Abs(float n);

int main(void)
{
    int M, i;
    float A, B, C;
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%f %f %f", &A, &B, &C);
        if (A + B > C && Abs(A - B) < C)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

float Abs(float n)
{
    return n > 0 ? n : -n;
}
