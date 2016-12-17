#include<stdio.h>
long long n,sum;
void rec(void)
{
    int r;
    sum=0;
    while(n>0)
    {
    r=n%10;
    sum=sum+r;
    n=n/10;
    }
    n=sum;
    if(n>=10)
        rec();
}
int main()
{
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
            break;
        else
        {
            rec();
            printf("%lld\n",sum);
        }

    }
    return 0;
}
