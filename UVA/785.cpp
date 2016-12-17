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
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
char str[sz][sz],ss[sz],maz[sz][sz];
int visit[sz][sz];
void dfs(int x,int y,char ph,char ch)
{
    int i,p,q;
    if(visit[x][y]==1&&str[x][y]==ch)
        return;
    visit[x][y]=1;
    str[x][y]=ph;
    for(i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>0&&p<30&&q<80&&(str[p][q]==' '||str[p][q]==ph))
            dfs(p,q,ph,ch);
    }
}
int main()
{
    int i,j,p,t,k,x=0;
    char ch;
    //    freopen("output.txt","w",stdout);
       // freopen("input.txt","r",stdin);
    while(gets(ss))
    {
        memset(visit,0,sizeof(visit));
        strcpy(str[x++],ss);
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
                if(str[i][j]!=' '&&p==0)
                {
                    ch=str[i][j];
                    p=1;
                    continue;
                }
                if(str[i][j]!=ch&&str[i][j]!=' '&&visit[i][j]==0)
                {
                    dfs(i,j,str[i][j],ch);
                }
            }
        }
        for(i=0;i<x;i++)
            puts(str[i]);
        x=0;
    }


    return 0;
}



