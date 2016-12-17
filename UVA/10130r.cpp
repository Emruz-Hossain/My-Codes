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
struct st
{
    int p,w;
}ar[1005];
int cap,dp[1002][102],n;
int knapsak(int ind,int w)
{
    int M=0,N=0;
    if(ind==n)
        return 0;
    if(dp[ind][w]!=-1)
        return dp[ind][w];
    if(w+ar[ind].w<=cap)
    M=ar[ind].p+knapsak(ind+1,w+ar[ind].w);
    N=knapsak(ind+1,w);
    return dp[ind][w]=max(M,N);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i,sum=0,P;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].p,&ar[i].w);
        }
        scanf("%d",&P);
        sum=0;
        for(i=0;i<P;i++)
        {
             memset(dp,-1,sizeof(dp));
            scanf("%d",&cap);
            sum+=knapsak(0,0);
        }
        printf("%d\n",sum);
    }

    return 0;
}



