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
#include<ctime>
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

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
int ar[105][105],dp[105][105],n,m;
int rec(int x,int y)
{
    int p=0,q=0,r=0,s=0,chkr=0;
    if(dp[x][y]!=0)
        return dp[x][y]+1;
    if(x+1<m&&ar[x+1][y]<ar[x][y])
    {
          p=rec(x+1,y);
          chkr=1;
    }
    if(x-1>=0&&ar[x-1][y]<ar[x][y])
    {
         q=rec(x-1,y);
         chkr=1;
    }
    if(y+1<n&&ar[x][y+1]<ar[x][y])
    {
         r=rec(x,y+1);
         chkr=1;
    }
    if(y-1>=0&&ar[x][y-1]<ar[x][y])
    {
         s=rec(x,y-1);
         chkr=1;
    }
    dp[x][y]=max(p,max(q,max(r,s)));
    if(chkr==0)
        return 1;
    else
    return dp[x][y]+1;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mx;
    char ss[100005];
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%s %d %d",&ss,&m,&n);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&ar[i][j]);
            }
        }
        mx=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
               mx=max(mx,rec(i,j));

            }
        }
        printf("%s: %d\n",ss,mx);
    }

    return 0;
}
