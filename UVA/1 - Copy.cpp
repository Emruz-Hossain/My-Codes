#include<stdio.h>
#include<math.h>

int main()
{
    int n,m,i,j,a,b,d1,d2,d3,d4;

    scanf("%d %d %d %d %d %d",&n,&m,&i,&j,&a,&b);
    if((i==1&&j==1)||(i==1&&j==m)||(i==n&&j==1)||(i==n&&j==m))
        printf("0\n");
    else {
    d1=distance(1,1,i,j);
    d2=distance(1,m,i,j);
    d3=distance(n,1,i,j);
    d4=distance(n,m,i,j);
    if(d1==0&&d2==0&&d3==0&&d4==0)
        printf("Poor Inna and pony!\n");
    else
    {
        if(d1==0)
            d1=d2;
        if(d1==0)
            d1=d3;
        if(d1==0)
            d1=d4;
        if(d1!=0)
        {
             if(d1>d2&&d2!=0)
            d1=d2;
            if(d1>d3&&d3!=0)
            d1=d3;
            if(d1>d4&&d4!=0)
            d1=d4;
        }
        printf("%d\n",d1);
    }}
    return 0;

}

