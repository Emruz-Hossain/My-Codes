#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
#define inf 1<<30
#define max 1010
vector<int>E[max];
queue<int>Q;
int dis[max][max];
int cl[]={-1,1,0,0};
int rw[]={0,0,-1,1};
int main()
{
    int R,C,n,r,b,c,i,j,ux,uy,vx,vy,dr,dc,sr,sc;
    while(1)
    {
        scanf("%d %d",&R,&C);
        if(R==0&&C==0)
            break;
        for(i=0;i<=R;i++)
        {
            for(j=0;j<=C;j++)
            {
                dis[i][j]=inf;
                E[i].push_back(1);

            }
        }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&r,&b);
        for(j=0;j<b;j++)
        {
            scanf("%d",&c);
            E[r][c]=-1;
        }
    }
    scanf("%d %d %d %d",&sr,&sc,&dr,&dc);
    Q.push(sr);
    Q.push(sc);
    dis[sr][sc]=0;
    while(!Q.empty())
    {
        ux=Q.front();Q.pop();
        uy=Q.front();Q.pop();
        for(i=0;i<4;i++)
        {
            vx=ux+rw[i];
            vy=uy+cl[i];
            if(vx>=0&&vy>=0&&vx<=R&&vy<=C&&dis[vx][vy]>dis[ux][uy]+1)
            {
                if(E[vx][vy]==-1)
                    continue;
                dis[vx][vy]=dis[ux][uy]+1;
                Q.push(vx);
                Q.push(vy);
            }
        }
    }
    printf("%d\n",dis[dr][dc]);
    }
    return 0;
}
