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
 int ar[10][10],visit[10][10],dom[10][10],ans;
 void dfs(int tkn)
 {
     int i,j,k,p,q;
     if(tkn>=28)
     {
         ans++;
         return;
     }
    for(i=0;i<7;i++)
    {
        for(j=0;j<8;j++)
        {
            if(visit[i][j]==0)
            {
                for(k=0;k<4;k++)
                {
                    p=i+R[i];
                    q=j+C[j];
                    if(p>=0&&p<7&&q>=0&&q<8&&visit[p][q]==0&&ar[p][q]>=ar[i][j]&&dom[ar[i][j]][ar[p][q]]==0)
                    {
                        visit[i][j]=1;
                        visit[p][q]=1;
                        dom[ar[i][j]][ar[p][q]]=1;
                        dfs(tkn+1);
                        visit[i][j]=0;
                        visit[p][q]=0;
                        dom[ar[i][j]][ar[p][q]]=0;
                    }
                }
            }
        }
    }

 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    sf("%d",&t);
    while(t--)
    {
        for(i=0;i<7;i++)
        {
            for(j=0;j<8;j++)
            {
                sf("%d",&ar[i][j]);
            }
        }
        mem(visit,0);
        mem(dom,0);
        ans=0;
        dfs(0);
        pf("%d\n",ans);
    }
    return 0;
}
