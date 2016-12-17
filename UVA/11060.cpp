#include<stdio.h>
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
