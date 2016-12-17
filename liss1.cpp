
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

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
int dp[1000],ar[1000],n,seq[1000];
int Lis(int u)
{
    int p=0,v;
    if(dp[u]!=-1)
        return dp[u];
    for(v=u+1;v<=n;v++)
    {
        if(ar[v]>ar[u])
        {
            if(Lis(v)>p)
            {
                seq[u]=v;
                p=Lis(v);
            }

        }
    }
    return dp[u]=p+1;
}
void print_seq(int u)
{
    printf("%d ",ar[u]);
    if(seq[u]==-1)
        return;
    print_seq(seq[u]);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mx;
    while(scanf("%d",&n)==1)
    {
        memset(dp,-1,sizeof(dp));
        memset(seq,-1,sizeof(seq));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
        }
        mx=0;
        for(i=1;i<=n;i++)
        {
            p=Lis(i);
            if(p>mx)
            {
                mx=p;
                seq[0]=i;
            }
        }
        printf("Longest Subsequence length= %d\n",mx);
        print_seq(seq[0]);
        printf("\n");
    }

    return 0;
}
