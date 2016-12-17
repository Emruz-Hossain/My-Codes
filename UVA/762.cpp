#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<map>
#define max 1000005
#include<string>
#include<iostream>
using namespace std;
vector<string>E[max];
queue<string>Q;
int dis[max];
map<string,string>mp;
int main()
{
    int edge,s,d,i,j,m;
    string u,v;
    while(scanf("%d",&edge)==1)
    {
        for(i=0;i<edge;i++)
        {
            cin>>u>>v;
            mp[u][v]=u;
            mp[v][u]=v;
        }
    }
    return 0;
}
