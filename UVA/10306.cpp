#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define inf 1<<25
#define ss 90009
struct st
{
    long long xx;
    long long yy;
};
st coin[ss],dp[ss];
long long way[ss];
long long Min(long long a,long long b)
{
    return a<b?a:b;
}
int main()
{
    long long t,x,y,s,m,i,j,px,py;
    long long q,z;
    scanf("%lld",&t);
    while(t--)
    {
        memset(coin,0,sizeof(coin));
        memset(dp,0,sizeof(dp));
        memset(way,0,sizeof(way));
        scanf("%lld %lld",&m,&s);
        for(i=0;i<m;i++)
        {
            scanf("%lld %lld",&x,&y);
           coin[i].xx=x;
           coin[i].yy=y;
        }
        for(i=0;i<=ss;i++)
        {
            for(j=0;j<m;j++)
            {
                px=dp[i].xx+coin[j].xx;
                py=dp[i].yy+coin[j].yy;
                q=px*px+py*py;
                if(q<=s*s)
                {
                    z=(dp[i].xx*dp[i].xx+dp[i].yy*dp[i].yy);
                    dp[q].xx=px;
                    dp[q].yy=py;
                    if(way[q]==0)
                        way[q]=way[z]+1;
                    else
                        way[q]=Min(way[q],(way[z]+1));

                }
            }
        }
        if(way[s*s]==0)
            printf("not possible\n");
        else
            printf("%lld\n",way[s*s]);
    }
    return 0;

}
