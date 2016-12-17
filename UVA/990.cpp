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

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct st
{
    int d,cn;
}ar[35];
int dp[1005][35];
int m,n,seq[35];
int vi[35];
vector<int>E;
void rec(int d,int itm)
{
    if(dp[d][itm]!=dp[d][itm-1])
    {
        E.push_back(itm);
        if(d-vi[itm]>=0&&itm-1>=0)
        rec(d-vi[itm],itm-1);
    }
    else
    {
        if(itm-1>=0)
        rec(d,itm-1);
    }

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    x=0;
    while(scanf("%d %d",&t,&m)==2)
    {
        ++x;
        E.clear();
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].d,&ar[i].cn);
            vi[i]=3*m*ar[i].d;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<=t;j++)
            {
                if(j-vi[i]>=0)
                {
                    dp[j][i]=max(dp[j][i-1],dp[j-vi[i]][i-1]+ar[i].cn);
                }
                else
                    dp[j][i]=dp[j][i-1];
            }
        }
        if(x>1)
            printf("\n");
        printf("%d\n",dp[t][n-1]);
        rec(t,n-1);
        printf("%d\n",E.size());
        for(i=E.size()-1;i>=0;i--)
        {
            printf("%d %d\n",ar[E[i]].d,ar[E[i]].cn);
        }
    }

    return 0;
}

