#include<stdio.h>
#include<math.h>
int main()
{
    int t,i;
    double r,c_area,s_area,area,pi;
    pi=2*acos(0.0);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&r);
        c_area=pi*r*r;
        r=2*r;
        s_area=r*r;
        area=s_area-c_area;
        printf("Case %d: %.2lf\n",i,area);
    }
    return 0;
}
