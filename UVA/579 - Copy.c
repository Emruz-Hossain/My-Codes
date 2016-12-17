#include<stdio.h>
int main()
{
    int h,m;
    double angle;
    while(1)
    {
        scanf("%d:%d",&h,&m);
        if(h==0&&m==0)
            break;
        angle=(30*h)-(5.5*m);
        if(angle<0)
            angle=-1*angle;
        if(angle>180)
            angle=360-angle;
        printf("%.3lf\n",angle);
    }
    return 0;
}
