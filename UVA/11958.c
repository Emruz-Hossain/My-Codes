#include<stdio.h>
int main()
{
    int h,m,time_need[150],test_case,need,i,number,current_time,journey,result,minimal,j;
    scanf("%d",&test_case);
    for(j=1;j<=test_case;j++)
    {
        scanf("%d",&number);
        scanf("%d:%d",&h,&m);
        current_time=(h*60)+m;
        for(i=0;i<number;i++)
        {
            scanf("%d:%d %d",&h,&m,&journey);
            need=(h*60)+m+journey;
            if(current_time>(h*60)+m)
                    result=1440+need-current_time;
            else
                result=need-current_time;
            time_need[i]=result;
        }
        minimal=time_need[0];
        for(i=0;i<number;i++)
        {
            if(minimal>time_need[i])
                minimal=time_need[i];
        }
        printf("Case %d: %d\n",j,minimal);
    }
    return 0;
}
