
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
     ll f,s;
 }ar[2*100005];
 bool cmp(st a,st b)
 {
     return a.f<b.f;
 }
 ll lb1(ll p,ll q,ll n)
 {
     ll l=0,h=n-1,mid,flag=0;
     while(l<=h)
     {
         mid=(l+h)/2;
         if(ar[mid].f>p)
             h=mid-1;
        else if(ar[mid].f<p&&ar[mid].s>=q)
        {
            flag=1;
            if(mid>0)
            {
                if(ar[mid-1].f<p&&ar[mid-1].s>=q)
                {
                    h=mid-1;
                }
                else
                    break;
            }
            else
                break;
        }
        else
            l=mid+1;
        if(l==h)
        {
            mid=(l+h)/2;
            if(ar[mid].f<p&&ar[mid].s>=q)
                flag=1;
            break;
        }
        if((l+h)/2==mid)
            break;
     }
     if(flag)
        return mid;
     else
        return -1;
 }
 ll up1(ll p,ll q,ll n)
 {
     ll l=0,h=n-1,mid,flag=0;
     while(l<=h)
     {
         mid=(l+h)/2;
         if(ar[mid].f>p)
             h=mid-1;
        else if(ar[mid].f<p&&ar[mid].s>=q)
        {
            flag=1;
            if(ar[mid+1].f<p&&ar[mid+1].s>=q)
                l=mid+1;
            else
             break;
        }
        else
            l=mid+1;
        if(l==h)
        {
            mid=(l+h)/2;
            if(ar[mid].f<p&&ar[mid].s>=q)
                flag=1;
            break;
        }
        if((l+h)/2==mid)
            break;
     }
     if(flag)
        return mid;
     else
        return -2;
 }
  ll lb2(ll p,ll q,ll n)
 {
     ll l=0,h=n-1,mid,flag=0;
     while(l<=h)
     {
         mid=(l+h)/2;
         if(ar[mid].f<p)
             l=mid+1;
        else if(ar[mid].f>p&&ar[mid].s<=q)
        {
            flag=1;
            if(mid>0)
            {
                if(ar[mid-1].f>p&&ar[mid-1].s<=q)
                    h=mid-1;
                else
                    break;
            }
            else
                break;
        }
        else
            h=mid-1;
        if(l==h)
        {
            mid=(l+h)/2;
            if(ar[mid].f>p&&ar[mid].s<=q)
                flag=1;
            break;
        }
        if((l+h)/2==mid)
            break;
     }
     if(flag)
        return mid;
     else
        return -1;
 }
  ll up2(ll p,ll q,ll n)
 {
     ll l=0,h=n-1,mid,flag=0;
     while(l<=h)
     {
         mid=(l+h)/2;
         if(ar[mid].f<p)
             l=mid+1;
        else if(ar[mid].f>p&&ar[mid].s<=q)
        {
            flag=1;
            if(mid+1<=h)
            {
                if(ar[mid+1].f>p&&ar[mid+1].s<=q)
                    l=mid+1;
                else
                    break;
            }
            else
                break;
        }
        else
            h=mid-1;
        if(l==h)
        {
            mid=(l+h)/2;
            if(ar[mid].f>p&&ar[mid].s<=q)
                flag=1;
            break;
        }
        if((l+h)/2==mid)
            break;
     }
     if(flag)
        return mid;
     else
        return -2;
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%lld",&t);
   for(x=1;x<=t;x++)
   {
       sf("%lld %lld",&n,&m);
       for(i=0;i<n;i++)
        sf("%lld %lld",&ar[i].f,&ar[i].s);
        sort(ar,ar+n,cmp);
      sm=0;
      for(i=0;i<m;i++)
      {
          sf("%lld %lld",&a,&b);
          p=lb1(a,b,n);
          q=up1(a,b,n);
          sm+=(q-p+1);
          p=lb2(a,b,n);
          q=up2(a,b,n);
          sm+=(q-p+1);
      }
     pf("Case %lld: %lld\n",x,sm);
   }

    return 0;
}
