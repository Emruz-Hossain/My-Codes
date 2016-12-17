#include<stdio.h>
#include<string.h>
int main()
{
    int coin[100],way[1000],i,j,n,c,p;
    scanf("%d",&c);
    for(i=0;i<c;i++)
        scanf("%d",&coin[i]);
    scanf("%d",&n);
    memset(way,0,sizeof(way));
    way[0]=1;
    for(i=0;i<c;i++)
    {
        for(j=coin[i];j<=n;j++)
        {
            p=j-coin[i];
            way[j]=way[p]+way[j];
        }
    }
    printf("way=%d\n",way[n]);
    return 0;
}
