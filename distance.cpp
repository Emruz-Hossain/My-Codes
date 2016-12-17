//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#define S 205
#define inf 1<<25
int dis[S][S];
int main()
{
int n,m,i,j,k,u,v,w;
scanf("%d%d",&n,&m);
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
    scanf("%d%d",&u,&v);
    dis[u][v]=dis[v][u]=1;
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
for(i=1;i<=n;i++)
    printf("1->%d=%d\n",i,dis[1][i]);
return 0;
}
