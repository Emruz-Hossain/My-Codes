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
#define sz 20000
struct st
{
    int p,fv;
}dp[100][sz],in[200];
int main()
{
    int bdg,n,i,j,q,x,w,k;
    while(scanf("%d %d",&bdg,&n)==2)
    {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            scanf("%d %d",&in[i].p,&in[i].fv);
        for(i=1;i<=n;i++)
        {
            for(j=in[i].fv;j<=15;j++)
            {
                q=j-in[i].fv;
                if(q>=0)
                {
                     x=dp[i][q].p+in[i].p;
                     w=dp[i][q].fv+in[i].fv;
                }

                else
                   {
                       x=in[i].p;
                       w=in[i].fv;
                   }
                if(x>2000)
                    k=bdg+200;
                else
                    k=bdg;
                if(dp[i-1][j].fv<w&&x<=k)
                {
                    dp[i][j].p=x;
                    dp[i][j].fv=w;

                }
                else
                {
                    dp[i][j].p=dp[i-1][j].p;
                    dp[i][j].fv=dp[i-1][j].fv;

                }

            }
        }
        printf("%d\n",dp[n][15].fv);
    }
    return 0;
}


