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
 int ans,visit[10][10];
 vector<int>row,col;
 struct st
 {
     int rw,clm;
 }ar[10];
 vector<st>E[1000],v;
 void SET(int x,int y,int p)
 {
     int i,j;
     for(i=y;i<8;i++)
        visit[x][i]+=p;
    for(i=y;i>=0;i--)
        visit[x][i]+=p;
     for(i=x;i<8;i++)
        visit[i][y]+=p;
    for(i=x;i>=0;i--)
        visit[i][y]+=p;
     for(i=x,j=y;i<8&&j<8;i++,j++)
        visit[i][j]+=p;
     for(i=x,j=y;i>=0&&j>=0;i--,j--)
        visit[i][j]+=p;
     for(i=x,j=y;i<8&&j>=0;i++,j--)
        visit[i][j]+=p;
     for(i=x,j=y;i>=0&&j<8;i--,j++)
        visit[i][j]+=p;
 }
 bool cmp(st a, st b){return a.clm<b.clm;};
 void backtrack(int ind)
 {
     int i;
     if(ind>=8)
     {
         for(i=0;i<8;i++)
            E[ans].push_back(v[i]);
        sort(E[ans].begin(),E[ans].end(),cmp);
         ans++;
         return;
     }
     for(i=0;i<8;i++)
     {
         if(visit[ind][i]==0)
         {
             SET(ind,i,1);
             st a;
             a.rw=ind;
             a.clm=i;
             v.push_back(a);
             backtrack(ind+1);
             v.pop_back();
             SET(ind,i,-1);
         }
     }
 }
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t=0,cnt,sm,tmp,mn;
   ans=0;
    backtrack(0);
    while(scanf("%d %d %d %d %d %d %d %d",&ar[0].rw,&ar[1].rw,&ar[2].rw,&ar[3].rw,&ar[4].rw,&ar[5].rw,&ar[6].rw,&ar[7].rw)==8)
    {
        for(i=0;i<8;i++)
        {
            ar[i].clm=i;
            ar[i].rw--;
        }
        mn=10;
        for(i=0;i<ans;i++)
        {
            sm=0;
            for(j=0;j<8;j++)
            {
                if(E[i][j].rw!=ar[j].rw)
                sm++;
            }
          mn=min(sm,mn);
        }
        pf("Case %d: %d\n",++t,mn);
    }
    return 0;
}
