
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
struct st
{
    int p,mx;
};
map<int,map<int,st> >dp;
char ss[1005],rev[1005];
int l;
int rec(int ids,int idr,int p)
{
    int s=0,r=0;
    if(ids>=l||idr>=l)
        return p;
    if(dp[ids][idr].p!=0&&dp[ids][idr].p>=p)
        return dp[ids][idr].mx;
    if(ss[ids]==rev[idr])
        r=rec(ids+1,idr+1,p+1);
    s=rec(ids+1,idr,p);
    dp[ids][idr].p=p;
    return dp[ids][idr].mx=max(s,r);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,q,r,t,cnt,sm,tmp;
    scanf("%d",&t);
    while(t--)
    {
        dp.clear();
        scanf("%s",&ss);
        l=strlen(ss);
        for(i=l-1,j=0;i>=0;i--,j++)
            rev[j]=ss[i];
        printf("%d\n",rec(0,0,0));
    }

    return 0;
}
