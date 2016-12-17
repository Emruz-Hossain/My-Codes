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
    int fq[200];
}ar[1005];
int check(int l,int h)
{
    int i,p=0;
    for(i='a';i<='z';i++)
    {
        if((ar[h].fq[i]-ar[l-1].fq[i])%2!=0)
            p++;
    }
    if(p<=1)
        return 1;
    else
        return 0;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,ans;
    char ss[1005];
    double cl=clock();
 //sieve();
 scanf("%d",&n);
for(x=1;x<=n;x++)
{
    for(i=0;i<1002;i++)
    {
        for(j='a';j<='z';j++)
            ar[i].fq[j]=0;
    }
    scanf("%s",&ss);
    l=strlen(ss);
    for(i=0;i<l;i++)
    {
        for(j='a';j<='z';j++)
        {
            ar[i+1].fq[j]=ar[i].fq[j];
        }
        ar[i+1].fq[ss[i]]++;
    }
    ans=0;
    for(i=0;i<l;i++)
    {
        for(j=i;j<l;j++)
        {
            p=check(i+1,j+1);
            if(p==1)
                ans++;
        }
    }
    printf("Case %d: %d\n",x,ans);
}

    return 0;
}
