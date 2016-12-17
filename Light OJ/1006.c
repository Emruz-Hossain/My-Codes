#include<stdio.h>
#include<stdlib.h>
long long  dp[10005];
int a, b, c, d, e, f;
void mset(int n)
{
    int i;
    for(i=0;i<=10005;i++)
        dp[i]=0;
}
long long fn( int n )
{

    if(n<0)
        return 0;
    else if( n == 0 ) return a;
    else if( n == 1 ) return b;
    else if( n == 2 ) return c;
    else if( n == 3 ) return d;
    else if( n == 4 ) return e;
    else if( n == 5 ) return f;
    else if(dp[n]!=0)
        return dp[n];
    else
        dp[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%10000007;
    return dp[n];
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
        {
        mset(0);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", ++caseno, fn(n) % 10000007);

    }
    return 0;
}
