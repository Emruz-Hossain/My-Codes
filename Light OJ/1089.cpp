
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
   int x,y;
 }seg[50005];
int ar[150005],look[50005],tree[4*150005],m;
int bs(int val)
{
    int l=1,h=m,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(ar[mid]==val)
            return mid;
        else if(val>ar[mid])
            l=mid+1;
        else
            h=mid-1;
    }
    return 0;
}
void update(int rt,int beg,int endd,int l,int r)
{
    if(beg>=l&&endd<=r)
    {
        tree[rt]++;
        return;
    }
    if(beg>r||endd<l)
        return;
    int mid=(beg+endd)/2;
    update(2*rt,beg,mid,l,r);
    update(2*rt+1,mid+1,endd,l,r);
}
int query(int rt,int beg,int endd,int val,int carry)
{
    if(beg==endd&&beg==val)
    {
        return carry+tree[rt];
    }
    int mid=(beg+endd)/2;
    if(val<=mid)
        return query(2*rt,beg,mid,val,carry+tree[rt]);
    else
        return query(2*rt+1,mid+1,endd,val,carry+tree[rt]);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%d",&t);
   for(x=1;x<=t;x++)
   {
       cnt=1;
       mem(tree,0);
       sf("%d %d",&n,&q);
       for(i=1;i<=n;i++)
       {
           sf("%d %d",&a,&b);
        seg[i].x=a;
        seg[i].y=b;
           ar[cnt++]=a;
           ar[cnt++]=b;
       }
       for(i=1;i<=q;i++)
       {
           sf("%d",&look[i]);
           ar[cnt++]=look[i];
       }
       sort(ar+1,ar+cnt);
       m=1;
       ar[0]=-1;
       for(i=1;i<cnt;i++)
       {
           if(ar[i]!=ar[i-1])
           {
               ar[m++]=ar[i];
           }
           else
            continue;
       }
       m--;
       for(i=1;i<=n;i++)
       {
           a=bs(seg[i].x);
           b=bs(seg[i].y);
           update(1,1,m,a,b);
       }
       pf("Case %d:\n",x);
       for(i=1;i<=q;i++)
       {
           pf("%d\n",query(1,1,m,bs(look[i]),0));
       }
   }

    return 0;
}
