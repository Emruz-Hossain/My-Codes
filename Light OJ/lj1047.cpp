//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
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

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct st
{
    int r,g,b;
}ar[30];
int dp[25][4][20003];
int n;
int rec(int ind,int clr,int cst)
{
    int cs1,cs2,cs3;
    if(ind>=n)
    {
        return cst;
    }
    if(dp[ind][clr][cst]!=-1)
        return dp[ind][clr][cst];
    if(clr==0)
    {
        cs1=rec(ind+1,1,cst+ar[ind].r);
        cs2=rec(ind+1,2,cst+ar[ind].g);
        cs3=rec(ind+1,3,cst+ar[ind].b);
        return dp[ind][clr][cst]=min(cs1,min(cs2,cs3));
    }
    else if(clr==1)
    {
        cs2=rec(ind+1,2,cst+ar[ind].g);
        cs3=rec(ind+1,3,cst+ar[ind].b);
        return dp[ind][clr][cst]=min(cs2,cs3);
    }
    else if(clr==2)
    {
        cs1=rec(ind+1,1,cst+ar[ind].r);
        cs3=rec(ind+1,3,cst+ar[ind].b);
        return dp[ind][clr][cst]=min(cs1,cs3);
    }
    else if(clr==3)
    {
        cs1=rec(ind+1,1,cst+ar[ind].r);
        cs2=rec(ind+1,2,cst+ar[ind].g);
        return dp[ind][clr][cst]=min(cs1,cs2);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d %d",&ar[i].r,&ar[i].g,&ar[i].b);
        printf("Case %d: %d\n",x,rec(0,0,0));
    }

    return 0;
}
