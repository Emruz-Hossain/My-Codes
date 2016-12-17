#include<stdio.h>
int main()
{
    int x,y,z,t,i,s;
    scanf("%d",&t);
    if(t<20)
    {
        for(i=1;i<=t;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            if((x>y&&x<z)||(x<y&&x>z))
                s=x;
            else if((y>x&&y<z)||(y<x&&y>z))
                s=y;
            else
                s=z;
            printf("Case %d: %d\n",i,s);

        }

    }
    return 0;
}
