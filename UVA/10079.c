#include<stdio.h>
int main()
{
    long long l,sum,i,a;
    while(1)
    {
        scanf("%lld",&l);
        sum=0;
        a=2;
        if(l<0)
            break;
        else
        {
            for(i=a;i<=l;i++)
            {
                sum=a+i;
                a=sum;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
