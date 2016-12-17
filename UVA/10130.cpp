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
#define sz 2000
struct st
{
    int p,w;
}obj[sz];
int dp[sz][40],man[sz];
int main()
{
    int t,th,i,g,j,sum,x,q;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        memset(dp,0,sizeof(dp));
        scanf("%d",&th);
        for(i=1;i<=th;i++)
            scanf("%d %d",&obj[i].p,&obj[i].w);
        scanf("%d",&g);
        for(i=0;i<g;i++)
            scanf("%d",&man[i]);
        for(i=1;i<=th;i++)
        {
            for(j=1;j<=30;j++)
            {
                q=j-obj[i].w;
                if(q>=0)
                    x=obj[i].p+dp[i][q];
                else
                    x=obj[i].p;
                if(dp[i-1][j]<x)
                {
                    dp[i][j]=x;
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        for(i=0;i<g;i++)
            sum+=dp[th][man[i]];
        printf("%d\n",sum);

    }
    return 0;
}


