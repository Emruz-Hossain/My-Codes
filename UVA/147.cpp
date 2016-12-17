#include<stdio.h>
#include<string.h>
long long  way[30010];
int main()
{
    int coin[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
    double p,c1;
    int n,i,j,q,d,c;
    while(1)
    {
        c=0;
        c1=0;
        memset(way,0,sizeof(way));
        way[0]=1;
        scanf("%d.%d",&d,&c);
        if(d==0&&c==0)
            break;
        n=d*100+c;
        c1=c;
        p=(d+c1/100);
        for(i=0;i<11;i++)
        {
            for(j=coin[i];j<=n;j++)
            {
                q=j-coin[i];
                way[j]=way[q]+way[j];
            }
        }
        printf("%6.2lf%17lld\n",p,way[n]);

    }
    return 0;
}
