#include<stdio.h>
int main()
{
    long long t,i,j,n,m,sum,k,p;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        k=0;
        sum=0;
        scanf("%lld %lld",&n,&m);
        for(j=n;j<=m;j++)
        {
            for(p=1;p<=j;p++)
            {
                if(p>9)
                {
                    while(p!=0)
                    {
                        sum+=p%10;
                        p=p/10;
                    }
                }
                sum+=p;
            }
            if(sum%3==0)
                k++;
        }
        printf("Case %lld: %lld\n",i,k);
    }
    return 0;
}
