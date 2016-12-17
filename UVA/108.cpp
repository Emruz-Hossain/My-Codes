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
int ar[105][105],sum[105][105];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mx;
    while(scanf("%d",&n)==1)
    {
        memset(sum,0,sizeof(sum));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            sum[i][j]=ar[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }
    mx=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            mx=max(mx,sum[i][j]);
            for(k=1;k<i;k++)
            {
                r=sum[i][j]-sum[k][j];
                mx=max(r,mx);
            }
            for(k=0;k<i;k++)
            {
                for(l=1;l<j;l++)
                {
                    r=sum[i][j]-sum[i][l]-sum[k][j]+sum[k][l];
                    mx=max(mx,r);
                }
            }
        }
    }
    printf("%d\n",mx);
    }
    return 0;
}
