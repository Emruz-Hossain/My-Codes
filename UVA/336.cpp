#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define max 10000000
#define inf 1<<30
vector<int>E[max];
queue<int>Q;
int dis[max];
int main()
{
    int edge,t=0,u,v,s,d,i,j,m=0,c;
    while(1)
    {

        scanf("%d",&edge);
        if(edge==0)
            break;
        for(i=0;i<=m;i++)
            E[i].clear();
        m=0;
        for(i=0;i<edge;i++)
        {
            scanf("%d %d",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
            if(u>m)
                m=u;
            if(v>m)
                m=v;
        }

        while(1)
        {

            scanf("%d %d",&s,&d);
            if(s==0&&d==0)
                break;
            c=0;
            t++;
            for(i=0;i<=m;i++)
            dis[i]=inf;
            dis[s]=0;
            Q.push(s);

            while(!Q.empty())
            {
                u=Q.front();
                Q.pop();
                for(i=0;i<E[u].size();i++)
                {
                    v=E[u][i];
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        Q.push(v);
                    }
                }
            }
            for(i=0;i<=m;i++)
            {
                if(dis[i]!=inf&&dis[i]>d)
                    c++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t,c,s,d);
        }
    }
    return 0;
}
