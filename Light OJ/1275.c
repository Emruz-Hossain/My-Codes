#include<stdio.h>
int main()
{
    int n,t,i,m;
    double r,k,c;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %lf",&n,&c);
        if(n==0)
            printf("Case %d: 0\n",i);
        else
        {
            r=c/(2*n);
            m=r;
            k=m+(1.00/2);
            if(r<=k)
            printf("Case %d: %d\n",i,m);
            else
                printf("Case %d: %d\n",i,m+1);
        }

    }
    return 0;
}
