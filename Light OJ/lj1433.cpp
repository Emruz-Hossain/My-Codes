
#include<stdio.h>
#include<math.h>
#define pi 3.14159265
int main()
{
    int t,p;
    double ax,ay,bx,by,ox,oy,m1,m2,ang,r,a,b,c,i,j,s,l;
    scanf("%d",&t);
    for(p=1;p<=t;p++){
    scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
    m1=(ay-oy)/(ax-ox);
    m2=(by-oy)/(bx-ox);
    a=(m1-m2)/(1+m1*m2);
    ang=atan(a);
    i=(ax-ox);
    j=(ay-oy);
    r=sqrt((i*i)+(j*j));
    s=r*ang;
    printf("Case %d: %0.10lf\n",p,fabs(s));
    }

    return 0;
}
