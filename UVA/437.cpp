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
    int l,w,h;
}ar[50];
map<int ,map<int ,map<int ,int> > >dp;
int n;
int rec(int l,int w,int height)
{
    int p=0,q=0,r=0,s=0,t=0,i,mx=0;
    if(dp[l][w][height]!=0)
        return dp[l][w][height];
    for(i=0;i<n;i++)
    {
        if(ar[i].l<l&&ar[i].w<w)
            p=rec(ar[i].l,ar[i].w,height+ar[i].h);
        if(ar[i].l<l&&ar[i].h<w)
            q=rec(ar[i].l,ar[i].h,height+ar[i].w);
        if(ar[i].h<l&&ar[i].l<w)
            q=rec(ar[i].h,ar[i].l,height+ar[i].w);
         if(ar[i].h<l&&ar[i].w<w)
            r=rec(ar[i].h,ar[i].w,height+ar[i].l);
        if(ar[i].w<l&&ar[i].h<w)
            s=rec(ar[i].w,ar[i].h,height+ar[i].l);
        if(ar[i].w<l&&ar[i].l<w)
            t=rec(ar[i].w,ar[i].l,height+ar[i].w);
        mx=max(p,max(q,max(r,max(s,max(t,height)))));
    }
    return dp[l][w][height]=mx;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,p,x=0,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    while(1)
    {
        ++x;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&p,&q,&r);
            ar[i].l=p;ar[i].w=q;ar[i].h=r;
        }
        printf("Case %d: maximum height = %d\n",x,rec(inf,inf,0));
    }
    return 0;
}
