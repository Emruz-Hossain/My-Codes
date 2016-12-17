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
typedef long long ll;
#define     mem(x,y) memset(x,y,sizeof(x))
#define     PB(x) push_back(x)
#define     POB() pop_back()
#define     SZ(a) a.size()
#define     len(a) strlen(a)
#define     sf scanf
#define     pf printf

#define     inf 1<<25
#define     sz 2000
#define     eps 1e-9
#define     mod  1000000007
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
 int ar[10005],br[165];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int a,b,c,d,h,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,aa,bb,cc,dd,ansa,ansb,ansc;
    double cost,mx,m;
    sf("%d",&t);
    for(x=1;x<=t;x++)
    {
        mem(br,0);
        sf("%d",&n);
        for(i=0;i<n;i++)
        {
            sf("%d",&ar[i]);
            p=ar[i];
            for(j=0;j<=160;j++)
            {
                if(p<=j)
                    br[j]++;
            }
        }
        m=(double)n/4.00;
        mx=9999999.00;
        for(a=0;a<160;a++)
        {
            for(b=a+1;b<160;b++)
            {
                for(c=b+1;c<160;c++)
                {
                    aa=br[a];
                    bb=br[b]-aa;
                    cc=br[c]-bb;
                    dd=br[160]-cc;
                    cost=fabs(m-aa)+fabs(m-bb)+fabs(m-cc)+fabs(m-dd);
                    if(cost<mx)
                    {
                        mx=cost;
                        ansa=a;
                        ansb=b;
                        ansc=c;
                    }
                }
            }
        }
        pf("Case %d: %d %d %d\n",x,ansa,ansb,ansc);

    }
    return 0;
}

