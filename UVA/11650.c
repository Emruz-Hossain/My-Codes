#include<stdio.h>
int main()
{
    int H,M,T,hour,minute,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d:%d",&hour,&minute);
        if(hour==12&&minute==00)
            printf("12:00\n");
        else
        {
        if(hour>11&&minute>0)
            {
                H=11;
                M=60-minute;
            }
        else
            {
                H=((12*60+0)-((hour*60)+minute))/60;
                M=720-((hour*60)+minute)-(H*60);
            }
        if(H==0)
        H=12;
        if(H<10&&M<10)
            printf("0%d:0%d\n",H,M);
        else if(H<10&&M>9)
            printf("0%d:%d\n",H,M);
        else if(H>9&&M<10)
            printf("%d:0%d\n",H,M);
        else
            printf("%d:%d\n",H,M);
        }
    }
    return 0;
}
//5
//09:55
//01:32
//01:00
//06:33
//12:11
