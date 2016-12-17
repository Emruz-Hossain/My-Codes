#include<stdio.h>
int main()
{
    int test,i;
    double v1,v2,v3,a1,a2,t,d,db,t1,t2;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        t1=v1/a1;
        t2=v2/a2;
        if(t1>t2)
            t=t1;
        else
            t=t2;
        db=v3*t;
        d=((v1*v1)/(2*a1))+((v2*v2)/(2*a2));
        printf("Case %d: %.10lf %.10lf\n",i,d,db);
    }
    return 0;
}
