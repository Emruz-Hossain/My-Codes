#include<stdio.h>
int main()
{
    long long m,a,b,c,r;
    while(1)
    {
        scanf("%lld %lld %lld %lld",&m,&a,&b,&c);
        if(m==0&&a==0&&b==0&&c==0)
            break;
    r=3*360;
    if(m==a)
        r=r;
    else if(m>a)
            r+=(m-a)*9;
    else
         r+=(m+(40-a))*9;
     if(a==b)
     r=r;
    else if(a>b)
        r+=((40-a)+b)*9;
    else
        r+=(b-a)*9;
    if(b==c)
    r=r;
    else if(b>c)
    r+=(b-c)*9;
    else
        r+=(b+(40-c))*9;
   printf("%lld\n",r);
    }
return 0;
}
