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
#define sz 300
int w[sz],vl[sz],dp[sz],taken[sz];
int take,wnum;
int Max(int a,int b)
{
    return a>b?a:b;
}
void rec(int ind,int rs,int cap)
{
    int i,p,j;
    for(i=ind;i<=take;i++)
    {
        for(j=w[i];j<=cap;j++)
        {
            if(w[i]<=rs&&taken[i]==0)
            {
                taken[i]=1;
                p=cap-rs+w[i];
                dp[p]=Max(dp[p],dp[cap-rs]+vl[i]);
                rec(++i,rs-w[i],cap);
                taken[i]=0;
            }
        }
    }
}
int main()
{
    int cap,i,mx=0,mxw;
    scanf("%d",&wnum);
    for(i=1;i<=wnum;i++)
    {
        scanf("%d %d",&w[i],&vl[i]);
    }
    scanf("%d",&cap);
    memset(dp,0,sizeof(dp));
    memset(taken,0,sizeof(taken));
    take=wnum;
   rec(1,cap,cap);
   for(i=1;i<=cap;i++)
   {
       if(mx<dp[i])
       {
            mx=dp[i];
            mxw=i;
       }

   }
   printf("Max weight=%d\nMax value=%d\n",mxw,mx);
    return 0;
}


