#include<stdio.h>
int main()
{
    long long r,n,t,i;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        n=n*567;
        n=n/9;
        n=n+7492;
        n*=235;
        n/=47;
        n-=498;
        n=n/10;
        r=n%10;
        if(r<0)
            r*=-1;
        printf("%lld\n",r);
    }
}
