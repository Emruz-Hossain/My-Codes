#include<stdio.h>
int k;
long long rev(long long m)
{
    long long sum=0;
    int r;
    while(m>0)
    {
        r=m%10;
        sum=sum*10+r;
        m=m/10;
    }
    return sum;
}
long long palindrome(long long n)
{
    long long sum;
    sum=n+rev(n);
    k++;
    if(sum==rev(sum))
        return sum;
    else
       palindrome(sum);
}
int main()
{
    long long P,sum;
    int N,i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        k=0;
        scanf("%lld",&P);
        sum=palindrome(P);
        printf("%d %lld\n",k,sum);
    }
    return 0;
}
