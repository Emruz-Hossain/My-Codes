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
int visit[sz][sz],maxx,l,k,r;
char str[sz][sz];
int R[]={1,-1,0,0,1,1,-1,-1};
int C[]={0,0,1,-1,1,-1,1,-1};
void dfs(int x,int y)
{
    int p,q;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    r++;
    maxx=max(maxx,r);
    for(int i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<k&&q<l&&str[p][q]=='1')
            dfs(p,q);
    }
}
int main()
{
       //freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i,j,x;
    char ss[100],ch,chh;
    scanf("%d%c",&t,&chh);
    getchar();
    while(t--)
    {
        x=0;
        maxx=0;
        while(gets(ss))
        {
        if(strlen(ss)==0)
            break;
        else
            strcpy(str[x],ss);
            x++;
        }
        k=x;
        l=strlen(str[0]);
        memset(visit,0,sizeof(visit));
        for(i=0;i<x;i++)
        {
            for(j=0;j<l;j++)
            {
                if(str[i][j]=='1'&&visit[i][j]==0)
                {
                    r=0;
                     dfs(i,j);
                }

            }
        }
        printf("%d\n",maxx);
        if(t>0)
            printf("\n");
    }


    return 0;
}

