#include<bits/stdc++.h>
using namespace std;
struct st
{
    int u,v,w;
}ar[100005];
int par[10005];
bool cmp(st a,st b)
{
    return(a.w<b.w);
}
int parent(int v)
{
    if(par[v]==-1||par[v]==v)
       return v;
    else
    return parent(par[v]);
}
int main()
{
    int n,m,i,mcost=0,p,q;
    vector<int>cost;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&ar[i].u,&ar[i].v,&ar[i].w);
    }
    sort(ar,ar+m,cmp);
    printf("----------\n");
    for(i=0;i<m;i++)
    printf("%d %d %d\n",ar[i].u,ar[i].v,ar[i].w);
    for(i=1;i<=n;i++)
    par[i]=i;
    par[ar[0].u]=-1;
    par[ar[0].u]=ar[0].u;
    cost.push_back(ar[0].w);
    mcost+=ar[0].w;
    for(i=1;i<m;i++)
    {
        p=parent(ar[i].u);
        q=parent(ar[i].v);
        if(p!=q)
        {
            cost.push_back(ar[i].w);
            mcost+=ar[i].w;
            if(p<q)
             par[ar[i].v]=p;
            else
                par[ar[i].u]=q;
        }
    }
    for(i=0;i<cost.size();i++)
    printf("%d ",cost[i]);
    printf("= %d\n",mcost);
    return 0;
}
