#include<stdio.h>
#include<math.h>
int main()
{
    double angle,n,pi,r,area;
    pi=2*acos(0);
    while(scanf("%lf %lf",&r,&n)==2)
    {
        angle=((360/n)*pi)/180;
        area=(r*r*n*sin(angle))/2;
        printf("%.3lf\n",area);
    }
    return 0;

}
