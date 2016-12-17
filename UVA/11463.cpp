#include<stdio.h>
int main()
{
    int n,r,i,j,k,t,T,u,v,s,d;
    int dis[200][200];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&r);
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                dis[i][j]=1<<29;
                if(i==j)
                    dis[i][j]=0;
            }
        }

        for(j=0;j<r;j++)
        {
            scanf("%d %d",&u,&v);
            dis[u][v]=dis[v][u]=1;
        }
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
        scanf("%d %d",&s,&d);
        printf("Case %d: %d\n",t,dis[s][d]);
    }
    return 0;
}
