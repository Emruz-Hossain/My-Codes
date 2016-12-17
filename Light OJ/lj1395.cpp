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
#define sz 200
#define eps 1e-9
#define mod  1000000007
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
double dp[sz];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int i,x,t,n,k;
    double r,A,B,p,q,d,Q;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        memset(dp,0.0,sizeof(dp));
        A=0.0;B=0.0;q=0.0;p=0.0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&r);
            if(r>=0.0)
            {
                p++;
                A+=r;
            }
            else
            {
                q++;
                B+=-1*r;
            }
        }
        if(p==0.0)
           printf("Case %d: -1\n",x);
        else
        {
        dp[0]=(A/p)+(B/p);
        if(n*p==0.0)
            dp[1]=dp[0];
        else
        dp[1]=dp[0]-(B/(n*p));
        r=1;
        d=n-1;
        Q=1;
        q--;
        for(i=2;i<=k;i++)
        {
            Q*=q;
            r*=d;
            if(n*p*r==0.0)
                dp[i]=dp[i-1];
            else
            dp[i]=dp[i-1]-(Q*B)/(n*p*r);
            q--;d--;

        }
        printf("Case %d: %.12lf\n",x,dp[k]);
        }
    }


    return 0;
}



