/*
ID: xildar91
PROG: concom
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
int inf_int=2e9;
ll inf_ll=2e18;
typedef pair<int,int> pii;
#define pb push_back
const double pi=3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz size()
template<typename T>
void prin(vector<T>& a)
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i];
        if(i<a.size()-1)
            cout<<" ";
        else
            cout <<"\n";
    }
}
template<typename T>
void prin(set<T>& a)
{
    for(auto it=a.begin();it!=a.end();it++)
    {
        cout << *it<<" ";
    }
}
template<typename T>
void prin_new_line(vector<T>& a)
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i]<<"\n";
    }
}
template<typename T,typename T1>
void prin_new_line(vector<pair<T,T1> >& a)
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i].fi<<" "<<a[i].se<<"\n";
    }
}

int sum_vec(vector<int>& a)
{
    int s=0;
    for(int i=0;i<a.size();i++)
    {
        s+=a[i];
    }
    return s;
}
template<typename T>
T max(vector<T>& a)
{
    T ans=a[0];
    for(int i=1;i<a.size();i++)
    {
        ans=max(ans,a[i]);
    }
    return ans;
}
template<typename T>
T min(vector<T>& a)
{
    T ans=a[0];
    for(int i=1;i<a.size();i++)
    {
        ans=min(ans,a[i]);
    }
    return ans;
}
template<typename T>
T min(T a,T b,T c)
{
    return min(a,min(b,c));
}
template<typename T>
T max(T a,T b,T c)
{
    return max(a,max(b,c));
}

double s_triangle(double x1,double y1,double x2,double y2,double x3,double y3)
{
    return abs(((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2);
}
#define x1 gfgs
#define y1 asd
const int maxn=6e5;
vector<int> g[maxn];
#define debug 0
vector<int> lis;
void dfs(int v,int p,int dis)
{
    bool k=1;
    for(int i=0;i<g[v].sz;i++)
    {
        int to=g[v][i];
        if(to!=p)
        {
            k=0;
            dfs(to,v,dis+1);
        }
    }
    if(k)
    {
        lis.pb(dis);
    }
}
void solve()
{
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans=0;
    for(int i=0;i<g[1].sz;i++)
    {
        int to=g[1][i];
        lis.clear();
        dfs(to,1,1);
        sort(lis.begin(),lis.end());
        for(int i=1;i<lis.sz;i++)
        {
            if(lis[i]<=lis[i-1])
            {
                lis[i]=lis[i-1]+1;
            }
        }
        ans=max(ans,lis[lis.sz-1]);
    }
    cout << ans;



}
#define FILE "strange"
int main()
{

      //  freopen("laundro_matt.txt","r",stdin);
      //  freopen("output.txt","w",stdout);

    // freopen(FILE".in","r",stdin);
    // freopen(FILE".out","w",stdout);
       if(!debug)
       {
           ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
       }
        int t=1;
        while(t--)
            solve();
        return 0;
}
