#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

#define MAX 100000
vector<int>edges[MAX];
vector<int>V1,V2;

int main()
{
    int n,e,i,source,value=2,out=0;
    while(scanf("%d",&n)!=EOF)
    {
    value=2,out=0;
    if(n==0) break;
    scanf("%d",&e);
    int x,y;
    for(i=1;i<=e;i++)
    {
        scanf("%d%d",&x,&y);
        if(i==1) source=x;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    if(n==2)
    {
        printf("BICOLORABLE.\n");
        continue;
    }
    if(n==1)
    {
        printf("BICOLORABLE.\n");
        continue;
    }
    V1.push_back(source);
    int taken[1000]={0};
    taken[source]=1;
    for(int loop=1;loop<n;loop++)
    {
        for(i=0;i<V1.size();i++)
        {
            int u=V1[i];
            for(int j=0;j<edges[u].size();j++)
            {
                int v=edges[u][j];
                if(taken[v]>0)
                {
                    if(taken[v]==taken[u])
                        out++;
                }
                else{
                    taken[v]=value;
                    V2.push_back(v);
                }
            }
        }
        if(value==1) value++;
        else value--;
        if(out>0)
        {
            printf("NOT BICOLORABLE.\n");
            break;
        }
        if(V2.empty())
        {
            printf("BICOLORABLE.\n");
            break;
        }
        else{
            V1.clear();
            V1=V2;
            V2.clear();
        }
    }
    for(int i=0;i<200;i++)
        edges[i].clear();
    }
    return 0;
}

