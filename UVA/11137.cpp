#include<stdio.h>
#include<string.h>
long long way[10010];
int main()
{
    int coin[30];
    int i,j,n,p;
    for(i=0;i<21;i++)
        coin[i]=(i+1)*(i+1)*(i+1);
    while(scanf("%d",&n)==1)
    {
        memset(way,0,sizeof(way));
        way[0]=1;
        for(i=0;i<21;i++)
        {
            for(j=coin[i];j<=n;j++)
            {
                p=j-coin[i];
                way[j]=way[j]+way[p];
            }
        }
        printf("%lld\n",way[n]);
    }
    return 0;
}
