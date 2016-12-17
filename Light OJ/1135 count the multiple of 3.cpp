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
#define     all(v) v.begin(),v.end()
#define     sf scanf
#define     pf printf
#define     read(n) scanf("%d",&n)
#define     read2(m,n) scanf("%d %d",&m,&n)
#define     read3(m,n,p) scanf("%d %d %d",&m,&n,&p)
#define     readl(n) scanf("%I64d",&n);
#define     readl2(m,n) scanf("%I64d %I64d",&m,&n)
#define     readl3(m,n,p) scanf("%I64d %I64d %I64d",&m,&n,&p)

#define     inf 1<<25
#define     sz 20002
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
 struct st
 {
     int prop,cnt[4];
 } tree[4*100004];

 void build(int rt,int beg,int endd)
 {
     tree[rt].prop=0;
     if(beg==endd)
     {
         tree[rt].cnt[0]=1;
         tree[rt].cnt[1]=tree[rt].cnt[2]=0;
         return;
     }
     int mid=(beg+endd)/2;
     build(2*rt,beg,mid);
     build(2*rt+1,mid+1,endd);
     for(int i=0;i<3;i++)
        tree[rt].cnt[i]=tree[2*rt].cnt[i]+tree[2*rt+1].cnt[i];
 }
 int get_value(int rt,int indx)
 {
     int n=(tree[rt].prop)%3;
     while(n--)
     {
         indx--;
         if(indx==-1)
            indx=2;
     }
     return tree[rt].cnt[indx];
 }
  int get_value2(int rt,int indx,int prop)
 {
     int n=(tree[rt].prop+prop)%3;
     while(n--)
     {
         indx--;
         if(indx==-1)
            indx=2;
     }
     return tree[rt].cnt[indx];
 }
  void propagate(int rt)
 {
     tree[2*rt].prop+=tree[rt].prop;
     tree[2*rt].prop%=3;
     tree[2*rt+1].prop+=tree[rt].prop;
     tree[2*rt+1].prop%=3;
     tree[rt].prop=0;
 }
 void update(int rt,int beg,int endd,int l,int r)
 {
     if(beg>=l&&endd<=r)
     {
         tree[rt].prop++;
         tree[rt].prop%=3;
         return;
     }
     if(beg>r||endd<l)
        return;
     propagate(rt);
     int mid=(beg+endd)/2;
     if(mid>=l)
     update(2*rt,beg,mid,l,r);
     if(r>mid)
     update(2*rt+1,mid+1,endd,l,r);
     for(int i=0;i<3;i++)
        tree[rt].cnt[i]=get_value(2*rt,i)+get_value(2*rt+1,i);
 }
 int query(int rt,int beg,int endd,int l,int r,int prop)
 {
     if(beg>=l&&endd<=r)
     {
         return get_value2(rt,0,prop);
     }
     if(beg>r||endd<l)
        return 0;
     int mid=(beg+endd)/2;
     return query(2*rt,beg,mid,l,r,prop+tree[rt].prop)+query(2*rt+1,mid+1,endd,l,r,prop+tree[rt].prop);
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   read(t);
   for(x=1;x<=t;x++)
   {
       read2(n,q);
       m=4*n;
       build(1,1,n);
       pf("Case %d:\n",x);
       while(q--)
       {
           read3(a,b,c);
           if(a==0)
           {
               update(1,1,n,b+1,c+1);
           }
           else
           {
               pf("%d\n",query(1,1,n,b+1,c+1,0));
           }
       }
   }
    return 0;
}
