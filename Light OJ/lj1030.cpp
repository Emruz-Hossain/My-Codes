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

typedef __int64 LL;
typedef vector<LL>VI;
typedef vector<string>VS;
typedef map<LL,LL>MII;
typedef map<string,LL>MSI;
typedef map<LL,string>MIS;

#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define fr(i,a,b) for(i=a;i<=b;i++)
#define frd(i,a,b) for(i=a;i>+b;i--)
#define sf scanf
#define sf1(a) scanf("%I64d",&a)
#define sf2(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define dsf1(a) scanf("%lf",&a)
#define dsf2(a,b) scanf("%lf %lf",&a,&b)
#define ssf1(a) scanf("%s",&a)
#define ssf2(a,b) scanf(%s %s",&a,&b)

#define pf printf

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007


 LL gcd(LL a, LL b) { return (b != 0 ? gcd(b, a%b) : a);}
LL lcm(LL a, LL b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
int ext=0;
double probability(int ind,int n,int sum)
{
    if(dp[ind]!=0.0)
        return dp[ind];
    if(ind==n)
        return dp[ind]=(double)ar[ind];
    ext+=ar[ind];
    fr(i,ind,n-1)
    {
        dp[i]=1/(n-ind+1)*()
    }

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    LL a,b,c,d,p,q,r,x,y,l,i,j,k,m,n,t,cnt,maxx,minn;
    double xx,yy,pp,qq,dd,rr,mm,nn,aa,bb;
    sf1(t);
    fr(x,0,t)
    {
        sf1(n);
        fr(i,1,n)
        {
               sf1(ar[i]);
               sum+=ar[i];
        }

        probabiloity(1,n,sum);
    }

    return 0;
}



