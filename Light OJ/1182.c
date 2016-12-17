#include<stdio.h>
int k;
void parity(int n)
{
    int r;
    if(n==0)
        return;
    r=n%2;
    k=k+r;
    parity(n/2);
}
int main()
{
    int t,i,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        k=0;
        scanf("%d",&n);
        parity(n);
        if(k%2==0)
            printf("Case %d: even\n",i);
        else
            printf("Case %d: odd\n",i);
    }
    return 0;
}
