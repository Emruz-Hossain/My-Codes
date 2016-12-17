#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int mod(int a,int b)
{
    int r=a%b;
    return r<0?r+b:r;
}
int main()
{
//    double sum=0.0;
//    int i;
//    for(i=1;i<=100000;i++)
//        sum+=(double)100000/(double)i;
//    printf("%lf\n",sum);
int n,m;
while(scanf("%d %d",&n,&m)==2)
{
    printf("%d\n",mod(n,m));
}
    return 0;
}
//1209114
//1309014
