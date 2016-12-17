#include<stdio.h>
int main()
{
    int pn,bdg,h,w,prc,b,i,j,c;
    while(scanf("%d %d %d %d",&pn,&bdg,&h,&w)==4)
    {
        c=bdg+5;
    for(j=0;j<h;j++)
    {
        scanf("%d",&prc);
        for(i=1;i<=w;i++)
        {
            scanf("%d",&b);
            if(b>=pn)
            {
                if(prc*pn<=bdg)
                {
                   if(c>prc*pn)
                    c=prc*pn;
                }
            }
        }
    }
        if(c<=bdg)
            printf("%d\n",c);
        else
            printf("stay home\n");

    }
    return 0;
}
