#include<stdio.h>
#include<math.h>
int main()
{
    int R,N;
    double area,angle,pi;
     while(scanf("%d%d",&R,&N)==2)
     {
         pi=2*acos(0);
         angle=(pi*(360/N))/180;
         area=((R*R)*N*sin(angle))/2;
         printf("%.3lf\n",area);
     }
     return 0;

}
