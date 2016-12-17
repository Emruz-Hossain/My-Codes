#include<stdio.h>
int main()
{
    int c,i;
    double t1,t2,d,h1,m1,h2,m2,ta,r,tb;
    scanf("%d",&c);
    for(i=1;i<=c;i++)
    {
        ta=0;
        tb=0;
        scanf("%lf:%lf",&h1,&m1);
        scanf("%lf:%lf",&h2,&m2);
        scanf("%lf",&d);
        t1=h1*60+m1;
        t2=h2*60+m2;
        if(t1>=t2)
        {
            ta=t1-t2+d;
        r=t2+2*d-t1;
        if(t1<t2+2*d)
            tb=2*d-r/2;
        else
            tb=t1-t2;
        }
        else
        {
            ta=t2-t1+d;
            r=t2-t1;
            if(d<t2-t1)
            tb=d;
            else
                tb=d-r;
        }

        printf("%.1lf %.1lf\n",ta,tb);
    }
    return 0;
}
