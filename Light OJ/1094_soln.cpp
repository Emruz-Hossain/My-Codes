#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <string>
#include <sstream>
#include <list>

using namespace std;

#define fst first
#define snd second
#define EPS 1e-7
#define PI 2*acos(0.0)
#define inf (1<<29)
#define akbarbe ceil
#define akkombe floor
#define bug(x) cout<<#x<<" = "<<x<<endl
#define N 1000000
#define LL long long
#define delect(str) str.erase(std::remove_if(str.begin(), str.end(), str[i]), str.end());

int xx[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int yy[] = {0, -1, 1, 0, 1, -1, 1, -1};

int dx[] = {+1,+1,+2,+2,-1,-1,-2,-2};
int dy[] = {+2,-2,+1,-1,+2,-2,+1,-1};

vector<pair<int,int> >G[30000];
int visit[30000];
vector<int>co;
int par[30000];
int cost[30000];
int mxc;
int BFS(int s,int n)
{
    memset(visit,0,sizeof visit);
    memset(cost,0,sizeof cost);
    queue<int>q;
    q.push(s);
    visit[s]=1;
    cost[s]=0;
    int m=-1;
    par[s]=s;

    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0; i<G[f].size(); i++)
        {
            int u = G[f][i].first;
            int w=G[f][i].second;
            if(!visit[u])
            {
                visit[u]=1;
                cost[u]=cost[f]+w;
                par[u]=f;
                q.push(u);
            }
        }
    }
    int index;
    for(int i=n; i>=0; i--)
    {
        if(cost[i]>m)
        {
            m = cost[i];
            index = i;
            mxc=max(mxc,m);
        }
    }
    return index;

}
void G_clear()
{
    for(int i=0; i<30000; i++)
    {
        G[i].clear();
    }
}
void print(int w)
{
    if(par[w]==w) return;
    co.push_back(par[w]);
    print(par[w]);

}
int main()
{
    //freopen("in.txt","r",stdin);
    int t,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        int u,v,w;
        mxc=-1;
        scanf("%d",&n);
        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back(make_pair(v,w));
            G[v].push_back(make_pair(u,w));

        }
        u = BFS(0,n-1);
        v = BFS(u,n-1);
//        print(v);
//        int sum = 0;
//        int i1;
//        int i2;
//        for(int i=0; i<co.size(); i++)
//        {
//            i1 = v;
//            i2 = co[i];
//            for(int j=0; j<G[i1].size(); j++)
//            {
//                if(G[i1][j].first==i2) sum+=G[i1][j].snd;
//            }
//            v = i2;
//
//        }
        printf("Case %d: %d\n",++cs,mxc);
        G_clear();
        co.clear();

    }
    return 0;
}


//1
//6
//0 1 1
//0 2 1
//1 3 1
//3 4 5
//3 5 5
