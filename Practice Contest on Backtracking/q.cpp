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
 int board[12][12],tt,visit[12][12],ans,n,m;
 void backtrack(int x,int y,int cnt)
 {
     int i,p,q;
     ans=min(ans,tt-cnt);
     for(i=0;i<8;i++)
     {
         p=x+KR[i];
         q=y+KC[i];
         if(p>=0&&p<11&&q>=0&&q<11&&board[p][q]==1&&visit[p][q]==0)
         {
             visit[p][q]=1;
             backtrack(p,q,cnt+1);
             visit[p][q]=0;
         }
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,p,x,y,i,j,k,l,q,r,t=0,cnt,sm,tmp;
    while(1)
    {
        ++t;
        sf("%d",&n);
        if(n==0)
            break;
        mem(board,0);
        tt=0;
        m=0;
        for(i=0;i<n;i++)
        {
            sf("%d %d",&p,&q);
            m=max(m,p+q);
            for(j=p;j<p+q;j++)
            {
                board[i][j]=1;
                tt++;
            }
        }
        mem(visit,0);
        ans=100005;
        visit[0][0]=1;
        backtrack(0,0,1);
        if(ans==1)
        {
             pf("Case %d, %d square can not be reached.\n",t,ans);
        }
        else
        pf("Case %d, %d squares can not be reached.\n",t,ans);

    }
    return 0;
}
