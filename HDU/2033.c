// 人见人爱A+B
#include <stdio.h>

int main(void)
{
    int n, i;
    int AH,AM,AS,BH,BM,BS, sh, sm, ss;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d %d %d %d", &AH, &AM, &AS, &BH, &BM, &BS);
        sh = 0; sm =0; ss = 0;
        ss = AS + BS;
        if (ss > 60)
        {
            sm += ss / 60;
            ss = ss % 60;
        }
        sm += AM + BM;
        if (sm > 60)
        {
            sh += sm / 60;
            sm = sm % 60;
        }
        sh += AH + BH;
        printf("%d %d %d\n", sh, sm, ss);
    }
    return 0;
}
