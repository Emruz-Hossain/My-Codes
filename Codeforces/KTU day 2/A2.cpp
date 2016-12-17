//BISMILLAHIR RAHMANIR RAHIM
// OUM NAMA MA SWARASATI

#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

#define cl(vctr) vctr.clear()
#define ms(v, ar) memset(ar, v, sizeof(ar))

#define inf (ll)1ll << 30
#define pi (double)(2.0 * acos( 0.0 ))
#define eps 1E-9
#define sz 100000 + 5
#define mod 1000000000 + 7

using namespace std;
typedef long long int ll;

struct P
{
    double x,y;
    P(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}


int main()
{
    double a1,a2,b1,b2;
    scanf("%lf %lf %lf %lf",&a1,&b1,&a2,&b2);
    if(a1>b1)
        swap(a1,b1);
    if(a2>b2)
        swap(a2,b2);
    if((a1<a2+eps&&b1<b2+eps)||(a2<a1+eps&&b2<b1+eps))
    {
        printf("Yes\n");
        return 0;
    }
    double ppi=2.0*acos(0);
    double l=0.0,h=ppi/2.0,theta,x,y;
    for(int i=0;i<1000;i++)
    {
        theta=(l+h)/2.0;
        x=a2*cos(theta);
        y=a2*sin(theta);
        P p1=mkv(P(x,b1+y),P(0,b1));
        P p2=mkv(P(x,b1+y),P(a1,0));
        if(fabs(dtp(p1,p2))+eps<0.0)
            l=theta;
        else
            h=theta;
    }
    cout<<theta<<endl;
    y=a2*tan(theta);

    double a=sqrt(a1*a1+b1*b1-a2*a2);
    if(a-2*y+eps>b2)
    {
        printf("Yes\n");
        return 0;
    }

    swap(a1,a2);
    swap(b1,b2);
    l=0;h=ppi/2.0;
    for(int i=0;i<1000;i++)
    {
        theta=(l+h)/2.0;
        x=a2*cos(theta);
        y=a2*sin(theta);
        P p1=mkv(P(x,b1+y),P(0,b1));
        P p2=mkv(P(x,b1+y),P(a1,0));
        if(fabs(dtp(p1,p2))+eps<0.0)
            l=theta;
        else
            h=theta;
    }
    cout<<theta<<endl;
    y=a2*tan(theta);
    a=sqrt(a1*a1+b1*b1-a2*a2);
    if(a-2*y+eps>b2)
    {
        printf("Yes\n");
        return 0;
    }

    printf("No\n");

    return 0;
}
