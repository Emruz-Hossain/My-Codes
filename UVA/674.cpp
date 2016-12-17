#include<stdio.h>
#include<string.h>
long long  way[7500];
int main()
{
    int coin[]={1,5,10,25,50};
    int n,i,j,p;
    while(scanf("%d",&n)==1)
    {
        memset(way,0,sizeof(way));
        way[0]=1;
        for(i=0;i<5;i++)
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

