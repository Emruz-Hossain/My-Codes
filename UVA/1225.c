#include<stdio.h>
int main()
{
    int counter[20]={0};
    long long number,k,temp;
    int digit,test_case,i,j;
    scanf("%d",&test_case);
    for(i=1;i<=test_case;i++)
    {
        for(j=0;j<10;j++)
            counter[j]=0;
        scanf("%lld",&number);
        if(number==0)
            counter[0]=1;
        else
        for(k=1;k<=number;k++)
        {
            temp=k;
            while(temp>0)
            {
            digit=temp%10;
            temp=temp/10;
            counter[digit]+=1;
            }
        }
        for(j=0;j<10;j++)
            if(j==9)
            printf("%d",counter[j]);
        else
            printf("%d ",counter[j]);
        printf("\n");
    }
    return 0;
}
