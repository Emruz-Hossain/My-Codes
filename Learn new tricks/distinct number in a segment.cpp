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
 struct st
 {
     int indx,val,is_query,indx_of_query,l;
 }ar[230005];
 int visit[1000005]={0},ans[200005],tree[4*230005];
 bool cmp(st a, st b)
 {
     if(a.indx==b.indx)
        return a.val>b.val;
    return a.indx<b.indx;
 }
 void update(int rt,int beg,int en, int indx)
 {
     if(beg==en)
     {
         tree[rt]^=1;
         return;
     }
     int mid=(beg+en)/2;
     if(indx<=mid)
        update(2*rt,beg,mid,indx);
     else
        update(2*rt+1,mid+1,en,indx);
     tree[rt]=tree[2*rt]+tree[2*rt+1];
 }
 int query(int rt,int beg,int en,int l,int r)
 {
     if(beg>r||en<l)
        return 0;
     if(beg>=l&&en<=r)
        return tree[rt];
     int mid=(beg+en)/2;
     return query(2*rt,beg,mid,l,r)+query(2*rt+1,mid+1,en,l,r);
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
     sf("%d",&n);
     for(i=1;i<=n;i++)
     {
         sf("%d",&p);
         ar[i].val=p;
         ar[i].indx=i;
         ar[i].is_query=0;
     }
     sf("%d",&q);
     for(i=1;i<=q;i++)
     {
         sf("%d %d",&l,&r);
         ar[n+i].indx=r;
         ar[n+i].is_query=1;
         ar[n+i].l=l;
         ar[n+i].indx_of_query=i;
         ar[n+i].val=0;
     }
     sort(ar+1,ar+n+q+1,cmp);
     for(i=1;i<=n+q;i++)
     {
         if(ar[i].is_query)
         {
             ans[ar[i].indx_of_query]=query(1,1,n,ar[i].l,ar[i].indx);
         }
         else
         {
             p=ar[i].val;
             if(visit[p]!=0)
             {
                 update(1,1,n,visit[p]);
             }
             update(1,1,n,ar[i].indx);
             visit[p]=ar[i].indx;
         }
     }
     for(i=1;i<=q;i++)
     {
         pf("%d\n",ans[i]);
     }
    return 0;
}
//15
//1 2 1 3 4 1 2 6 5 3 2 1 3 5 4
//9
//1 7
//2 9
//8 15
//1 5
//6 9
//2 11
//5 14
//6 13
//1 15
