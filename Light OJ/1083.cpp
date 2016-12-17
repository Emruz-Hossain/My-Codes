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
 struct  st
 {
     ll val,indx;
 }tree[3*30005];
 ll ar[30005];
 void build(ll node, ll beg, ll endd)
 {
     if(beg==endd)
     {
         tree[node].val=ar[beg];
         tree[node].indx=beg;
         return;
     }
     ll mid=(beg+endd)/2;
   build(2*node,beg,mid);
   build(2*node+1,mid+1,endd);
  if(tree[2*node].val<=tree[2*node+1].val)
  {
      tree[node].val=tree[2*node].val;
      tree[node].indx=tree[2*node].indx;
  }
  else
  {
      tree[node].val=tree[2*node+1].val;
      tree[node].indx=tree[2*node+1].indx;
  }
 }
 st query(ll node,ll beg,ll endd,ll l,ll r)
 {
     if(beg>r||endd<l)
     {
       st a;
       a.val=inf;
       a.indx=0;
       return a;
     }
     if(beg>=l&&endd<=r)
        return tree[node];
     ll mid=(beg+endd)/2;
     st p=query(2*node,beg,mid,l,r);
     st q=query(2*node+1,mid+1,endd,l,r);
     return (p.val>q.val)?q:p;
 }
 ll best_area(ll beg,ll endd,ll n)
 {
     if(beg>endd)
        return 0;
     st p=query(1,1,n,beg,endd);
     ll area=p.val*(endd-beg+1);
     return max(area,max(best_area(beg,p.indx-1,n),best_area(p.indx+1,endd,n)));

 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mx;
 sf("%lld",&t);
 for(x=1;x<=t;x++)
 {
     sf("%lld",&n);
     for(i=1;i<=n;i++)
        sf("%lld",&ar[i]);
     build(1,1,n);
     pf("Case %lld: %lld\n",x,best_area(1,n,n));
 }
    return 0;
}

