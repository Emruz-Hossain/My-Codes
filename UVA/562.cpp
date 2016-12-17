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
#define inf 1<<25
#define sz 25005
int coin[sz];
int dp[sz];
int main()
{
    int n,i,t,m,j ,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
         scanf("%d",&coin[i]);
         sum+=coin[i];
    }
       m=sum/2;
    for(i=1;i<=n;i++)
    {
        for(j=m;j>=1;j--)
        {
            if(dp[j]==0)
            {
                dp[j]=(coin[i]<=j)? dp[j-coin[i]]:0;
            }
        }
    }
    for(i=m;i>=1;i--)
        if(dp[i]==1)
            break;
    printf("%d\n",sum-2*i);
    }
    return 0;
}
