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
long long prm[10000009],r,ans[10000009];
int ar[10000009];
char ss[10000000];
void sieve(long long n)
{
    long long i,j;
    for(i=4;i<=n;i+=2)
        ar[i]=1;
    for(i=3;i*i<=n;i+=2)
    {
        for(j=2;j*i<=n;j++)
            ar[i*j]=1;
    }
    prm[0]=2;
    r=1;
    for(i=3;i<=n;i+=2)
    {
        if(ar[i]==0)
            prm[r++]=i;
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long a,b,c,d,m,n,p,x,i,j,q,r,l,k,t;
    sieve(10000000);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",&ss);
        if(strlen(ss)>17)
        {
            printf("1\n");
            printf("%s\n",ss);
        }
        else
        {
        sscanf(ss,"%lld",&n);
        k=0;
        q=0;
        while(n>prm[k])
        {
            if(n%prm[k]==0)
            {
                while(n%prm[k]==0)
                {
                    ans[q++]=prm[k];
                    n/=prm[k];
                    if(q>10000000)
                        break;
                }

            }
            k++;
            if(k>r||q>10000000)
                    break;
        }
        if(n>1)
            ans[q++]=n;
        printf("%lld\n",q);
        for(i=0;i<q;i++)
            printf("%lld\n",ans[i]);
        }
    }

    return 0;
}

