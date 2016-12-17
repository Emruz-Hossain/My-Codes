//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct P
{
    double x,y;
    P(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}
long long ar[2*100005],br[2*100005];
long long ffind(long long cr[],long long p,long long n)
{
    long long l,h,mid;
    l=0;h=n;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(cr[mid]>p)
        {
            if(cr[mid-1]<=p)
                return mid-1;
            else if(cr[mid-1]>p)
                h=mid-1;
        }
        else if(cr[mid]<=p)
        {
            if(cr[mid+1]>p)
                return mid;
            else if(cr[mid+1]<=p)
                l=mid+1;
        }
    }
    return mid;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    long long b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mx,pm,qm,lw,hg,md;

    sm=0;cnt=0;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
        scanf("%I64d",&ar[i]);
    scanf("%I64d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%I64d",&br[i]);
    }
    ar[0]=0;
    br[0]=0;
    sort(ar,ar+n+1);
    sort(br,br+m+1);
    mx=-1*1e18;pm=0;
    while(lw<=hg)
    {
        md=(l+h)/2;
        p=ffind(ar,md,n);
    }
        if(ar[i]>0)

        else
            p=ffind(ar,ar[i],n);
        sm=((p-0)*2)+((n-p)*3);
        if(ar[i]>0)
        q=ffind(br,ar[i]-1,m);
        else
            q=ffind(br,ar[i],m);
        cnt=((q-0)*2)+((m-q)*3);
        if(sm-cnt>=mx)
        {
            if(sm-cnt==mx)
            {
                if(sm>pm)
                {
                pm=sm;
                qm=cnt;
                }
            }
            else
            {
                mx=sm-cnt;
                pm=sm;
                qm=cnt;
            }
        }
    }
    printf("%I64d:%I64d\n",pm,qm);
    return 0;
}
