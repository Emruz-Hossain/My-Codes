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
#define sz 200
map<string,int>mp,ind,visit;
vector<string>E[sz];
vector<string>vc;
queue<string>Q;
int main()
{
    int m,n,i,x=0,t=1;
    string u,v,str,s1,s2;
    string order[sz];
    while(scanf("%d",&n)==1)
    {
        x=0;
        for(i=0;i<n;i++)
        {
            cin>>str;
            vc.push_back(str);
            ind[str]=0;
            visit[str]=0;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            cin>>s1>>s2;
            ind[s2]++;
            E[s1].push_back(s2);
        }
        for(i=0;i<vc.size();i++)
        {
            if(ind[vc[i]]==0)
            {
                Q.push(vc[i]);
                visit[vc[i]]=1;
            }
        }
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            order[x]=u;
            x++;
            for(i=0;i<E[u].size();i++)
            {
                v=E[u][j];
                ind[v]--;
            }
            for(i=0;i<vc.size();i++)
            {
                if(ind[vc[i]]==0&&visit[vc[i]]!=1)
                {
                    Q.push(vc[i]);
                    visit[vc[i]=1;
                }
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ",t);
        for(i=0;i<x;i++)
        {
            if(i>0)
                printf(" ");
            cout<<order[i];
        }
        printf(".\n");
        printf("\n");
        t++;
    }
    return 0;
}
