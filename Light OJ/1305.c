#include<stdio.h>
#include<math.h>
int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4,t,i,s,x,y,h,a;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        x4=x1+x3-x2;
        y4=y1+y3-y2;
        x=x4-x1;
        y=y1;
        h=sqrt((x-x4)*(x-x4)+(y-y4)*(y-y4));
        if(h<0)
            h=-1*h;
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(a<0)
            a=-1*a;
        s=a*h;
        printf("Case %d: %d %d %d\n",i,x4,y4,s);
    }
    return 0;
}
