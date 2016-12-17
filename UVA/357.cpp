#include<stdio.h>
#include<string.h>
long long  way[30005];
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
        if(way[n]==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",way[n],n);
    }
    return 0;
}
