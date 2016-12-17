//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<algorithm>
#define S 100005
using namespace std;
struct Mst
{
    int u,v,w;
}E[S];
bool cmp(Mst a,Mst b)
{
    return a.w<b.w;
}
int P[S];
int find(int u)
{
    if(P[u]==u)
    return u;
    return P[u]=find(P[u]);
}
int main()
{
    int n,m,i,u,v,sum;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=1;i<=n;i++)
        P[i]=i;
        for(i=0;i<m;i++)
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
        sort(E,E+n,cmp);
        for(i=sum=0;i<m;i++)
        {
            u=find(E[i].u);
            v=find(E[i].v);
            if(u!=v)
            {
                if(u<v)
                P[v]=u;
                else
                P[u]=v;
                sum+=E[i].w;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
