/**************************
pset1 hacker editon (1)

Bad Credit
简而言之，就是验证一个银行卡号是否有效，要知道，我们的银行卡号也是有一定规律的，
AMEX（ American Express）以34或37开头， MASTERCARD（MasterCard）以51.52.53.54.55开头，VISA（Visa ）以4开头，
很多卡都用的来自IBM的Hans Peter Luhn的算法：
  1.将卡号的偶数位（2，4```）都乘以2，将得到的数相加（比如7*2=14则变成1+4）
  2.将1中得到的数与卡号的奇数位（1，3，5```）相加（正常相加）
  3.在2中得到的数末位是否为0？或者说该数mod 10=0？若为0，则该卡号是有效的。
举个例子：
  卡号：378282246310005
  1.3(7)8(2)8(2)2(4)6(3)1(0)0(0)5括号内为偶数位，乘以2为7•2 + 2•2 + 2•2 + 4•2 + 3•2 + 0•2 + 0•2，
  即14 + 4 + 4 + 8 + 6 + 0 + 0，把数字相加1 + 4 + 4 + 4 + 8 + 6 + 0 + 0 = 27
  2.将27与奇数位相加27 + 3 + 8 + 8 + 2 + 6 + 1 + 0 + 5 = 60
  3.所以该卡号是有效的！
  所以本题为在credit.c中，提示用户输入卡号，然后输出结果是否有效。并判断为那一种卡。要求在最后一行输出 AMEX\n or MASTERCARD\n or VISA\n or INVALID\n
示例：
jharvard@appliance (~/Dropbox/hacker1): ./credit
Number: 378282246310005
AMEX

jharvard@appliance (~/Dropbox/hacker1): ./credit
Number: 7722574501
INVALID
在这有一些数据可供测试https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm

!!
The checksum for 5105105105105100 is 20
   5 1 0 5 1 0 5 1 0 5 1 0 5 1 0 0
   2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1

=(10)+1+0+5+2+0+(10)+1+0+5+2+0+(10)+1+0+0
= 20
It's a Mastercard.
Did you perhaps start your odds/evens from the beginning rather than the end?
****************************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // long int10位
    printf("Number:");
    long long num = GetLongLong();// c89支持,19位   
    int i = 0;
    int nums[20] = {0};// Initialization
    while(num > 0)// put digits in nums[] and count num  
    {
        nums[i] = num % 10;
        num = num / 10;
        i++;
    }
    int sum = 0;
    for(int j = i;j >= 0;j = j - 2)// from i+1 to 0
    {
        if (i % 2 == 1)// odds
        {
            sum += (nums[j] * 2) / 10 + (nums[j] * 2) % 10;// adds double
            if ((j - 1) >= 0)
                sum += nums[j - 1];// add single
        }
        else// evens
        {
            if ((j - 1) >= 0)
                sum += (nums[j - 1] * 2) / 10 + (nums[j - 1] * 2) % 10;// adds double
            if ((j - 2) >= 0)
                sum += nums[j - 2];// add single
        }
        // printf("%d\n",sum);
    }
    // printf("%d\n",sum);
    if (sum % 10 == 0)
    {
        switch (nums[i - 1])
        {
            case 3 : 
                if (nums[i - 2] == 4 || nums[i - 2] == 7)
                    printf("AMEX\n");
                else
                    printf("INVALID\n");
                break;
            case 4 : 
                printf("VISA\n");
                break;
            case 5 : 
                if (nums[i - 2] > 0 && nums[i - 2] < 6)
                    printf("MASTERCARD\n");
                else
                    printf("INVALID\n");
                break;
            default: 
                printf("INVALID\n");
        }
    }
    else
        printf("INVALID\n");
    return 0;
}
