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
//#include<bits/stdc++.h>
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
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}

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
 long long dp[15][15],dir[15][15],row[15],col[15];
 long long MCM(long long beg,long long ed)
 {
     long long mid;
     if(beg>=ed)
        return 0;
     if(dp[beg][ed]!=-1)
        return dp[beg][ed];
   long long mn=(long long)1<<32;
     for(mid=beg;mid<ed;mid++)
     {
         long long q=MCM(beg,mid)+MCM(mid+1,ed)+row[beg]*col[mid]*col[ed];
         if(q<mn)
         {
             mn=q;
             dp[beg][ed]=mn;
             dir[beg][ed]=mid;
         }
     }
     return dp[beg][ed];
 }
 void soln(long long beg,long long ed)
 {
     if(beg==ed)
     {
          pf("A%lld",beg+1);
          return;
     }
     else
     {
         pf("(");
         soln(beg,dir[beg][ed]);
         pf(" x ");
         soln(dir[beg][ed]+1,ed);
         pf(")");
     }

 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   long long a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    t=0;
    while(sf("%lld",&n)==1)
    {
        ++t;
        if(n==0)
            break;
        for(i=0;i<n;i++)
            sf("%lld %lld",&row[i],&col[i]);
        if(n==1)
        {
            pf("Case %lld: (A1)\n",t);
        }
        else
        {
        mem(dp,-1);
        dir[0][0]=0;
        p=MCM(0,n-1);
        pf("Case %lld: ",t,p);
        soln(0,n-1);
        pf("\n");
        }
    }
    return 0;
}

