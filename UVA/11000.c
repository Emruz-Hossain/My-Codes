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
    long long year,result,total,male;
    while(1)
    {
        scanf("%lld",&year);
        if(year==-1)
            break;
        else
            {
                total=fibo(year+3)-1;
                male=total-fibo(year+1);
            }
        printf("%lld %lld\n",male,total);
    }
    return 0;
}

