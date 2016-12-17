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
vector<int>V[105];
int n;
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j,k,r,x,t,d,p;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%d",&n);
        d=ceil((2*n-1)/2);
        for(i=0;i<d;i++)
        {
            for(j=0;j<i+1;j++)
            {
                scanf("%d",&p);
                V[i].push_back(p);
            }
        }
        r=i-2;
        for(k=i;k<2*n-1;k++)
        {
            for(j=0;j<r;j++)
            {
                scanf("%d",&p);
                V[k].push_back(p);
            }
            r--;
        }
        for(i=0;i<2*n-1;i++)
        {
            for(j=0;j<V[i].size();j++)
                printf("%d ",V[i][j]);
            printf("\n");
        }

    }

    return 0;
}

