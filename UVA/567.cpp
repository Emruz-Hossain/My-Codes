#include<stdio.h>
#include<string.h>
int main()
{
    int n,r,i,j,k,s,d,t=0,m,u;
   int  dis[40][40];
    while(scanf("%d",&u)==1)
    {
        t++;
        for(i=0;i<=20;i++)
        {
            for(j=0;j<=20;j++)
                {
                    dis[i][j]=1<<29;
                    if(i==j)
                        dis[i][j]=0;
                }
        }
        for(i=0;i<u;i++)
        {
            scanf("%d",&m);
            dis[1][m]=dis[m][1]=1;
        }
        for(r=2;r<=19;r++)
        {
            scanf("%d",&u);
            for(j=0;j<u;j++)
            {
                scanf("%d",&m);
                dis[r][m]=dis[m][r]=1;
            }
        }
        for(k=1;k<=20;k++)
        {
            for(i=1;i<=20;i++)
            {
                for(j=1;j<=20;j++)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
        scanf("%d",&n);
        printf("Test Set #%d\n",t);
        for(i=0;i<n;i++)

        {
            scanf("%d %d",&s,&d);
            printf("%2d to %2d: %d\n",s,d,dis[s][d]);
        }
        printf("\n");

    }
 return 0;
}
