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
int dp[120][120][120],mm,nn;
int rec(int ia,int ib,int ll,int ar[],int br[])
{
    int p=0,r=0;
    if(ia>=mm||ib>=nn)
    {
        return ll;
    }
    if(dp[ia][ib][ll]!=-1)
        return dp[ia][ib][ll];
    if(ar[ia]==br[ib])
    {
        p=rec(ia+1,ib+1,ll+1,ar,br);
    }
    else
    {
        p=rec(ia,ib+1,ll,ar,br);
    }
    r=rec(ia+1,ib,ll,ar,br);
    return dp[ia][ib][ll]=max(p,r);
}
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,n,m;
    int ar[200],br[200];
    x=0;
    while(1)
    {
        ++x;
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<m;i++)
            scanf("%d",&br[i]);
        nn=max(m,n);
        mm=min(m,n);
        if(n>m)
        {
            p=rec(0,0,0,br,ar);
        }
        else
            p=rec(0,0,0,ar,br);
        printf("Twin Towers #%d\n",x);
        printf("Number of Tiles : %d\n",p);
        printf("\n");
    }

    return 0;
}
