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
int dp[sz][sz];
int rec(int ind,int nw,int cap,int w[],int vl[])
{
    int take,nottake;
    take=nottake=0;
    if(dp[ind][cap]!=0)
        return dp[ind][cap];
    if(ind==nw-1)
    {
        if(w[ind]<=cap)
            return dp[ind][cap]=vl[ind];
        else
            return dp[ind][cap]=0;
    }
    if(w[ind]<=cap)
        take=vl[ind]+rec(ind+1,nw,cap-w[ind],w,vl);
        nottake=rec(ind+1,nw,cap,w,vl);
    return dp[ind][cap]=max(take,nottake);
}
int main()
{
    int w[sz],vl[sz],i,nw,cap,mx;
    memset(dp,0,sizeof(dp));
    scanf("%d",&nw);
    for(i=0;i<nw;i++)
    {
        scanf("%d %d",&w[i],&vl[i]);
    }
    scanf("%d",&cap);
    mx=rec(0,nw,cap,w,vl);
    printf("Max value=%d",mx);
    return 0;
}


