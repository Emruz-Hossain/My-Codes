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
struct st
{
    int p;
    char ch;
}ar[25005];
int tt;
int R[]={1,-1,0,0};
int C[]={0,0,1,-1};
char str[sz][sz];
int visit[sz][sz];
void dfs(int x,int y,int m,int n,char ch)
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
        if(p>=0&&q>=0&&p<m&&q<n&&str[p][q]==ch)
            dfs(p,q,m,n,ch);
    }
}
bool cmp(st a,st b)
{
    if(a.p>b.p)
        return true;
    else if(a.p<b.p)
        return false;
    else
    {
        return (a.ch<b.ch)?true:false;
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int i,j,m,n,pp=0,x;
    while(1)
    {
        pp++;
    scanf("%d %d",&m,&n);
    if(m==0&&n==0)
        break;
    for(i=0;i<m;i++)
    {
        scanf("%s",&str[i]);
    }
    memset(visit,0,sizeof(visit));
    x=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(str[i][j]>='A'&&str[i][j]<='Z'&&visit[i][j]==0)
            {
                tt=0;
                dfs(i,j,m,n,str[i][j]);
                ar[x].p=tt;
                ar[x].ch=str[i][j];
                ++x;
            }


        }
    }
    sort(ar,ar+x,cmp);
    printf("Problem %d:\n",pp);
    for(i=0;i<x;i++)
    {
        printf("%c %d\n",ar[i].ch,ar[i].p);
    }
    }

    return 0;
}


