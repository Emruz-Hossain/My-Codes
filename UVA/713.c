#include<stdio.h>
int sum;
int rev(int m)
{
    int r;
    if(m<10)
        return sum=sum*10+m;
    else
    {
        r=m%10;
        sum=sum*10+r;
        rev(m/10);
        return sum;
    }
}
int main()
{
    int t,n,a,b,r,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d %d",&a,&b);
        a=rev(a);
        sum=0;
        b=rev(b);
        sum=0;
        r=rev(a+b);
        printf("%d\n",r);
    }
    return 0;
}
