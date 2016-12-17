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
long long n;
long long rec(long long p)
{
   long long  ans=1;
    while(p--)
    {
        ans=(((10%n)*ans)%n+1)%n;
    }
    if(ans==0)
        return 1;
    else
        return 0;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long a,b,c,d,m,p,x,i,j,q,r,l,cnt;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
        {
            printf("1\n");
            continue;
        }
        d=n;
        cnt=0;
        while(d)
        {
            cnt++;
            d=d/10;
        }
        p=cnt;
        while(1)
        {
            if(rec(p))
            {
                printf("%lld\n",p+1);
                break;
            }
            p++;
        }
    }

    return 0;
}
