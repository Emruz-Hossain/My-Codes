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
 int ar[100005],tree[3*100005];
 void build(int node,int beg,int endd)
 {
     int mid;
     if(beg==endd)
     {
         tree[node]=ar[beg];
         return;
     }
     mid=(beg+endd)/2;
     build(2*node,beg,mid);
     build(2*node+1,mid+1,endd);
     tree[node]=tree[2*node]+tree[2*node+1];
 }
 int query(int node,int beg,int endd,int l,int r)
 {
     int mid,ans;
     if(beg>r||endd<l)
        return 0;
     if(beg>=l&&endd<=r)
        return tree[node];
     mid=(beg+endd)/2;
     return ans=query(2*node,beg,mid,l,r)+query(2*node+1,mid+1,endd,l,r);
 }
 void update(int node,int beg,int endd,int ind,int val)
 {
     int mid;
     if(beg>ind||endd<ind)
        return;
     if(beg>=ind&&endd<=ind)
     {
         tree[node]=val;
         return;
     }
    mid=(beg+endd)/2;
    update(2*node,beg,mid,ind,val);
    update(2*node+1,mid+1,endd,ind,val);
    tree[node]=tree[2*node]+tree[2*node+1];
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%d %d",&n,&q);
   for(i=1;i<=n;i++)
    sf("%d",&ar[i]);
   build(1,1,n);
   while(q--)
   {
       sf("%d",&tmp);
       if(tmp==0)
       {
           int ind,val;
            sf("%d %d",&ind,&val);
            update(1,1,n,ind,val);
       }
       else
       {
         sf("%d %d",&l,&r);
         pf("%d\n",query(1,1,n,l,r));
       }

   }
    return 0;
}

