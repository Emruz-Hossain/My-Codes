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
typedef long long ll;
#define     mem(x,y) memset(x,y,sizeof(x))
#define     PB(x) push_back(x)
#define     POB() pop_back()
#define     SZ(a) a.size()
#define     len(a) strlen(a)
#define     sf scanf
#define     pf printf

#define     inf 1<<25
#define     sz 2000
#define     eps 1e-9
#define     mod  1000000007
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
 P ar[55],pvt;
 bool cmp1(P a,P b)
{
    if(a.y==b.y)
        return(a.x<b.x)?true:false;
    else
        return (a.y<b.y)?true:false;
}
bool cmp(P b, P a)
{
    pvt.x=-10005.00;
    pvt.y=-10005.00;
    double c=crp(mkv(pvt,a),mkv(pvt,b));
   // printf("%lf %lf %lf %lf c=%lf\n",a.x,a.y,b.x,b.y,c);
    if(c>0.0)
        return false;
    else if(c<0.0)
        return true;
    else
    {
        double dst1=sqrt((pvt.x-a.x)*(pvt.x-a.x)+(pvt.y-a.y)*(pvt.y-a.y));
         double dst2=sqrt((pvt.x-b.x)*(pvt.x-b.x)+(pvt.y-b.y)*(pvt.y-b.y));
//         printf("------------------------------------------------------\n%lf %lf %lf %lf\n",a.x,a.y,b.x,b.y);
//         printf("%lf %lf\n----------------------------------------------\n",dst1,dst2);
         return (dst1>dst2)?strue:false;
    }
}
double dis(P a, P b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    double s1,s2,s3,s4,d1,d2;
    sf("%d",&t);
    for(a=1;a<=t;a++)
    {
        for(i=0;i<4;i++)
            sf("%lf %lf",&ar[i].x,&ar[i].y);
        sort(ar,ar+4,cmp1);
        sort(ar,ar+4,cmp);
        s1=dis(ar[0],ar[2]);
        s2=dis(ar[1],ar[3]);
        s3=dis(ar[2],ar[3]);
        s4=dis(ar[1],ar[0]);
        d1=dis(ar[1],ar[2]);
        d2=dis(ar[0],ar[3]);
        k=0;
       // pf("%lf %lf %lf %lf %lf %lf\n",s1,s2,s3,s4,d1,d2);
        pf("Case %d: ",a);
        if(k==0)
        {
            if(s1==s2&&s1==s3&&s1==s4&&d1==d2)
            {
                pf("Square\n");
                k=1;
            }
        }
        if(k==0)
        {
            if(s1==s2&&s1==s3&&s1==s4&&d1!=d2)
            {
                pf("Rhombus\n");
                k=1;
            }
        }
        if(k==0)
        {
            if(s1==s2&&s3==s4&&d1==d2)
            {
                pf("Rectangle\n");
                k=1;
            }
        }
        if(k==0)
        {
            if(s1==s2&&s3==s4&&d1!=d2)
            {
                pf("Parallelogram\n");
                k=1;
            }
        }
        if(k==0)
        {
            slp1=slop(ar[],ar[2])
            slp2=
            slp3=
            slp4=
            if()
               {
                   k=1;
                   pf("Trapezium\n");
               }
        }
        if(k==0)
            pf("Ordinary Quadrilateral\n");
    }
    return 0;
}

