#include<stdio.h>
int main()
{
    int H,U,D,F,day,k,climb;
    while(1)
    {
        scanf("%d",&H);
        if(H==0)
            break;
        else
        {
            scanf("%d %d %d",&U,&D,&F);
            day=0;
            k=0;
            F=(F/100)*H;
            while(1)
            {
                day++;
                if(day==1)
                    climb=U;
                else
                    {
                        U=U-F;
                climb+=U;
                    }
                if(climb>=H)
                {
                    k=1;
                    break;
                }
                climb=climb-D;
                if(climb<=0)
                {
                    k=0;
                    break;
                }
            }
            if(k==1)
                printf("success on day %d\n",day);
            if(k==0)
                printf("failure on day %d\n",day);
        }
    }
    return 0;
}
