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
vector<int>V[2005],E;
int dp [2005][1005],visit[2005];
int cow,bol;
void color(int ind,int p)
{
    int i,u;
    if(visit[ind]==1)
        return;
    visit[ind]=1;
    if(p==0)
        cow++;
    else
        bol++;
    for(i=0;i<V[ind].size();i++)
    {
        u=V[ind][i];
        if(visit[u]==0)
        {
            if(p==0)
            color(u,1);
            else
                color(u,0);
        }
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t,b,c,n,u,v,i,j;
    scanf("%d",&t);
    while(t--)
    {
        memset(visit,0,sizeof(visit));
        scanf("%d %d %d",&b,&c,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            V[u].push_back(v);
            V[v].push_back(u);
        }
        for(i=1;i<=b+c;i++)
        {
            if(V[i].size()!=0&&visit[i]==0)
            {
                cow=0;bol=0;
               color(i,0);
               E.push_back(cow);
               E.push_back(bol);
            }
        }
        for(i=0;i<E.size();i++)
            printf("%d ",E[i]);
        dp[0][0]=1;
        for(i=1;i<=E.size();i++)
        {
            for(j=0;j<=b;j++)
            {
                if(j-E[i-1]>=0)
                {
                if(dp[i-1][j-E[i-1]]==1)
                dp[i][j]=1;
                }

            }
        }
        printf("\nb=%d dp[%d][b]=%d\n",b,E.size()-1,dp[b][E.size()]);
        if(dp[E.size()-1][b]==1)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}

