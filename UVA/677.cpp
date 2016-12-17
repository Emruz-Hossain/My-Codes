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
#include<iomanip>
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
int p=0;
int m,n;
vector<int>V,E[20];
int visit[20];
void backtrack(int u,int l)
{
    int i;
    if(V.size()==n+1)
    {
        p=1;
        for(i=0;i<n+1;i++)
           {
               if(i==0)
                printf("(1");
               else if(i==n)
                printf(",%d)\n",V[i]);
                else
                    printf(",%d",V[i]);
           }
    }
    for(i=0;i<E[u].size();i++)
    {
        if(visit[E[u][i]]==0)
        {
            V.push_back(E[u][i]);
            visit[E[u][i]]=1;
            backtrack(E[u][i],l+1);
            V.pop_back();
            visit[E[u][i]]=0;
        }
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j,u,k;
    while(scanf("%d",&m)==1)
    {
        memset(visit,0,sizeof(0));
        V.clear();
        p=0;
        if(m!=-9999)
        {
            k=0;
            scanf("%d",&n);
        }
        else
        {
            k=-9999;
            scanf("%d %d",&m,&n);
        }
        if(k==-9999)
            printf("\n");
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&u);
                if(u==1)
                    E[i].push_back(j);
            }
        }
        V.push_back(1);
        visit[1]=1;
        backtrack(1,0);
        if(p==0)
            printf("no walk of length %d\n",n);
        for(i=0;i<=m;i++)
            E[i].clear();

    }

    return 0;
}


