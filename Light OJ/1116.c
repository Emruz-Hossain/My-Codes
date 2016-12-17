#include<stdio.h>
int main()
{
    unsigned long long n,m,t,i,d,w;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        d=0;
        scanf("%lld",&w);
        for(m=2;m<=w;m=m*2)
        {
            if(w%m==0)
            {
                n=w/m;
                if(n%2!=0)
                {
                    d=1;
                    break;
                }
            }
        }
        if(d==1)
            printf("Case %lld: %lld %lld\n",i,n,m);
        else
            printf("Case %lld: Impossible\n",i);
    }
    return 0;
}
