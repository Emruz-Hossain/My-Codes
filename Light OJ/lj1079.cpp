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

typedef long long LL;
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
#define eps 1e-6
#define mod  1000000007
long long dp[sz];
struct st
{
    long long m;
    double p;
}ar[sz];
bool cmp(st a,st b)
{
    if(a.p==b.p)
        return(a.m>b.m)?true:false;
    else
    return(a.p<b.p)? true:false;
}
 LL gcd(LL a, LL b) { return (b != 0 ? gcd(b, a%b) : a);}
LL lcm(LL a, LL b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
long long prob(double pp,double pc,long long ind,long long n,long long mn)
{
    long long M,N;
    if(ind==n)
        return mn;
    if(dp[ind]!=0)
        return dp[ind];
    double k=pc+(1-pc)*ar[ind].p;
    if(ind+1<=n)
    {
        if(k<pp)
        M=prob(pp,k,ind+1,n,mn+ar[ind].m);
        N=prob(pp,pc,ind+1,n,mn);
    }
    return dp[ind]=max(M,N);

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    LL a,b,c,d,p,q,r,x,y,l,i,j,k,m,n,t,cnt,maxx,minn;
    double xx,yy,pp,qq,dd,rr,mm,nn,aa,bb;
    sf1(t);
    for(x=1;x<=t;x++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%lf %I64d",&pp,&n);
        for(i=0;i<n;i++)
        {
            scanf("%I64d %lf",&ar[i].m,&ar[i].p);
            ar[i].p+=eps;
        }
        sort(ar,ar+n,cmp);
        printf("Case %I64d: %I64d\n",x,prob(pp,0.0,0,n,0));
    }

    return 0;
}



