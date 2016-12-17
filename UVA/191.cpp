//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
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
 int check_intersection(P p1,P p2,P c1,P c2)
 {
     double v1,v2,v3,v4,mx1,mx2,mn1,mn2;
     P l1=mkv(p1,p2);
     P l2=mkv(c1,c2);
     v1=crp(l1,mkv(p1,c1));
     v2=crp(l1,mkv(p1,c2));
     v3=crp(l2,mkv(c1,p1));
     v4=crp(l2,mkv(c1,p2));
     if(v1*v2<0.0&&v3*v4<0.0)
        return 1;
     else if(fabs(v1-0.0)<eps&&fabs(v2-0.0)<eps&&fabs(v3-0.0)<eps&&fabs(v4-0.0)<eps)
     {
         if(p1.x==c1.x)
         {
             mx1=max(c1.y,c2.y);
             mn1=min(c1.y,c2.y);
             mx2=max(p1.y,p2.y);
             mn2=min(p2.y,p1.y);
             if(mx1>=mn2&&mn1<=mx2)
                return 1;
             else if(mx2>=mn1&&mn2<=mx1)
                return 1;
             else
                return 0;
         }
         else if(p1.y==c1.y)
         {
             mx1=max(c1.x,c2.x);
             mn1=min(c1.x,c2.x);
             mx2=max(p1.x,p2.x);
             mn2=min(p2.x,p1.x);
             if(mx1>=mn2&&mn1<=mx2)
                return 1;
             else if(mx2>=mn1&&mn2<=mx1)
                return 1;
             else
                return 0;
         }
     }
     else
        return 0;
 }
int main()
{
     //  freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    P c1,c2,c3,c4,p1,p2;
    int r1=0,r2=0,r3=0,r4=0;
    double maxx,maxy,minx,miny,maxpx,maxpy,minpx,minpy;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y,&c4.x,&c4.y,&c2.x,&c2.y);
        c1.x=c4.x;c1.y=c2.y;
        c3.x=c2.x;c3.y=c4.y;
        r1=check_intersection(p1,p2,c1,c4);
        r2=check_intersection(p1,p2,c1,c2);
        r3=check_intersection(p1,p2,c2,c3);
        r4=check_intersection(p1,p2,c3,c4);
        maxx=max(c1.x,max(c2.x,max(c3.x,c4.x)));
        minx=min(c1.x,min(c2.x,min(c3.x,c4.x)));
        maxy=max(c1.y,max(c2.y,max(c3.y,c4.y)));
        miny=min(c1.y,min(c2.y,min(c3.y,c4.y)));
         maxpx=max(p1.x,p2.x);
         minpx=min(p1.x,p2.x);
         maxpy=max(p1.y,p2.y);
         minpy=min(p1.y,p2.y);
        if(r1||r2||r3||r4||(maxpx<=maxx&&maxpy<=maxy&&minpx>=minx&&minpy>=miny))
            printf("T\n");
        else
            printf("F\n");

    }
    return 0;
}

