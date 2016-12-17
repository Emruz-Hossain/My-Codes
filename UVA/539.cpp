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
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
vector<int>V[30];
int n,m,maxx,visit[30][30];
void backtrack(int ind,int p)
{
    int i;
    maxx=max(maxx,p);
    for(i=0;i<V[ind].size();i++)
    {
        int k=V[ind][i];
        if(visit[ind][k]==0)
        {
            visit[ind][k]=1;
            visit[k][ind]=1;
            backtrack(V[ind][i],p+1);
            visit[ind][k]=0;
            visit[k][ind]=0;
        }
    }

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int u,v,i;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)
            break;
        for(i=0;i<n;i++)
            V[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            V[u].push_back(v);
            V[v].push_back(u);
        }
        maxx=0;
        for(i=0;i<n;i++)
        {
            memset(visit,0,sizeof(visit));
            backtrack(i,0);
        }

        printf("%d\n",maxx);
    }


    return 0;
}


