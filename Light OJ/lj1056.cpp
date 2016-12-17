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
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i;
    double a,b,l,h,m,r,ang,s,p=0;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf : %lf",&a,&b);
        l=0;h=400;
        while(fabs(l-h)>eps)
        {
            m=(l+h)/2;
            double k=(b*m)/a;
            r=sqrt(m*m+k*k)/2;
            ang=asin((k/2)/r);
            ang=2*(ang*180)/(2*acos(0));
            s=(2*acos(0)*r*ang)/180;
            p=(2*m)+(2*s);
            if(p>400)
              h=m;
            else
                l=m;
        }
        printf("Case %d: %.12lf %.12lf\n",i,l,((l*b)/a));
    }


    return 0;
}


