#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int degree[500],visit[500][500];
int main()
{
    int node,edge,u,v,p,k,i,cur;
    vector<int>E[500];
    scanf("%d %d",&node,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d %d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    p=0;
    for(i=1;i<=node;i++)
    {
        degree[i]=E[i].size();
        if(degree[i]%2==1)
        {
            p++;
            k=i;
        }
        if(degree[i]==0||p>2)
        {
            printf("No Euler Path.\n");
            return 0;
        }

    }
    stack<int>STK;
    vector<int>path;
    if(p!=0)
    {
        STK.push(k);
    }
    else
    {
        STK.push(1);
    }
    while(!STK.empty())
    {
        cur=STK.top();
        p=-1;
        while(E[cur].size())
        {
            k=E[cur].back();
            if(visit[cur][k]==0)
            {
                p=0;
                visit[cur][k]=1;
                visit[k][cur]=1;
                break;
            }
            else
                E[cur].pop_back();

        }
        if(p!=-1)
        STK.push(k);
        else
        {
            STK.pop();
            path.push_back(cur);
        }
    }
    for(i=path.size()-1;i>=0;i--)
    printf("%d ",path[i]);
    printf("\n");
    return 0;
}
