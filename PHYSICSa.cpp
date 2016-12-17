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
bool cmp(long long a,long long b)
{
    return(a>b)?true:false;
}
long long ar[10005];
map<long long ,long long>mp,freq,visit;
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long  a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,f,tt,mx=1e9;
    scanf("%lld",&t);
    while(t--)
    {
      memset(ar,0,sizeof(ar));
      mp.clear();freq.clear();visit.clear();
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            freq[ar[i]]++;
            mx=min(mx,ar[i]);
        }
        //sort(ar,ar+n,cmp);
        for(i=0;i<n;i++)
        {
            for(j=m;j<=ar[i];j*=m)
            {
                if(ar[i]%j==0)
                {
                    k=ar[i]/j;
                     mp[k]+=freq[k];
                }

            }
        }
        tt=0;
        for(i=0;i<n;i++)
        {
            if(visit[ar[i]]==0)
            {
                visit[ar[i]]=1;
                tt+=mp[ar[i]];
                q=freq[ar[i]];
                tt+=(q*(q-1))/2;
            }
        }
        printf("%lld\n",tt);
    }

    return 0;
}
