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
void star(int x,int y,int w,int h);
char str[sz][sz];
int visit[sz][sz];
int R[]={1,-1,0,0};
int C[]={0,0,1,-1};
int RR[]={1,-1,0,0};
int CC[]={0,0,1,-1};
int cmp,xx,yy;
struct st
{
    int xx,yy;
}a;
vector<st>V;
void dfs(int x,int y,int w,int h)
{
    int i,p,q;
    if(visit[x][y]==1||str[x][y]=='.')
        return;
    visit[x][y]=1;
    for(i=0;i<4;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<h&&q<w)
        {
            if(str[p][q]=='X'&&visit[p][q]==0)
             dfs(p,q,w,h);
            else if(str[p][q]=='*'&&visit[p][q]==0)
            {
                a.xx=p;
                a.yy=q;
                V.push_back(a);
            }

        }

    }

}
void star(int x,int y,int w,int h)
{
    int i,p,q;
    if(visit[x][y]==1&&str[x][y]=='*')
        return;
    if(str[x][y]=='X'&&visit[x][y]==0)
    {
        dfs(x,y,w,h);
        cmp++;
        if(V.size()!=0)
        {
            for(int k=0;k<V.size();k++)
            star(V[k].xx,V[k].yy,w,h);
            V.clear();
        }

    }
    visit[x][y]=1;
    for(i=0;i<4;i++)
    {
        p=x+RR[i];
        q=y+CC[i];
        if(p>=0&&q>=0&&p<h&&q<w)
        {
            if(str[p][q]=='X'&&visit[p][q]==0)
            {
                dfs(p,q,w,h);
                cmp++;
                star(p,q,w,h);
            }
            else if(str[p][q]=='*')
                star(p,q,w,h);
        }
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,w,h,i,j;
    vector<int>E;
    t=0;
    while(1)
    {
        scanf("%d %d",&w,&h);
        if(w==0&&h==0)
            break;
        t++;
        cmp=0;
        memset(visit,0,sizeof(visit));
        E.clear();
        V.clear();
        for(i=0;i<h;i++)
        {
            scanf("%s",str[i]);
        }
        printf("Throw %d\n",t);
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if((str[i][j]=='*'||str[i][j]=='X')&&visit[i][j]==0)
                {
                    cmp=0;
                    star(i,j,w,h);
                    if(cmp>0)
                    E.push_back(cmp);
                }
            }
        }
        sort(E.begin(),E.end());
        for(i=0;i<E.size();i++)
        {
            printf("%d",E[i]);
            if(i<E.size()-1)
                printf(" ");
        }
        if(E.size()==0)
            printf("0");
        printf("\n");
        printf("\n");
    }


    return 0;
}
