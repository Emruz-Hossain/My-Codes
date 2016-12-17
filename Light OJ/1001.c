#include<stdio.h>
int main()
{
    int t,a,b,n,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        a=n/2;
        b=a;
        if(a+b<n)
            b=a+1;
        printf("%d %d\n",a,b);
    }
    return 0;
}
