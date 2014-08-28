// 数据的交换输出
#include <stdio.h>

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        int nums[n], min = 0, i;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &nums[i]);
            if (nums[i] < nums[min])
                min = i;
        }
        int tmp = nums[0];
        nums[0] = nums[min];
        nums[min] = tmp;
/*        for (i = 0; i < n; i++)*/
/*        {*/
/*            if (i == n)*/
/*                printf("%d\n",nums[i]);*/
/*            else*/
/*                printf("%d ",nums[i]);*/
/*        }*/
	    for(i=0;i<n-1;i++)
				printf("%d ",nums[i]);
		printf("%d\n",nums[n-1]);
    }
    return 0;
}
