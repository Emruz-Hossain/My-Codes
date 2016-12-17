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
#define sz 2400
#define eps 1e-9
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
char str[sz][sz],ss[sz],sstr[sz][sz];
int ans[sz][sz],visit[sz][sz];
void dfs(int x,int y,char ch,int n,int m,int d)
{
    int i,p,q;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    ans[x][y]=d;
    for(i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<n&&q<m&&sstr[p][q]==ch)
            dfs(p,q,ch,n,m,d);
    }
}
void output(int x)
{
    int p, i,j,sp=0,maxx;

        p=1;
            for(i=0;i<x;i++)
            {
                for(j=0;j<strlen(sstr[0]);j++)
                {
                    if(visit[i][j]==0)
                    {
                        dfs(i,j,sstr[i][j],x,strlen(sstr[0]),p);
                        p++;
                    }

                }
            }
            maxx=0;
            {
                for(i=0;i<x;i++)
                    maxx=max(maxx,ans[i][0]);
                while(maxx)
                {
                    sp++;
                    maxx/=10;
                }
            }
            for(i=0;i<x;i++)
            {
                for(j=0;j<strlen(sstr[0]);j++)
                {
                    if(j==0)
                    {
                        if(sp==1)
                         printf("%d",ans[i][j]);
                        else if(sp==2)
                             printf("%2d",ans[i][j]);
                        else if(sp==3)
                            printf("%3d",ans[i][j]);
                        else if(sp==4)
                            printf("%4d",ans[i][j]);
                        else if(sp==5)
                             printf("%5d",ans[i][j]);
                        else if(sp==6)
                            printf("%6d",ans[i][j]);
                        else if(sp==7)
                            printf("%7d",ans[i][j]);
                        else if(sp==8)
                            printf("%8d",ans[i][j]);
                        else if(sp==9)
                            printf("%9d",ans[i][j]);
                        else if(sp==10)
                            printf("%10d",ans[i][j]);
                    }
                    else
                    {
                        if(p<10)
                         printf("%d",ans[i][j]);
                         else if(p<100)
                            printf("%2d",ans[i][j]);
                         else if(p<1000)
                            printf("%3d",ans[i][j]);
                         else if(p<10000)
                            printf("%3d",ans[i][j]);
                        else if(p<100000)
                            printf("%4d",ans[i][j]);
                        else if(p<1000000)
                            printf("%5d",ans[i][j]);
                         else if(p<10000000)
                            printf("%6d",ans[i][j]);
                        else if(p<100000000)
                            printf("%7d",ans[i][j]);
                        else if(p<1000000000)
                            printf("%8d",ans[i][j]);
                        else if(p<10000000000)
                            printf("%9d",ans[i][j]);
                        else if(p<100000000000)
                            printf("%10d",ans[i][j]);

                    }
//                    if(j<strlen(sstr[0])-1)
//                        printf("");
                }
                printf("\n");
            }
            printf("%%\n");
}
int main()
{
        freopen("output.txt","w",stdout);
       // freopen("input.txt","r",stdin);
    int i,j,p,x=0,m,n,y,k;
    while(1)
    {
        x=0;
        memset(ans,0,sizeof(ans));
        memset(visit,0,sizeof(visit));
        while(gets(ss))
        {
            k=0;
        if(ss[0]=='%')
        {
            output(x);
            k=1;
            break;
        }
        else
        {
            y=0;
             strcpy(str[x],ss);
             for(i=0;i<strlen(str[x]);i++)
                if(str[x][i]!=' ')
                    sstr[x][y++]=str[x][i];
            sstr[x][y]=NULL;
            x++;
        }
        }
        if(k==0)
        {
            output(x);
            break;
        }
    }
    return 0;
}

