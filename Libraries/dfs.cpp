//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<vector>
#define S 100005
using namespace std;
vector<int>E[S];
int vis[S];
void dfs(int u)
{
    vis[u]=1;
    int i,v,j=E[u].size();
    for(i=0;i<j;i++)
    {
        v=E[u][i];
        if(!vis[v])
        dfs(v);
    }
}
int main()
{
    int n,m,i,u,v,cmp;
    while(scanf("%d%d",&n,&m)==2)
    {
        cmp=0;
        for(i=1;i<=n;i++)
        {
            E[i].clear();
            vis[i]=0;
        }
        while(m--)
        {
            scanf("%d%d",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                cmp++;
            }
        }
        printf("%d\n",cmp);
    }
    return 0;
}
