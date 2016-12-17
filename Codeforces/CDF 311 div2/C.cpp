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
#define     fr(s,e,in) for(i=s;i<=e;i+=in)
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
 int cost[400];
 struct st
 {
     int len,pc;
 }ar[100005];
 bool cmp(st a,st b)
 {
     return a.len<b.len;
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   mem(cost,0);
   read(n);
   fr(0,n-1,1)
   {
       read(ar[i].len);
   }
   fr(0,n-1,1)
   {
       read(p);
       cost[p]++;
       ar[i].pc=p;
   }
   sort(ar,ar+n,cmp);
   sm=n*200;
   j=n-1;
   int cur=0;
   for(i=n-1;i>=0;i--)
   {
       while(j>=0&&ar[i].len==ar[j].len)
       {
           cost[ar[j].pc]--;
           j--;
       }
       m=i-j;
       tmp=cur;
       int del=max(0,i-(2*m-1)+1);
       for(k=1;k<=200;k++)
       {
           q=min(cost[k],del);
           tmp+=q*k;
           del-=q;
       }
       cur+=ar[i].pc;
       sm=min(sm,tmp);
   }
   pf("%d\n",sm);

    return 0;
}
//4
//3 3 1 1
//2 3 4 5
