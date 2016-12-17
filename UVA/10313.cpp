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
unsigned long long  dp[sz];
unsigned long long way(int lb,int ub,int n)
{
    int i,j;
    if(ub<0)
        return 0;
    if(lb==0)
        lb=1;
    dp[0]=1;
    for(i=1;i<=ub;i++)
    {
        for(j=i;j<=n;j++)
        {
            dp[j]=dp[j-i]+dp[j];
        }
    }
    return dp[n];
}
int main()
{
    //freopen("abc.txt","w",stdout);
    int l,i,j,n,lb,ub,x,sum;
    char *p;
    char str[1000];
    while(gets(str))
    {
        sum=0;
        memset(dp,0,sizeof(dp));
        lb=-1;ub=-1;n=-1;
      sscanf(str,"%d %d %d",&n,&lb,&ub);
       if(lb==-1&&ub==-1)
        printf("%lld\n",way(0,n,n));
       else if(ub==-1)
        printf("%lld\n",way(0,lb,n));
       else
       {  unsigned long long p=0,q=0;
            p=way(0,lb-1,n);
            memset(dp,0,sizeof(dp));
           q=way(0,ub,n);
           printf("%llu\n",q-p);
       }


    }
    return 0;
}


