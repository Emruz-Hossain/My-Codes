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
int R[]={1,-1,0,0};
int C[]={0,0,1,-1};
int ar[sz][sz],visit[sz][sz],tt;
void dfs(int x,int y,int n,int r)
{
    int i,p,q;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    tt++;
    for(i=0;i<4;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>0&&q>0&&p<=n&&q<=n&&ar[p][q]==r)
            dfs(p,q,n,r);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int i,j,p,n,u,v;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=1;i<n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d %d",&u,&v);
                ar[u][v]=i;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<n;j++)
            {
                if(ar[i][j]==0)
                    ar[i][j]=n;
            }
        }
        p=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(visit[i][j]==0)
                {
                    tt=0;
                    dfs(i,j,n,ar[i][j]);
                    if(tt!=n)
                        p=0;
                }
            }
        }
        if(p==1)
            printf("good\n");
        else
            printf("wrong\n");
    }


    return 0;
}

