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
long long ar[1000005];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    long long t,i,sum,x,p,q,m,ind,n,v,j;
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
    {
        sum=0;
        scanf("%lld %lld",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&ar[i]);
        }
        for(i=1;i<=n;i++)
            sum+=(n-(2*i-1))*ar[i];
        printf("Case %lld:\n",x);
        while(q--)
        {
            scanf("%lld",&m);
            if(m==1)
                printf("%lld\n",sum);
            else
            {
                scanf("%lld %lld",&ind,&v);
                  sum-=(n-((ind+1)*2-1))*ar[ind];
                    sum+=(n-((ind+1)*2-1))*v;
            }
        }
    }


    return 0;
}


