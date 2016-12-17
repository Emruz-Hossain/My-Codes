#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define inf 1<<29
int dp[30001];
int main()
{
    int t,i,j,n,p,x;
    int coin[300];
    scanf("%d",&t);
    while(t--)
    {
        x=30000;
        for(i=1;i<=30000;i++)
            dp[i]=inf;
        scanf("%d",&p);
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&coin[i]);
     for(i=0;i<n;i++)
     {
         for(j=30001-coin[i]-1;j>=0;j--)
         {
             if(dp[j]<inf)
             {
                 dp[j+coin[i]]=min(dp[j+coin[i]] ,dp[j]+1);
             }
         }
     }
     for(i=1;i<=30000;i++)
     {
         if(i<=x&&i>=p&&dp[i]!=inf)
         {
             x=i;
         }
     }
     printf("%d %d\n",x,dp[x]);
     }

    return 0;
}

