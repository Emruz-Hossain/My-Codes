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
char prime[1000000000];
void sieve(int n)
{
    int i,j;
    for(i=4;i<=n;i+=2)
        prime[i]='*';
    for(i=3;i*i<=n;i+=2)
    {
        for(j=1;j*i<=n;j+=i)
            prime[i]='*';
    }
}
int main()
{
        //freopen("output.txt","w",stdout);
        //freopen("input.txt","r",stdin);
    double cl;
    ios_base::sync_with_stdio(false);
    int  a,b,c,d,m,n,p,x,i,j,q,r,l;
    scanf("%d",&n);
    cl=(double)clock();
    sieve(n);
    cl=(double)clock()-cl;
    cl/=CLOCKS_PER_SEC;
//    for(i=2;i<n;i++)
//        if(prime[i]!='*')
//            printf("%d ",i);
    printf("Execution time =%.12lf\n",cl);

    return 0;
}

