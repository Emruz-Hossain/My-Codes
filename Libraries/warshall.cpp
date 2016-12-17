//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#define S 205
#define inf 1<<29
int dis[S][S];
int main()
{
    int n,m,i,j,k,u,v,w;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                dis[i][j]=inf;
                if(i==j)
                dis[i][j]=0;
            }
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            dis[u][v]=dis[v][u]=w;
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
        while(scanf("%d%d",&u,&v)==2)
        printf("%d\n",dis[u][v]);
    }
    return 0;
}
