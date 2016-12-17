//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define inf 1<<25
#define sz 2000
#define eps 1e-9
long long trailing_zero(long long n)
{
    long long zero=0;
    double r;
    while(n>1)
    {
        r=n/5;
        zero+=(int)r;
        n=r;
        if(n<1&&n>0&&zero!=0)
            zero++;
    }
    return zero;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i;
    long long l,h,m,n,q,tz;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        l=0;h=400000015;
        tz=0;
        while(l<=h)
        {
            m=(l+h)/2;
            q=trailing_zero(m);
            if(q==n)
                tz=m;
            if(q>=n)
                h=m-1;
            else
                l=m+1;
        }
        if(tz!=0)
            printf("Case %d: %lld\n",i,tz);
        else
            printf("Case %d: impossible\n",i);
    }

    return 0;
}


