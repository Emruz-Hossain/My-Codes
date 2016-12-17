#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define inf 1<<30
#define max 1000
vector<int>Edge[max];
queue<int>Q;
int parents[max];
int dis[max];
void path(int u)
{
    int v;
    if(u==-1)
        return;
    else
    {
        v=parents[u];
        path(v);
        printf("%d",u);
        if(u!=-1)
            printf(" ");
    }
}
int main()
{
    int node,edge,source,destination,u,v,i,j;
    scanf("%d %d",&node,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d %d",&u,&v);
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
    printf("Enter source and destination:\n");
    while(scanf("%d %d",&source,&destination)==2)
    {
        for(i=0;i<=node;i++)
            dis[i]=inf;
        Q.push(source);
        dis[source]=0; parents[source]=-1;
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            for(i=0;i<Edge[u].size();i++)
            {
                v=Edge[u][i];
                if(dis[v]>dis[u]+1)
                {
                    dis[v]=dis[u]+1;
                    parents[v]=u;
                    Q.push(v);
                }
            }
        }
        printf("Distance from %d to %d is %d\n",source,destination,dis[destination]);
        printf("Path is ");
        path(destination);
        printf("\n");
    }
    return 0;
}
