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

bool cmp(long long a,long long b)
{
  if(a>b)
    return true;
  else
    return false;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long a,b,c,d,m,n,p,x,i,j,q,r,l,mx,smx;
    long long ar[10000];
    scanf("%lld",&a);
    for(x=1;x<=a;x++)
    {
        mx=0;smx=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
           {
               scanf("%lld",&r);
               if(r>mx)
               {
                   smx=mx;
                   mx=r;
               }
               else if(r>smx)
                smx=r;
           }
        printf("Case %lld: %lld %lld\n",x,mx,smx);
    }

    return 0;
}

