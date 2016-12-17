// BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<queue>
#define S 105
#define inf 1<<30
using namespace std;
queue<int>Q;
char st[S][S];
int dis[S][S],P[S][S][2],R[]={0,0,-1,1},C[]={1,-1,0,0};
void path(int x,int y,int sx,int sy)
{
    if(x==-1)
    return;
    path(P[x][y][0],P[x][y][1],sx,sy);
    if(x!=sx||y!=sy)
    printf(" ");
    printf("%d %d",x,y);
}
int main()
{
    int n,m,i,j,x,y,xx,yy,sx,sy,dx,dy;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",st[i]);
            for(j=0;j<m;j++)
            dis[i][j]=inf,P[i][j][0]=0;
        }
        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
        P[sx][sy][0]=-1;
        Q.push(sx);
        Q.push(sy);
        dis[sx][sy]=0;
        while(!Q.empty())
        {
            x=Q.front(),Q.pop();
            y=Q.front(),Q.pop();
            for(i=0;i<4;i++)
            {
                xx=x+R[i];
                yy=y+C[i];
                if(xx<n&&xx>=0&&yy>=0&&yy<m&&dis[xx][yy]>dis[x][y]+1)
                {
                    if(st[xx][yy]=='#')
                    continue;
                    dis[xx][yy]=dis[x][y]+1;
                    Q.push(xx);
                    Q.push(yy);
                    P[xx][yy][0]=x;
                    P[xx][yy][1]=y;
                }
            }
        }
        printf("%d\n",dis[dx][dy]);
        path(dx,dy,sx,sy);
        printf("\n");
    }
    return 0;
}
