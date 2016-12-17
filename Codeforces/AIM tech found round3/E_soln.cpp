//
//  main.cpp
//  709E
//
//  Created by Matrix.code on 8/24/16.
//  Copyright © 2016 Matrix.code. All rights reserved.
//
#include<bits/stdc++.h>
using namespace std;
/*------- Constants---- */

#define Long                    long long
#define Ulong                   unsigned long long
#define FOR(I,A,B)              for(int I = (A); I < (B) ; ++ I)
#define REP(i,n)                for( int i=0 ; i < n ; i++ )
#define mp                      make_pair
#define pb                      push_back
#define all(x)                  (x).begin(),(x).end()
#define PI                      acos(-1.0)
#define EPS                     1e-9
#define F                       first
#define S                       second
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define Di(x)                   int x;scanf("%d",&x)
#define Si(x)                   scanf("%d",&x);
#define ms(ara_name,value)      memset(ara_name,value,sizeof(ara_name))
#define IO                      ios_base::sync_with_stdio(0);cin.tie(0)

template <class T> inline T bigmod(T p,T e,T M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

/***************************** END OF TEMPLATE *******************************/

const int N = 4e5+5;
int n,h;
int sub[N];
int Mx[N][2];
int id[N][2];
int flag[N];
int ans[N] ;
vector<int>G[N];
int is[N];
void dfs(int u,int  p =-1 )
{
    sub[u] = 1;
    is[u] = 0;
    flag[u] = 1;
    Mx[u][0] = Mx[u][1] = -1;
    REP(i,G[u].size())
    {
        int v = G[u][i];
        if(v == p )continue;
        dfs(v,u);
        sub[u] += sub[v];
        if(sub[v] > h )
        {
            if(sub[v] - Mx[v][0] <= h )
            {
                is[u] ++;
            }
            else
                flag[u] = 0;
        }


        int o = Mx[v][0];
        if(sub[v] <= h )
            o = max(o , sub[v]);

        if(Mx[u][0] < o )
        {
            Mx[u][1] = Mx[u][0];
            id[u][1] = id[u][0];
            Mx[u][0] = o;
            id[u][0] = v;
        }
        else if( Mx[u][1] < o )
        {
            Mx[u][1] = o;
            id[u][1] = v;
        }

    }

}

void dfs2(int u,int p, int PM)
{
    if(u > 1)
    {
        int o = PM;
        int os = n - sub[u];

        if(os - o > h ) flag[u] = 0;
        if(os > h ) is[u] ++;
    }
    if(is[u] > 1 || flag[u] == 0 ) ans[u] = 0;

    REP(i,G[u].size())
    {
        int v = G[u][i];
        if(v==p)continue;
        int M = PM;
        if(id[u][0] != v )
            M = max(M, Mx[u][0]);
        if(id[u][1] != v )
            M = max(M , Mx[u][1]);
        if(n - sub[u]  <= h )
            M = max(M , n - sub[u]);
        dfs2(v,u,M);
    }
}

int main()
{

    int u,v;
    cin >> n;
    h = n/2;
    for(int i = 0; i < n-1 ; i ++ )
    {
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++ )
        ans[i] = 1, flag[i] = 1;

    dfs(1,-1);
    dfs2(1,-1,0);

    for(int i = 1; i <= n; i ++ )
        printf("%d " ,ans [i]);
    return 0;
}


//7
//1 3
//1 2
//1 5
//3 7
//2 4
//2 6
//1 5

