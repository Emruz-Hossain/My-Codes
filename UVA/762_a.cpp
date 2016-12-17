#include <bits/stdc++.h>
#define inf 1<<28
using namespace std;
int mark[100005];
vector <int> ed[100005], cost[100005];
map<string , int> mp;
map<int , string> mp1;

int bfs(int src,int dest){
    int d[100005];
    for(int i = 0; i<100005; i++) d[i] =inf;
    queue<int >q;
    q.push(src);
    d[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int ucost = d[u];
        for(int i = 0;i<ed[u].size(); i++){
            int v = ed[u][i], vcost = cost[u][i] + ucost;
            if(d[v] > vcost){
                d[v] = vcost;
                mark[v] = u;
                q.push(v);
            }
        }
    }
    if(d[dest] == inf) return -1;
    else return 1;
}
void prpt(int a, int b){
    if(a == b) return;
    //cout<< "1st b , a" << b<< " "<< a<<endl;
    prpt(mark[a], b);
    //cout<< "2nd b , a" << b<< " "<< a<<endl;
    cout<<mp1[mark[a]]<<" "<< mp1[a]<<endl;
}

int main()
{
    int n, u, v, c, m, f = 0;
    string a, b;
    while(~scanf("%i", &n)){
            if(f)cout<<"\n";
            f++;
            c = 1;
            mp.clear();
            mp1.clear();
    for(int i = 0; i<n; i++){
        cin>>a>>b;
        if(!mp[a]) mp[a] = c++;
        if(!mp[b]) mp[b] = c++;
        u = mp[a];
        v = mp[b];
        mp1[u] = a;
        mp1[v] = b;
        ed[u].push_back(v);
        ed[v].push_back(u);
        cost[u].push_back(1);
        cost[v].push_back(1);
        //cout<< "u = "<< u<< " mp[a] = (c) "<< mp[a]<<endl;
        //cout<< "v = "<< v<< " mp[b] = (c) "<< mp[b]<<endl;
    }
        n = c;
        cin>> a>>b;
        if(mp[a]==0||mp[b]==0)
        {
            cout<<"No route"<<endl;
            return 0;
        }
        u = mp[a];
        v = mp[b];
        int k = bfs(u, v);
        if(k == -1){cout<<"No route"<<endl;}
        else prpt(v, u);
        for(int i = 0; i<n; i++) ed[i].clear(), cost[i].clear();
    }
}
