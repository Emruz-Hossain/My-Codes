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
#define sz 200
int main()
{
    int w[sz],vl[sz],i,j,dp[sz][sz],nw,cap;
    scanf("%d",&nw);
    for(i=0;i<nw;i++)
    {
        scanf("%d %d",&w[i],&vl[i]);
    }
    scanf("%d",&cap);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=nw;i++)
    {
        for(j=0;j<=cap;j++)
        {
            if(w[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],vl[i-1]+dp[i-1][j-w[i-1]]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    printf("Max value=%d",dp[nw][cap]);
    return 0;
}


