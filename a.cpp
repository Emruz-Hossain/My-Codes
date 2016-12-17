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
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

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
 int dp[105][105],visit[105][105],ar[115][115];
 int r,c;
 struct st
 {
     int x,y;
 }dir[105][105];
 int rec(int x,int y)
 {
     int p=0,q=0,s=0,t=0,mx=0;
     if(dp[x][y]!=-1)
        return dp[x][y];
     if(y+1<c&&gcd(ar[x][y],ar[x][y+1])!=1&&ar[x][y]>ar[x][y+1])
     {
         p=rec(x,y+1);
     }
     if(x+1<r&&gcd(ar[x][y],ar[x+1][y])!=1&&ar[x][y]>ar[x+1][y])
     {
          q=rec(x+1,y);
     }
     if(x-1>=0&&gcd(ar[x][y],ar[x-1][y])!=1&&ar[x][y]>ar[x-1][y])
     {
         s=rec(x-1,y);
     }
     if(y-1>=0&&gcd(ar[x][y-1],ar[x][y])!=1&&ar[x][y]>ar[x][y-1])
     {
          t=rec(x,y-1);
     }
     mx=max(p,max(q,max(s,t)));
     if(p==mx&&((x<dir[x][y].x)||(x==dir[x][y].x&&y+1<dir[x][y].y))&&mx!=0)
     {
         dir[x][y].x=x;
         dir[x][y].y=y+1;
     }
     if(q==mx&&((x+1<dir[x][y].x)||(x+1==dir[x][y].x&&y<dir[x][y].y))&&mx!=0)
     {
         dir[x][y].x=x+1;
         dir[x][y].y=y;
     }
    if(s==mx&&((x-1<dir[x][y].x)||(x-1==dir[x][y].x&&y<dir[x][y].y))&&mx!=0)
     {
         dir[x][y].x=x-1;
         dir[x][y].y=y;
     }
      if(t==mx&&((x<dir[x][y].x)||(x==dir[x][y].x&&y-1<dir[x][y].y))&&mx!=0)
     {
         dir[x][y].x=x;
         dir[x][y].y=y-1;
     }
     return dp[x][y]=mx+1;
 }
 vector<int>v;
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int b,d,h,m,n,p,x,y,i,j,k,l,q,t,cnt,sm,tmp,mx,xx,yy;
    char ss[100005];
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<101;i++)
        {
            for(j=0;j<101;j++)
            {
                dir[i][j].x=105;
                dir[i][j].y=105;
            }
        }
        scanf("%s %d %d",&ss,&r,&c);
        if(r==0||c==0)
             printf("%s: 0\n",ss);
        else
        {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&ar[i][j]);
            }
        }
        mx=0;xx=inf;yy=inf;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                p=rec(i,j);
                if((p>mx)||(p==mx&&((xx>i)||(xx==i&&yy>j))))
                {
                    mx=p;
                    xx=i;
                    yy=j;
                }
            }
        }
        printf("%s: %d\n",ss,mx);
        v.clear();
        v.push_back(ar[xx][yy]);
        p=dir[xx][yy].x;q=dir[xx][yy].y;
        xx=p;yy=q;
        while(xx<=100)
        {
            v.push_back(ar[xx][yy]);
            p=dir[xx][yy].x;
           q=dir[xx][yy].y;
           xx=p;yy=q;
        }
        for(i=0;i<v.size();i++)
        {
            printf("%d",v[i]);
            if(i<v.size()-1)
                printf(" ");
        }
        printf("\n");
        }
    }

    return 0;
}
