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
#define sz 100005
#define eps 1e-9
vector<int>E[sz];
int visit[sz],tt;
void dfs(int u)
{
    int i;
    if(visit[u]==1)
        return;
    visit[u]=1;
    tt++;
    for(i=0;i<E[u].size();i++)
    {
        int v=E[u][i];
        if(visit[v]==0)
            dfs(v);
    }

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int n,m,l,total,i,u,v,ar[sz],t;
    scanf("%d",&t);
    while(t--)
    {
        total=0;
        memset(visit,0,sizeof(visit));
        scanf("%d %d %d",&n,&m,&l);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            E[u].push_back(v);
        }
        for(i=0;i<l;i++)
        {
            scanf("%d",&ar[i]);
        }
        for(i=0;i<l;i++)
        {
            if(visit[ar[i]]==0)
            {
                tt=0;
                dfs(ar[i]);
                total+=tt;
            }

        }
        printf("%d\n",total);
        for(i=0;i<=n;i++)
            E[i].clear();
    }


    return 0;
}


