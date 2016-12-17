#include<stdio.h>
long long result=0;

long long f(long long n)
{
    int digit;
    if(n==0)
        return 0;
    else
    {
        digit=n%2;
        f(n/2);
        result=result*10+digit;
    }
    return result;
}
int main()
{
    long long number,binary,parity,k;
    int i,sum=0,digit;
    while(1)
    {
        sum=0;
        result=0;
        scanf("%lld",&number);
        if(number==0)
            break;
        else
            binary=f(number);
            k=binary;
        while(binary!=0)
        {
            digit=binary%10;
            sum=sum+digit;
            binary=binary/10;
        }
        printf("The parity of %lld is %d (mod 2).\n",k,sum);
    }
    return 0;
}
