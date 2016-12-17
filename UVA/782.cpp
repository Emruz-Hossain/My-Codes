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
char str[sz][sz],ss[sz];
int visit[sz][sz];
void dfs(int x,int y,int n,int m,char ch)
{
    int i,p,q;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    if(str[x+1][y]==ch||str[x-1][y]==ch||str[x][y+1]==ch||str[x][y-1]==ch)
        str[x][y]='#';
    for(i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<n&&q<m&&str[p][q]==' ')
            dfs(p,q,n,m,ch);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i,j,p,x;
    char ch;
    scanf("%d%c",&t,&ch);
   // getchar();
    while(t--)
    {
        x=0;
        memset(visit,0,sizeof(visit));
        gets(ss);
        strcpy(str[x++],ss);
        if(ss[0]=='_');
        {
            p=0;
            for(i=0;i<x;i++)
            {
                for(j=0;j<strlen(str[0]);j++)
                {
                    if(str[i][j]!=' '||str[i][j]!='*'||str[i][j]!='#')
                    {
                        ch=str[i][j];
                        p=1;break;
                    }
                }
                if(p==1)
                    break;
            }
            p=0;
            for(i=0;i<x;i++)
            {
                for(j=0;j<strlen(str[0]);j++)
                {
                    if(str[i][j]=='*')
                    {
                        p=1;
                        str[i][j]=' ';
                        dfs(i,j,x,strlen(str[0]),ch);
                        break;
                    }
                }
                if(p==1)
                    break;
            }
            for(i=0;i<x;i++)
                puts(str[i]);
            break;
        }
    }


    return 0;
}


