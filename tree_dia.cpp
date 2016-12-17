//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<vector>
#define S 100005
using namespace std;
vector<int>E[S];
int mx,node;
void dfs(int p,int u,int c)
{
    if(mx<c)
    mx=c,node=u;
    int i,v,j=E[u].size();
    for(i=0;i<j;i++)
    {
        v=E[u][i];
        if(v!=p)
        dfs(u,v,c+1);
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
        }
        while(m--)
        {
            scanf("%d%d",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
        mx=-1;
        dfs(-1,1,0);
        dfs(-1,node,0);
        printf("Dia-%d\n",mx);
    }
    return 0;
}


