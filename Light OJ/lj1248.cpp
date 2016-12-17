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
using namespace std;
#define inf 1<<25
#define sz 2000
#define eps 1e-9
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int i,x,t;
    double n,sum;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        sum=0.0;
        scanf("%lf",&n);
        for(i=1;i<=n;i++)
        {
            sum+=n/i;
        }
        printf("Case %d: %.12lf\n",x,sum);
    }


    return 0;
}


