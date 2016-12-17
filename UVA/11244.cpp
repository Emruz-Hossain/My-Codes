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
int tt;
int R[]={1,-1,0,0,1,1,-1,-1};
int C[]={0,0,1,-1,1,-1,1,-1};
char str[sz][sz];
int visit[sz][sz];
void dfs(int x,int y,int m,int n)
{
    int i,p,q;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    tt++;
    for(i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<m&&q<n&&str[p][q]=='*')
            dfs(p,q,m,n);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int i,j,m,n,cmp;
    while(1)
    {
    scanf("%d %d",&m,&n);
    if(m==0&&n==0)
        break;
    for(i=0;i<m;i++)
    {
        scanf("%s",&str[i]);
    }
    memset(visit,0,sizeof(visit));
    cmp=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(str[i][j]=='*'&&visit[i][j]==0)
            {
                tt=0;
                dfs(i,j,m,n);
                if(tt==1)
                cmp++;
            }


        }
    }
    printf("%d\n",cmp);
    }

    return 0;
}


