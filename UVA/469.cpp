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
char str[sz][sz],ss[sz];
int visit[sz][sz],tt;
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
void dfs(int x,int y,int n,int m)
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
        if(p>=0&&q>=0&&p<n&&q<m&&str[p][q]=='L')
            dfs(p,q,n,m);

    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i,r,c,x;
    char ch;
    scanf("%d%c",&t,&ch);
    getchar();
    while(t--)
    {
        x=0;
        while(1)
        {
        scanf("%s",&ss);
        if(strlen(ss)==1)
        {
            if(ss[0]>='1'&&ss[0]<='9')
                break;
            else
                strcpy(str[x++],ss);
        }
        else
            strcpy(str[x++],ss);
        }
        {
            r=ss[0]-'48';
            getchar();
            scanf("%d",&c);
            getchar();
            tt=0;
            dfs(r,c,strlen(str[0]),x);
            printf("%d\n",tt);
            while(1)
            {
                gets(ss);
                if(strlen(ss)<=0)
                    break;
                else
                    sscanf(ss,"%d %d",&r,&c);
                    tt=0;
                dfs(r,c,strlen(str[0]),x);
                printf("%d\n",tt);
            }
            if(t!=0)
                printf("\n");
            if(t!=0)
            {
                getchar();
                getchar();
            }
        }
    }


    return 0;
}


