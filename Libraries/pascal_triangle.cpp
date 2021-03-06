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
int main()
{
      //  freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
  long long i,j,n,ar[100][100];
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        ar[i][0]=ar[i][i]=1;
        for(j=1;j<i;j++)
        {
            ar[i][j]=ar[i-1][j-1]+ar[i-1][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
            printf("%lld ",ar[i][j]);
        printf("\n");
    }
    return 0;
}
