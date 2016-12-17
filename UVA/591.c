#include<stdio.h>
int main()
{
    int height[150],wall,avarege,moves,i,sum,t=0;
    while(1)
    {
        sum=0;
        moves=0;
        scanf("%d",&wall);
        if(wall==0)
            break;
        else
        {
            t++;
            for(i=0;i<wall;i++)
                scanf("%d",&height[i]);
            for(i=0;i<wall;i++)
                sum=sum+height[i];
            avarege=sum/wall;
            for(i=0;i<wall;i++)
            {
                if(height[i]>avarege)
                    moves=moves+(height[i]-avarege);
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",t,moves);
    }
    return 0;
}
