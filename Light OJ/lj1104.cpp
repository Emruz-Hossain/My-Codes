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
    int t,pp,x;
    double p,n,trg;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%lf",&n);
        p=1.0;
        pp=1;
        trg=0.500;
        while(p>trg)
        {
            p=p*(n-pp)/n;
            pp++;
        }
        printf("Case %d: %d\n",x,pp-1);
    }


    return 0;
}


