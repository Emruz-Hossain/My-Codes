#include<stdio.h>
int vesel,continer,capacity[1500];
int checker(int avg)
{
    int k,sum=0,j,c=0;
    k=1;
    while(k<=continer)
    {
        sum=0;
         for(j=c;j<vesel;j++)
         {
             sum+=capacity[j];
             if(sum>avg)
             {
                 c=j;
                 k++;
                break;
             }

         }
          if(j==vesel)
          break;
    }
    if(k<=continer)
        return 1;
    else
    return 0;
}
int main()
{
    int i,maximal,minimal,avg,p,x,t;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%d %d",&vesel,&continer);
        maximal=0;
        for(i=0;i<vesel;i++)
            scanf("%d",&capacity[i]);
        minimal=capacity[0];
        for(i=0;i<vesel;i++)
        {
            maximal+=capacity[i];
            if(minimal<capacity[i])
                minimal=capacity[i];
        }
        while(minimal<=maximal)
        {
            avg=(maximal+minimal)/2;
            p=checker(avg);
            if(p==1)
            {
                p=checker(avg-1);
                if(p==1)
                maximal=avg-1;
                else
                break;
            }

            if(p==0)
                minimal=avg+1;
        }
        printf("Case %d: %d\n",x,avg);
    }
    return 0;
}
