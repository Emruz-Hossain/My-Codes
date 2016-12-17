//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define inf 1<<25
#define sz 2000
#define eps 1e-9
vector<int>E[100005];
map<int,int>mp;
int ar[100005],visit[100005],ss,tt,vp;
void dfs(int u,int p)
{
    int v;
    if(visit[u]==1)
        return;
    visit[u]=1;
    tt++;
    if(p==0)
        ss++;
    else
        vp++;
    for(int i=0;i<E[u].size();i++)
    {
        v=E[u][i];
        if(visit[v]==0)
        {
            if(p==0)
            {
                dfs(v,1);
            }

            else
            {
                 dfs(v,0);
            }

        }
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,x,i,p,u,v,total,n,k;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        p=0;
        total=0;
        k=0;
        mp.clear();
        memset(visit,0,sizeof(visit));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
            if(mp[u]==0)
            ar[p++]=u;
            if(mp[v]==0)
            ar[p++]=v;
            mp[u]=1;
            mp[v]=1;
            k=max(k,u);
            k=max(k,v);
        }
        for(i=0;i<p;i++)
        {
            if(visit[ar[i]]==0)
            {
                tt=0;ss=0;vp=0;
                dfs(ar[i],0);
                total+=max(ss,vp);

            }
        }
        printf("Case %d: %d\n",x,total);
        for(i=0;i<=k;i++)
            E[i].clear();
    }


    return 0;
}

