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

int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    P p1,p2,p3,p4,mx1,mx2,mn1,mn2;
    double k1,k2,m1,m2,v1,v2,v3,v4,xx,yy,slp1,slp2,r1,r2,r3;
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
        k1=p1.x-p2.x;
        k2=p3.x-p4.x;
        m1=p1.y-p2.y;
        m2=p3.y-p4.y;
        slp1=3.0;slp2=5.0;
        if(k1!=0.0)
            slp1=m1/k1;
        if(k2!=0.0)
            slp2=m2/k2;
        if(fabs(slp1-slp2)<eps||(k1==0.0&&k2==0.0)||(m1==0.0&&m2==0.0))
        {
                r1=(m1*p4.x-k1*p4.y+(k1*p1.y-m1*p1.x));;
            if((fabs(slp1-slp2)<eps&&fabs(r1-0.0)<eps)||(k1==0.0&&k2==0.0&&p1.x==p3.x)||(m1==0.00&&m2==0.0&&p1.y==p3.y))
                printf("LINE\n");
            else
                printf("NONE\n");
        }
        else
        {
            if(k1==0.0)
                xx=p1.x;
            if(k2==0.0)
                xx=p3.x;
            if(m1==0.0)
                yy=p1.y;
            if(m2==0.0)
                yy=p3.y;
            if(m2*k1-m1*k2!=0.0)
            {
                yy=(p1.y*k1*m2-m1*p1.x*m2+m1*m2*p3.x-m1*k2*p3.y)/(m2*k1-m1*k2);
            }
            if(m1!=0)
                xx=(yy*k1-p1.y*k1+m1*p1.x)/m1;
            printf("POINT %.2lf %.2lf\n",xx,yy);
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}

