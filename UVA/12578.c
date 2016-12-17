#include<stdio.h>
#include<math.h>
int main()
{
    double rec[150],cir[150],radious,width,length;
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&length);
        radious=length/5;
        width=(length*6)/10;
        cir[i]=acos(-1)*(radious*radious);
        rec[i]=(length*width)-cir[i];
    }
    for(i=0;i<n;i++)
        printf("%.2lf %.2lf\n",cir[i],rec[i]);
    return 0;
}
