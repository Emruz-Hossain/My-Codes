//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<stack>
#include<vector>
#define inf 1<<30
#define S 100005
using namespace std;
vector<int>E[S];
stack<int>Q;
int vis[S];
int main()
{
    int n,m,i,j,s,d,u,v,cmp;
    while(scanf("%d%d",&n,&m)==2)
    {
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
        for(i=1,cmp=0;i<=n;i++)
        {
            if(!vis[i])
            Q.push(i),vis[i]=1,cmp++;
            while(!Q.empty())
            {
                u=Q.top();
                Q.pop();
                for(i=0,j=E[u].size();i<j;i++)
                {
                    v=E[u][i];
                    if(!vis[v])
                    {
                        vis[v]=1;
                        Q.push(v);
                    }
                }
            }
        }
        printf("%d\n",cmp);
    }
    return 0;
}

