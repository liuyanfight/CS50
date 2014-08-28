// 数列有序!
#include <stdio.h>

int main(void)
{
    int n,m;
    while (scanf("%d %d",&n,&m) != EOF && (n !=0 || m != 0))
    {
        int q[n + 1], i, k = -1;
        for (i = 0; i < n; i++)
        {
            scanf("%d",&q[i]);
            if (m > q[i])
            {
                k = i;
            }
        }
        
        for (i = n; i > (k + 1); i--)
        {
            q[i] = q[i - 1];
        }
        q[k + 1] = m;
        
        for (i = 0; i <= n; i++)
        {
            if (i == n)
                printf("%d\n",q[i]);
            else
                printf("%d ",q[i]);
        }
    }
    return 0;
}
