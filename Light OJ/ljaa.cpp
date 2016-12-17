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
struct st
{
    long long a,b;
};
st ar[100005];
bool cmp(st a,st b)
{
    if(a.b>b.b)
        return true;
    else if(a.b==b.b)
    {
        if(a.a>b.a)
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long a,b,c,d,m,n,p,x,i,j,q,r,l;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld",&ar[i].a,&ar[i].b);
        }
        sort(ar,ar+n,cmp);

    p=1;
    i=0;
    r=0;
    while(p--)
    {
        p+=ar[i].b;
        r+=ar[i].a;
        i++;
        if(i>=n)
            break;
    }
    r=r*1000;
    printf("%lld\n",r);
    }
    return 0;
}
