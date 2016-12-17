#include<bits/stdc++.h>
using namespace std;
#define sz 1001

int cost[sz][sz],par[sz],mcost[sz];
vector<int>E[sz];
struct st
{
    int nd,w;
    st(int a,int b){nd=a;w=b;}
    bool operator <(const st&p) const{return p.w<w;}
};
int DSTR(int s,int d)
{
    int i,u,v;
    memset(mcost,127,sizeof(mcost));
    memset(par,-1,sizeof(par));
    priority_queue<st> P;
    mcost[s]=0;
    P.push(st(s,0));
    while(!P.empty())
    {
        st tp=P.top();P.pop();
        u=tp.nd;
        if(u==d)
            return mcost[u];
        for(i=0;i<E[u].size();i++)
        {
            v=E[u][i];
            if(mcost[u]+cost[u][v]<mcost[v])
            {
                mcost[v]=mcost[u]+cost[u][v];
                P.push(st(v,mcost[v]));
                par[v]=u;
            }
        }
    }
    return -1;
}
void soln(int u)
{
    if(u==-1)
        return;
    soln(par[u]);
    printf("%d ",u);
}
int main()
{
    int u,v,w,i,n,edg,ans,s,d;
    memset(cost,127,sizeof(cost));
    scanf("%d %d",&n,&edg);
    for(i=0;i<edg;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        E[u].push_back(v);
        E[v].push_back(u);
        cost[u][v]=cost[v][u]=w;
    }
    printf("Enter source and destination:\n");
    scanf("%d %d",&s,&d);
    ans=DSTR(s,d);
    printf("Min Dist: %d\nPath: ",ans);
    soln(d);
    printf("\n");
}
