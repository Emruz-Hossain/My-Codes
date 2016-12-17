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
int gcd(int m,int n)
{
    if(m%n==0)
        return n;
    else
        gcd(n,m%n);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,p,u,sum,rev,e,i,n,x,g;
    char ch;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        rev=0;sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&u);
            if(u<0)
                rev++;
            sum+=abs(u);
        }
        e=n-rev;
        if(e==0)
        {
            printf("Case %d: inf\n",x);
        }
        else
        {
            g=gcd(sum,e);
            printf("Case %d: %d/%d\n",x,(sum/g),(e/g));
        }
    }


    return 0;
}


