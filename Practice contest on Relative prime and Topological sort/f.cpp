
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
 long long gcd(long long a, long long b) { return (b != 0 ? gcd(b, a%b) : a);}
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
 long long relative[200005],ans[200005];
 void phi_sieve(long long n)
 {
   long long i,j;
     for(i=2;i<=n;i++)
        relative[i]=i;
     for(i=1;i<=n;i++)
     {
         if(relative[i]==i)
         {
             for(j=1;i*j<=n;j++)
             {
                 relative[i*j]-=(relative[i*j]/i);
             }
         }
     }
 }
 long long Find(long long n)
 {
     long long l=1,h=200000,m;
     while(l<=h)
     {
         m=(l+h)/2;
         if(ans[m]==n)
            return m;
         else if(ans[m]>n)
         {
             if(ans[m-1]==n)
                return m-1;
             else if(ans[m-1]<n)
                return m;
            else
                h=m-1;
         }
         else
         {
             if(ans[m+1]>=n)
                return m+1;
             else
                l=m+1;
         }
     }
     return (l+h)/2;
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
 long long a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
  phi_sieve(200000);
  relative[1]=1;
  for(i=1;i<=200000;i++)
  {
      ans[i]=ans[i-1]+relative[i];
  }
  while(sf("%lld",&n)==1)
  {
      if(n==0)
        break;
      if(n==1)
      {
          pf("0/1\n");
          continue;
      }
      n--;
      p=Find(n);
     // pf("%lld %lld %lld\n",ans[p-1],ans[p],ans[p+1]);
      n=n-ans[p-1];
      q=1;
      for(i=1;i<p&&n;i++)
      {
          if(gcd(i,p)==1)
          {
              n--;
              if(n==0)
              {
                  q=i;
                  break;
              }
          }
      }
      printf("%lld/%lld\n",q,p);
  }
    return 0;
}
