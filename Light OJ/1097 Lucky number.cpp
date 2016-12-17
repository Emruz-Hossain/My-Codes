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
#define     sz 1429435
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
 int tree[4*sz],ar[sz];
 void build(int rt,int beg,int en)
 {
     if(beg==en)
     {
         tree[rt]=beg&1;
         return;
     }
     int mid=(beg+en)/2;
     build(2*rt,beg,mid);
     build(2*rt+1,mid+1,en);
     tree[rt]=tree[2*rt]+tree[2*rt+1];
 }
 int query(int rt,int beg,int en,int val)
 {
     if(beg==en)
        return beg;
     int mid=(beg+en)/2;
     if(tree[2*rt]>=val)
        return query(2*rt,beg,mid,val);
     else
        return query(2*rt+1,mid+1,en,val-tree[2*rt]);
 }
 void update(int rt,int beg,int en,int val)
 {
     if(beg==en)
     {
         tree[rt]=0;
         return;
     }
     int mid=(beg+en)/2;
     if(tree[2*rt]>=val)
        update(2*rt,beg,mid,val);
     else
        update(2*rt+1,mid+1,en,val-tree[2*rt]);
     tree[rt]=tree[2*rt]+tree[2*rt+1];
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   build(1,1,sz);
   ar[1]=1;
   for(i=2;i<=100000;i++)
   {
       p=query(1,1,sz,i);
       ar[i]=p;
       j=(sz/p)*p;
       for(;j>=p;j-=p)
       {
           update(1,1,sz,j);
       }
   }
   sf("%d",&t);
       for(x=1;x<=t;x++)
       {
           sf("%d",&n);
           pf("Case %d: %d\n",x,ar[n]);
       }

    return 0;
}

