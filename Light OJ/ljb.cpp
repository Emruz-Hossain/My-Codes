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
map<long long,long long>mp;
long long ar[100000];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long p,t,x,i,q,n;
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
    {
        mp.clear();
        scanf("%lld %lld",&n,&q);
        for(i=0;i<n;i++)
        {
             scanf("%lld",&p);
             mp[p]++;
        }

        for(i=0;i<q;i++)
        {
            scanf("%lld",&ar[i]);
        }
        printf("Case %lld: ",x);
        for(i=0;i<q;i++)
        {
            if(mp[ar[i]]==0)
                printf("No");
            else
                printf("%lld",mp[ar[i]]);
            if(i<q-1)
                printf(" ");

        }
        printf("\n");

    }

    return 0;
}
