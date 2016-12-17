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
#define mod  100000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
long long dp[2505][1005],coin[60],occ[60],n,k,t;
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long x,i,j,r,m,p;
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%lld %lld",&n,&k);
        for(i=1;i<=n;i++)
            scanf("%lld",&coin[i]);
        for(i=1;i<=n;i++)
           scanf("%lld",&occ[i]);
        dp[0][0]=1;
        m=1;
       for(i=1;i<=n;i++)
       {
           p=m-1;
           for(j=1;j<=occ[i];j++)
           {
               long long d=coin[i]*j;
               for(r=0;r<=1000;r++)
               {
                   if(r-d>=0)
                   {
                       if(dp[p][r-d]!=0)
                       {
                           if(dp[m][r]==0)
                            dp[m][r]=((dp[p][r-d]%mod)+(dp[m-1][r]%mod))%mod;
                           else
                            dp[m][r]=((dp[m][r]%mod)+(dp[p][r-d]%mod))%mod;
                       }
                        else
                        dp[m][r]=max(dp[m][r],dp[m-1][r]);
                   }
                   else
                    dp[m][r]=max(dp[m][r],dp[m-1][r]);
               }
               m++;
           }
       }
       printf("Case %lld: %lld\n",x,dp[m-1][k]%mod);

    }
    return 0;
}



