#include<stdio.h>
#include<vector>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
#define s 200
int main()
{
    int u,v,visited[s],indegree[s],node,edge,x,i,j;
    memset(visited,0,sizeof(visited));
    memset(indegree,0,sizeof(indegree));
    queue<int>Q;
    vector<int>E[s];
    scanf("%d %d",&node,&edge);
    for(x=0;x<edge;x++)
    {
        scanf("%d %d",&u,&v);
        indegree[v]++;
        E[u].push_back(v);
    }
    for(i=1;i<=node;i++)
    {
        if(indegree[i]==0)
        {
            Q.push(i);
            visited[i]=1;
        }

    }
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        printf("%d\n",u);
        for(i=0;i<E[u].size();i++)
        {
            v=E[u][i];
            indegree[v]--;
        }
        for(j=1;j<=node;j++)
        {
            if(indegree[j]==0&&visited[j]!=1)
            {
                Q.push(j);
                visited[j]=1;
            }
        }
    }
    return 0;
}

