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
#define sz 30
#define eps 1e-9
int R[]={1,-1,0,0};
int C[]={0,0,1,-1};
int tt,visit[sz][sz];
char str[sz][sz];
void dfs(int x,int y,int m,int n,char ch)
{
    int i,p,q;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    tt++;
    for(i=0;i<4;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(q==n)
            q=0;
        if(q==-1)
            q=n-1;
        if(p>=0&&q>=0&&p<m&&str[p][q]==ch)
            dfs(p,q,m,n,ch);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int m,n,x,y,i,j,mx;
    while(scanf("%d %d",&m,&n)==2)
    {
        mx=0;
        memset(visit,0,sizeof(visit));
        for(i=0;i<m;i++)
            scanf("%s",&str[i]);
        scanf("%d %d",&x,&y);
        tt=0;
        dfs(x,y,m,n,str[x][y]);
        tt=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(str[i][j]==str[x][y]&&visit[i][j]==0)
                {
                    tt=0;
                    dfs(i,j,m,n,str[x][y]);
                    mx=max(mx,tt);
                }
            }
        }
        printf("%d\n",mx);
    }


    return 0;
}

