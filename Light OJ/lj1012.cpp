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
#define inf 1<<25
#define sz 200
#define eps 1e-9
char str[sz][sz];
int visit[sz][sz],tt,w,h;
int R[]={1,-1,0,0};
int C[]={0,0,1,-1};
void dfs(int x,int y)
{
    int p,q,i;
    if(visit[x][y]==1||str[x][y]=='#')
        return;
    visit[x][y]=1;
    tt++;
    for(i=0;i<4;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<h&&q<w&&str[p][q]=='.')
            dfs(p,q);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,x,i,j;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        memset(visit,0,sizeof(visit));
        scanf("%d %d",&w,&h);
        for(i=0;i<h;i++)
            scanf("%s",&str[i]);
            tt=0;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(str[i][j]=='@')
                {
                    dfs(i,j);
                }

            }
        }
        printf("Case %d: %d\n",x,tt);
    }
    return 0;
}


