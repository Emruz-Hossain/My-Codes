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
#define sz 100
#define eps 1e-9
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
char str[sz][sz],ss[sz],maz[sz][sz];
int visit[sz][sz];
void dfs(int x,int y)
{
    int i,p,q;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    str[x][y]='#';
    for(i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>0&&p<30&&q<80&&str[p][q]==' ')
            dfs(p,q);
    }
}
int main()
{
    int i,j,p,t,k,x;
    char ch;
    //    freopen("output.txt","w",stdout);
       // freopen("input.txt","r",stdin);
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        memset(visit,0,sizeof(visit));
        x=0;
        while(gets(ss))
        {
            strcpy(str[x++],ss);
            strcpy(maz[x-1],ss);
            if(ss[0]=='_')
            break;
        }
        k=0;p=0;
        for(i=0;i<30;i++)
        {
            for(j=0;j<80;j++)
            {
                if(str[i][j]=='*'&&visit[i][j]==0)
                {
                    dfs(i,j);
                    k=1;
                    break;
                }
            }
            if(k==1)
                break;
        }
//        for(i=0;i<x;i++)
//            puts(maz[i]);
        for(i=0;i<x;i++)
            puts(str[i]);
    }


    return 0;
}


