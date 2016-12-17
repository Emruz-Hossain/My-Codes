#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
#define max 100
vector<int>V[max];
queue<int>Q;
#define inf 1<<30
int dis[max];
int main()
{
    int p,q,edge,node,d,s,i,j;
    scanf("%d %d",&node,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d %d",&p,&q);
        V[p].push_back(q);
        V[q].push_back(p);
    }
    for(i=1;i<=node;i++)
        dis[i]=inf;
    printf("Enter source and destination\n");
    scanf("%d %d",&s,&d);
    dis[s]=0;
    Q.push(s);
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        for(i=0;i<V[p].size();i++)
        {
            q=V[p][i];
            if(dis[q]>dis[p]+1)
            {
                dis[q]=dis[p]+1;
                Q.push(q);
            }
        }
    }
    printf("Distance from %d to %d is %d",s,d,dis[d]);
    return 0;
}
