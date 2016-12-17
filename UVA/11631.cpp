#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define max  200050
int pr[max];
struct st
{
    int r1;
    int r2;
    int c;
}E[max];
bool cmp(st a,st b)
{
    return a.c<b.c;
}
int find(int u)
{
    if(u==pr[u])
        return u;
    else
        return pr[u]=find(pr[u]);
}
int main()
{
    int i,j,n,m,u,v;
    long long tc=0,cost=0;
    while(1)
    {
        tc=0;cost=0;
        memset(pr,0,sizeof(pr));
        memset(E,0,sizeof(E));
        scanf("%d %d",&m,&n);
        if(m==0&&n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&E[i].r1,&E[i].r2,&E[i].c);
            tc+=E[i].c;
        }

        sort(E,E+n,cmp);
        for(i=0;i<=n;i++)
            pr[i]=i;
        for(i=0;i<n;i++)
        {
            u=find(E[i].r1);
            v=find(E[i].r2);
            if(u!=v)
            {
                if(u<v)
                    pr[v]=u;
                else
                    pr[u]=v;
                cost+=E[i].c;
            }
        }
        printf("%lld\n",tc-cost);
    }
    return 0;
}
