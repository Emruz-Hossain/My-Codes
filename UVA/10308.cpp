#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<iostream>
#define max 100010
using namespace std;
vector<int>E[max];
map<int, map<int ,int > >mp;
int dis,node;
void dfs(int p,int u,int c)
{
    int i,v,j;
    if(dis<c)
    {
        dis=c;
        node=u;
    }
    for(i=0,j=E[u].size();i<j;i++)
    {
        v=E[u][i];
        if(v!=p)
        {
            dfs(u,v,c+mp[u][v]);
        }
    }
}
int main()
{
   int u,v,i,j=0,d,r=0,p;
   char c;
   while(scanf("%c",&c)==1)
   {
       j=1;
       dis=0;
       for(i=0;i<=r;i++)
        E[i].clear();
    mp.clear();
    p=0;
   while(1)
   {
       if(j!=1)
        scanf("%c",&c);
       if(c=='\n')
        break;
        p=1;
       u=c-48;
       scanf("%d %d",&v,&d);
       E[u].push_back(v);
       E[v].push_back(u);
       mp[u][v]=d;
       mp[v][u]=d;
       if(r<u)
        r=u;
        if(r<v)
        r=v;
    j=0;
    getchar();
   }
   if(p==1)
   {
    dis=-1;
   dfs(-1,r,0);
   dfs(-1,node,0);
   }
   printf("%d\n",dis);
    }
    return 0;
}

