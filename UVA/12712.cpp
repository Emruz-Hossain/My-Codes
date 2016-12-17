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
#define mod  1000000000007
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
    map<long long,long long>Pow;
}V[10005];
map<long long ,long long>visit;
vector<long long>E;
long long CP(long long n,long long p)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        long long ret=(CP(n,p/2))%mod;
        return  (ret*ret)%mod;
    }
    else
    {
        return (n*CP(n,p-1))%mod;
    }
}
void factorize(long long p)
{
    long long i;
    long long d=p;
    if(d%2==0)
    {
        if(visit[2]==0)
        {
            E.push_back(2);
            visit[2]=1;
        }
        while(d%2==0)
        {
            V[p].Pow[2]++;
            d=d/2;
        }
    }
    for(i=3;i*i<=d;i++)
    {
        if(d%i==0)
        {
            if(visit[i]==0)
            {
                E.push_back(i);
                visit[i]=1;
            }
            while(d%i==0)
            {
                 V[p].Pow[i]++;
                d=d/i;
            }
        }
    }
    if(d>0)
    {
        if(visit[d]==0)
        {
            visit[d]=1;
            E.push_back(d);
        }
         V[p].Pow[d]++;
    }
    for(i=0;i<E.size();i++)
    {
        V[p].Pow[E[i]]+=V[p-1].Pow[E[i]];
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,ans;
    for(i=1;i<=10004;i++)
    {
         factorize(i);
    }
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
    {
        ans=0;
        scanf("%lld %lld %lld",&l,&m,&n);
        d=l*l;
        for(i=m;i<=n;i++)
        {
            k=d-i;y=1;
            for(j=0;j<E.size();j++)
            {
                r=V[d].Pow[E[j]]-V[k].Pow[E[j]];
                sm=CP(E[j],r);
                y=(y*sm)%mod;
            }
            ans=(ans+y)%mod;
        }
        printf("Case %lld: %lld\n",x,ans);
    }
return 0;
}
