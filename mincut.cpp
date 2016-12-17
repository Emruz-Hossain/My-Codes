//BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
vector<int>v,E[300];
int graph[205][205],temp_graph[205][205];
int visit[205],parent[205];
bool dfs(int s,int d)
{
    int i,u,v;
    memset(visit,0,sizeof(visit));
    queue<int>Q;
    Q.push(s);
    visit[s]=1;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=0;i<E[u].size();i++)
        {
            v=E[u][i];
            if(visit[v]==0&&temp_graph[u][v]>0)
            {
                visit[v]=1;
                Q.push(v);
                parent[v]=u;
            }
        }
    }
    if(visit[d])
     return true;
    else
        return false;
}
int max_flow(int source,int destination)
{
    int i,u,flow,mx_flow=0,j;
    for(i=1;i<=200;i++)
    {
        for(j=1;j<=200;j++)
        {
            temp_graph[i][j]=graph[i][j];
        }
    }
    memset(parent,-1,sizeof(parent));
    while(dfs(source,destination))
    {
        flow=999999;
        for(i=destination;i!=source;i=parent[i])
        {
            u=parent[i];
            flow=min(flow,temp_graph[u][i]);
        }
        for(i=destination;i!=source;i=parent[i])
        {
            u=parent[i];
            temp_graph[u][i]-=flow;
            temp_graph[i][u]+=flow;
        }
        mx_flow+=flow;
    }
        if(mx_flow==0)
            return 999999;
        else
        return mx_flow;
}
int main()
{


    int i,j,sm,ans,l,p;
    string ss;
    freopen("Prob05.txt","r",stdin);//এই লাইন টা file থেকে ইনপুট নেওয়ার জন্য। ফাইল টা অবশ্যই  Prob05.txt নাম হতে হবে এবং এই কোড যেখানে থাকবে  সেখানে ফাইল টা রাখতে হবে। যদি হাতে ইনপুট নিতে চাও তবে এই লাইন টা comment করে দাও।
    memset(graph,0,sizeof(graph));
    for(i=1;i<=200;i++)
    {
        getline(cin,ss);
        l=ss.size();
        sm=0;
        v.clear();
        for(j=0;j<l;j++)
        {
            if(ss[j]>='0'&&ss[j]<='9')
                sm=sm*10+ss[j]-'0';
            else
            {
                if(sm!=0)
                v.push_back(sm);
                sm=0;
            }
        }
        if(j==l&&sm!=0)
            v.push_back(sm);
        for(j=1;j<v.size();j++)
        {
            E[i].push_back(v[j]);
            graph[i][v[j]]=1;
            graph[v[j]][i]=1;
        }
    }
    ans=9999999;
    for(i=1;i<=200;i++)
    {
        for(j=i+1;j<=200;j++)
        {
            p=max_flow(i,j);
            ans=min(ans,p);
        }
    }
    printf("%d\n",ans);

    return 0;
}
