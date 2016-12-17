#include<stdio.h>
int main()
{
    long long  n,m,d,t,r,i;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&n,&m);
        d=n/2;
        r=d*m;
        printf("Case %lld: %lld\n",i,r);
    }
}
