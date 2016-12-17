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
#define eps 1e-10
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int i,t;
    double ll,c,n,s,l,h,m,p,r,ang;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %lf %lf",&ll,&n,&c);
        if(n==0)
        {
            l=0;
            printf("Case %d: %.12lf\n",i,l);
        }
        else
        {
        s=(1+n*c)*ll;
        l=0;h=ll;
        while(fabs(l-h)>eps)
        {
            m=(l+h)/2;
            r=(m/2)+(ll*ll)/(8*m);
            ang=asin((ll/2)/r);
            ang=2*(ang*180)/(2*acos(0));
            p=(2*acos(0)*r*ang)/180;
            if(p>s)
                h=m;
            else
                l=m;

        }
        printf("Case %d: %.12lf\n",i,l);
        }
    }


    return 0;
}


