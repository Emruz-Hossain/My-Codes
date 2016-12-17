#include<stdio.h>
int main()
{
    int test_case,i,a,digit;
    long long number,sum,k;
    scanf("%d",&test_case);
    for(i=1;i<=test_case;i++)
    {
        scanf("%lld",&number);
        k=number;
        if(number<10)
        number=number*number;
        while(1)
        {
             sum=0;

            if(number<=10)
                break;

            else
                while(number!=0)
                {
                    digit=number%10;
                    sum=sum+digit*digit;
                    number=number/10;
                }
                number=sum;
        }
        if(number==1||number==10)
            printf("Case #%d: %lld is a Happy number.\n",i,k);
        else
            printf("Case #%d: %lld is an Unhappy number.\n",i,k);
    }
    return 0;
}
