//*********BISMILLAHIR RAHMANIR RAHIM*********
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef __int64 ll;
#define mem(x,y) memset(x,y,sizeof(x))

#define fr(i,a,b) for(i=a;i<=b;i++)
#define frd(i,a,b) for(i=a;i>=b;i--)

#define sf1(a) scanf("%I64d",&a)
#define sf2(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define dsf1(a) scanf("%lf",&a)
#define dsf2(a,b) scanf("%lf %lfd",&a,&b)
#define dsf3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define ssf1(a) scanf("%s",&a)
#define ssf2(a,b) scanf("%s %s",&a,&b)
#define ssf3(a,b,c) scanf("%s %s %s",&a,&b,&c)
#define pf(a) printf();
#define pf1(a) printf("%I64d\n",a)
#define pf2(a,b) printf("%I64d %I64d\n",a,b)
#define pf3(a,b,c) printf("%I64d %I64d %I64d\n",a,b,c)
#define spf1(a) printf("%s\n",a)
#define spf2(a,b) printf("%s %s\n",a,b)

#define pi 2*acos(0)
#define mod 1000000007
ll i,j,k,la,lb,a,b,c,m,n,r,p,q,x,y,sum,mid,high,low,t;
int main()
{
sf1(t);
fr(i,1,t)
{
    sum=1;
    p=0;
    c=0;
    sf2(n,b);
    fr(j,1,n)
    {
        sum=sum*j;
    }
    if(b!=10)
    {
        while(sum!=0)
        {
            x=sum%b;
            p=p*10+x;
            sum=sum/10;
        }
    }
    else
        p=sum;
    while(p!=0)
    {
        c++;
        p=p/10;
    }
    printf("Case %lld: %lld\n",i,c);
}
return 0;
}
