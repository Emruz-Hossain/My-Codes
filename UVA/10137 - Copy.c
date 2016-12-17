#include<stdio.h>
int main()
{
    double cost[10025],avg,sum,exchange;
    int n,i;
    while(1)
    {
        exchange=0;
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&cost[i]);
            sum+=cost[i];
        }
        avg=sum/n;
        for(i=0;i<n;i++)
        {
            if(cost[i]>avg)
                exchange+=(cost[i]-avg);
        }
        printf("$%.2lf\n",exchange);
    }
    return 0;
}
