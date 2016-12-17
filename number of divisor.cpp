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
vector<long long>prime;
int PR[1000009];
void sieve(long long n)
{
    prime.clear();
    long long  i,j;
    for(i=4;i<=n;i+=2)
        PR[i]=1;
    for(i=3;i*i<=n;i+=2)
    {
        for(j=2;j*i<=n;j++)
        {
            PR[i*j]=1;
        }
    }
    for(i=2;i<1000000;i++)
    {
        if(PR[i]!=1)
            prime.push_back(i);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long a,b,c,d,m,n,p,x,i,j,q,r,l,ans,cnt;
    sieve(1000000);
    while(scanf("%lld",&n)==1)
    {
        ans=1;
        d=n;
        for(i=0;prime[i]<n;i++)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
            }
            ans*=(cnt+1);
        }
        if(n>1)
            ans=ans*2;
        printf("Number of Divisor of %lld is %lld\n",d,ans);
    }

    return 0;
}
