//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
typedef long long ll;
#define     mem(x,y) memset(x,y,sizeof(x))
#define     PB(x) push_back(x)
#define     POB() pop_back()
#define     SZ(a) a.size()
#define     len(a) strlen(a)
#define     sf scanf
#define     pf printf

#define     inf 1<<25
#define     sz 2000
#define     eps 1e-9
#define     mod  1000000007
 long long dp[61][61];
 char ss[61];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
  long long a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    sf("%lld",&t);
    while(t--)
    {
        sf("%s",&ss);
        l=strlen(ss);
       for(i=0;i<=l;i++)
       {
           for(j=0;j<=l;j++)
            dp[i][j]=1;
       }
       for(i=0;i<l;i++)
       {
           if(ss[i]==ss[i+1])
            dp[i][i+1]=3;
           else
            dp[i][i+1]=2;
       }
       for(i=2;i<l;i++)
       {
           for(x=0;x+i<l;x++)
           {
               y=x+i;
               if(ss[x]==ss[y])
                dp[x][y]=1+dp[x+1][y]+dp[x][y-1];
               else
                dp[x][y]=dp[x+1][y]+dp[x][y-1]-dp[x+1][y-1];
           }
       }
       pf("%lld\n",dp[0][l-1]);
    }
    return 0;
}


