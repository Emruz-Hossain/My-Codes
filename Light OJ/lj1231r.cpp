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
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  100000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
int dp[1005][52],coin[200],occ[200],n,k;
int rec(int ind,int total)
{
    if(ind>=n)
    {
        if(total==k)
            return 1;
        return 0;
    }

    if(total>k)
        return 0;
    if(total==k)
        return 1;
    if(dp[total][ind]!=0)
        return dp[total][ind];
    int M=0;
    for(int i=1;i<=occ[ind];i++)
    {
        int d=coin[ind]*i;
        if(total+d<=k)
            M+=rec(ind+1,total+d)%mod;
        else
            break;
    }
    M+=rec(ind+1,total)%mod;
    return dp[total][ind]=M%mod;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    int i,t,x;
   scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
    memset(dp,0,sizeof(dp));
   scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
       scanf("%d",&coin[i]);
    for(i=0;i<n;i++)
        scanf("%d",&occ[i]);
    printf("Case %d: %d\n",x,rec(0,0));
    }
    return 0;
}
