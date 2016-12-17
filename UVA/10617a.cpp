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
 long long rec(int x,int y)
 {
     if(x>y)
        return 0;
     if(x==y)
        return 1;
     if(dp[x][y]!=-1)
        return dp[x][y];
    if(ss[x]!=ss[y])
     return dp[x][y]=max(dp[x][y],rec(x+1,y)+rec(x,y-1)-rec(x+1,y-1));
     else
        return dp[x][y]=max(dp[x][y],rec(x+1,y)+rec(x,y-1)+1);
 }
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
        mem(dp,-1);
        cout<<rec(0,l-1)<<endl;
    }
    return 0;
}

