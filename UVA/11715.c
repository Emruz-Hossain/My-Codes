#include<stdio.h>
#include<math.h>
int main()
{
    int n,i=1;
    double u,v,t,a,s;

    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        else
        {
            if(n==1)
            {
                 scanf("%lf %lf %lf",&u,&v,&t);
                 a=(v-u)/t;
                 s=(u*t)+(0.5*a*t*t);
                 printf("Case %d: %.3lf %.3lf\n",i,s,a);
            }
            if(n==2)
            {
                 scanf("%lf %lf %lf",&u,&v,&a);
                 s=((v*v)-(u*u))/(2*a);
                 t=(v-u)/a;
                 printf("Case %d: %.3lf %.3lf\n",i,s,t);
            }
            if(n==3)
            {
                 scanf("%lf %lf %lf",&u,&a,&s);
                 v=sqrt((u*u)+(2*a*s));
                 t=(v-u)/a;
                 printf("Case %d: %.3lf %.3lf\n",i,v,t);
            }
            if(n==4)
            {
                 scanf("%lf %lf %lf",&v,&a,&s);
                 u=sqrt((v*v)-2*a*s);
                 t=(v-u)/a;
                 printf("Case %d: %.3lf %.3lf\n",i,u,t);
            }
            i++;
        }
    }
    return 0;
}
