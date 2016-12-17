//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
#define s 205
queue<int>Q;
vector<int>E[s];
int visit[s],ind[s];
map<string ,int >mp;
map<int ,string>bp;
int main()
{
    int t,i,j,m,n,u,v,x;
    string ss,s1,s2,str[s];
    t=0;
    while(scanf("%d",&n)==1)
    {
        memset(ind,0,sizeof(ind));
        memset(visit,0,sizeof(visit));

        for(i=1;i<=n;i++)
        {
           cin>>ss;
            mp[ss]=i;
            bp[i]=ss;

        }
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            cin>>s1>>s2;
            ind[mp[s2]]++;
            E[mp[s1]].push_back(mp[s2]);
        }
        for(i=1;i<=n;i++)
        {
            if(ind[i]==0)
            {
                Q.push(i);
                visit[i]=1;
            }
        }
        x=0;
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
           str[x]=bp[u];
            x++;
            for(j=0;j<E[u].size();j++)
            {
                v=E[u][j];
                ind[v]--;
            }
            for(i=1;i<=n;i++)
            {
                if(ind[i]==0&&visit[i]==0)
                {
                    Q.push(i);
                    visit[i]=1;
                }
            }
        }
        if(t>0)
        printf("\n");
        printf("Case #%d: Dilbert should drink beverages in this order: ",++t);
        for(i=0;i<x;i++)
        {
            if(i>0)
                printf(" ");
            cout<<str[i];
        }
        printf(".\n");
        for(i=0;i<=n;i++)
            E[i].clear();
    }
    return 0;
}

#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define sz 100005
typedef long long int ll;
using namespace std;
vector<int>ar[100005];
vector<int>point;
int vis[sz],viss[sz],low[sz],timeinfo[sz],par[sz];
int tm=0;

int Min(int a,int b)
{
    return a>b?a:b;
}

int dfs(int u)
{
    vis[u]=1;

    timeinfo[u]=low[u]=++tm;
    int i,v;
    for( i=0;i<ar[u].size();i++)
    {
        v=ar[u][i];
        if(!vis[v])
           {
               par[v]=u;
               low[u]=Min(low[u],dfs(v));
               if(timeinfo[u]==1)
               {
                   if(ar[u].size()>=2&&viss[u]==0&&low[v]>timeinfo[u])
                   {
                       viss[u]=1;
                       point.push_back(u);
                   }
               }
              else if(low[v]>=timeinfo[u]&&viss[u]==0)
               {
                   viss[u]=1;
                   point.push_back(u);
               }
           }
           else if(v!=par[u])
                low[u]=Min(low[u],low[v]);
    }
   return low[u];
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    char st[10000],*cp;
     while(scanf("%d",&n)==1)
     {
         if(n==0)
            break;
         memset(vis,0,sizeof(vis));
         memset(viss,0,sizeof(viss));
         getchar();
         while(gets(st))
         {
             j=0;
             if(st[0]=='0')break;
             cp=strtok(st," ");
             while(cp!=NULL)
             {
                 if(j==0)
                    a=atoi(cp);
                 else
                 {
                     b=atoi(cp);
                     ar[a].push_back(b);
                     ar[b].push_back(a);
                 }
                 cp=strtok(NULL," ");
                 j++;
             }

         }
        memset(par,0,sizeof(par));
         tm=0;
         for(i=1;i<=n;i++)
         {
             if(vis[i]==0)
             dfs(i);
         }
         printf("%d\n",point.size());
         point.clear();
         for(i=1;i<=n;i++)
            ar[i].clear();

     }
    return 0;
}


