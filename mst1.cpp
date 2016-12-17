#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct st
{
  int u,v,w;
};
int pr[100];
int ar[1000];
bool cmp(st a, st b)
{
        return a.w<b.w;
}
int parent(int k)
{
    if(pr[k]==k)
        return k;
    else
        return pr[k]=parent(pr[k]);
}
int main()
{
    int node,edge,i,j,p,q,u,v,w, total=0,x=0;
    st E[10];
    int visit[10];
    memset(visit,0,sizeof(visit));
    scanf("%d %d",&node,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);
    }
    for(i=1;i<=edge;i++)
        pr[i]=i;
    sort(E,E+edge,cmp);
    for(i=0;i<edge;i++)
    {
        u=E[i].u;
        v=E[i].v;
        p=parent(E[i].u);
        q=parent(E[i].v);
        if(p!=q)
        {
            if(p<q)
                pr[q]=p;
            else
                pr[p]=q;
            total+=E[i].w;
            ar[x]=u;ar[++x]=v;x++;
        }

    }
    printf("%d\n",total);
    for(i=0;i<x;i+=2)
        printf("%d %d\n",ar[i],ar[i+1]);

return 0;
}

//6 8
//1 2 2
//1 3 3
//2 5 1
//2 6 5
//3 4 5
//4 5 1
//4 6 2
//5 6 3
