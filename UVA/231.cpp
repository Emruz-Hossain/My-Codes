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
struct st
{
    int cur,mx;
};
map<int,map<int,st> >dp;
int d,ar[100005];
int rec(int last,int ind,int p)
{
    int r=0,q=0;
    if(ind>=d)
    {
        return p;
    }
    if(dp[ind][last].cur>p)
        return dp[ind][last].mx;
    if(ar[ind]<=last)
    r=rec(ar[ind],ind+1,p+1);
    q=rec(last,ind+1,p);
    dp[ind][last].cur=p;
    return dp[ind][last].mx=max(r,q);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    x=0;
    while(1)
    {
        ++x;
        dp.clear();
        scanf("%d",&n);
        if(n==-1)
            break;
        ar[0]=n;
        d=1;
        while(1)
        {
            scanf("%d",&p);
            if(p==-1)
                break;
            else
                ar[d++]=p;
        }
        if(x!=1)
            printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n",x,rec(inf,0,0));
    }

    return 0;
}
