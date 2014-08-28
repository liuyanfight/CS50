/*王道p19第14题
 *
 *将一个二维N * N矩阵顺时针旋转90‘
 *例如a[2][2] = {1,2,3,4},旋转过后a[2][2] = {3,1,4,2}
 *
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("input the dim:");
    int n = GetInt();
    int matrix[n][n];
    int k = 0;
    printf("Init:\n");
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            matrix[i][j] = ++k;
            printf(" %3d ",matrix[i][j]);
        }
        printf("\n");
    }
    for (int layer = 0;layer < n / 2;++layer)
    {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first;i < last;++i)
        {
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
            printf("layer = %d, i = %d\n", layer, i); 
            for (int i = 0;i < n;i++)
            {
                for (int j = 0;j < n;j++)
                {
                    printf(" %3d ",matrix[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}

