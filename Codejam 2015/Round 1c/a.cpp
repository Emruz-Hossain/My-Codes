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
 int w,c,r;
 int visit[25][25];
 int dp[21][21][401][21][2];
 int check(int x,int y,int mx,int my,int dmg)
 {
     int cnt=0,i;
     for(i=0;i<w;i++)
     {
         if(visit[x][y+i]==1&&x!=mx&&y+i!=my)
            cnt++;
     }
     if(cnt==dmg)
        return 1;
     else
        return 0;
 }
 int dmage(int x,int y,int mx,int my)
 {
    if(mx==x&&my>=y&&my<=y+w)
        return 1;
    else
        return 0;
 }
 int rec(int mx,int my,int mov,int p,int dmg)
 {
     int i,j,tmp;
     if(dp[mx][my][mov][dmg][p]!=-1)
        return dp[mx][my][mov][dmg][p];
     if(dmg==w)
        return mov;
     if(p==0)
     {
         int minn=1<<29;
         for(i=0;i<r;i++)
         {
             for(j=0;j<c;j++)
             {
                 if(visit[i][j]==0)
                 {
                     visit[i][j]=1;
                     tmp=rec(i,j,mov+1,1,dmg);
                     minn=min(minn,tmp);
                     visit[i][j]=0;
                 }
             }
         }
         return dp[mx][my][mov][dmg][p]=minn;
     }
     else
     {
         int maxx=0,flag=0;
         for(i=0;i<r;i++)
         {
             for(j=0;j<c-w;j++)
             {
                 if(check(i,j,mx,my,dmg))
                 {
                     flag=1;
                     int q=dmage(i,j,mx,my);
                     tmp=rec(mx,my,mov,0,dmg+q);
                     maxx=max(maxx,tmp);
                 }
             }
         }
     if(flag==1)
         return dp[mx][my][mov][dmg][p]=maxx;
     else
        return dp[mx][my][mov][dmg][p]=mov;
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,d,h,m,n,p,x,y,i,j,k,l,q,t,cnt,sm,tmp;
   sf("%d",&t);
   for(x=1;x<=t;x++)
   {
       mem(dp,-1);mem(visit,0);
       sf("%d %d %d",&r,&c,&w);
       pf("Case #%d: %d\n",x,rec(0,0,0,0,0));
   }
    return 0;
}

