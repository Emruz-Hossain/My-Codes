#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,n,base,j,l,d;
    long long fact;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        d=0;
        scanf("%d %d",&n,&base);
        if(n==0)
            printf("Case %d: 1\n",i);
        else
        {
            fact=1;
        while(n!=0)
        {
            fact=fact*n;
            n=n-1;
        }
        /*while(fact!=0)
        {
            d++;
            fact=fact/base;

        }
        */
        printf("Case %d: %d\n",i,fact);
    }
    }
    return 0;
}
