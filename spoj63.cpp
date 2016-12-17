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
map<int,map<int,int> >dp;
int ar[50],n;
int rec(int ind,int p)
{
    int cs1=0,cs2=0;
    if(ind>2*n)
    {
        if(p==0)
            return 1;
        else
            return 0;
    }
    if(dp[ind][p]!=-1)
        return dp[ind][p];
    if(ar[ind]==1)
        return dp[ind][p]=rec(ind+1,p+1);
    else
    {
        cs1=rec(ind+1,p+1);
        cs2=rec(ind+1,p-1);
        return dp[ind][p]=cs1+cs2;
    }

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    scanf("%d",&t);
    while(t--)
    {
        memset(ar,0,sizeof(ar));
        for(i=0;i<=50;i++)
        {
           for(j=0;j<=100;j++)
           {
               dp[i][j]=-1;
           }
        }
        scanf("%d %d",&n,&k);
        for(i=0;i<k;i++)
        {
            scanf("%d",&p);
            ar[p]=1;
        }
        printf("%d\n",rec(1,0));
    }
    return 0;
}
