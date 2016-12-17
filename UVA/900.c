#include<stdio.h>
long long dp[1000];
long long fibo(long long m)
{
    if(dp[m]!=0)
        return dp[m];
    else if(m<=2)
        return 1;
    else
        return dp[m]=fibo(m-1)+fibo(m-2);
}
int main()
{
    long long briks,result;
    while(1)
    {
        scanf("%lld",&briks);
        if(briks==0)
            break;
        else
            result=fibo(briks+1);
        printf("%lld\n",result);
    }
    return 0;
}
