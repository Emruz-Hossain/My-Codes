//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define inf 1<<25
#define sz 2000
#define eps 1e-9
double Min(double a,double b)
{
    return (a<b)?a:b;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    double x,y,c,l,h,m;
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %lf %lf",&x,&y,&c);
        l=0;h=Min(x,y);
        while(fabs(l-h)>eps)
        {
            m=(l+h)/2;
            double p=sqrt(x*x-m*m);
            double q=sqrt(y*y-m*m);
            if((p*q)/(p+q)>c)
                l=m;
            else
                h=m;
        }
        printf("Case %d: %.10lf\n",i,l);
    }

    return 0;
}


