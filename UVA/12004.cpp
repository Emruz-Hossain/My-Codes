#include<stdio.h>
int gcd(int p,int q)
{
    if(p%q==0)
        return q;
    else
        gcd(q,p%q);
}
int main()
{
    int t,i,n,avg,p,q,g;
    double r,sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        if(n==1)
            printf("Case %d: 0\n",i);
        else
        {
        sum=((n-1)*(n))/2;
        r=sum/n;
        p=sum;
        q=n;
        avg=r;

        if(avg==r)
            printf("Case %d: %d\n",i,avg);
        else
        {
            g=gcd(p,q);
            p=p/g;
            q=q/g;
            printf("Case %d: %d/%d\n",i,p,q);

        }
        }
    }
    return 0;
}
