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
#include<iomanip>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
int dp[500009][9];
 int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int  a,b,c,d,m,n,p,x,i,j,q,r,l;
    scanf("%d",&n);
    if(n<13)
        printf("0\n");
    else if(n<15)
        printf("1\n");
    else
    {
       p=(n-13)/2;
    for(i=1;i<=7;i++)
        dp[1][i]=1;
    for(i=2;i<=p+1;i++)
    {
        dp[i][1]=1;
        for(j=2;j<=7;j++)
        {
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
        }
    }
        printf("%d\n",dp[p+1][7]);
    }

    return 0;
}

