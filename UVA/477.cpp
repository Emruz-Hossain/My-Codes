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
 struct st
 {
     double x1,x2,y1,y2,r;
     char ch;
 }ar[100];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int a,b,c,h,m,n,p,i,j,k,l,q,r,t,cnt,sm,tmp;
    n=0;
    double x,y,xx1,xx2,yy1,yy2,d;
    char ss[1000];
    n=0;
    while(1)
    {
        sf("%s",&ss);
        if(ss[0]=='*')
            break;
        else if(ss[0]=='r')
        {
            sf("%lf %lf %lf %lf",&xx1,&yy1,&xx2,&yy2);
            ar[n].ch='r';
            ar[n].x1=min(xx1,xx2);
            ar[n].x2=max(xx1,xx2);
            ar[n].y1=min(yy1,yy2);
            ar[n].y2=max(yy1,yy2);
            n++;
        }
        else if(ss[0]=='c')
        {
            sf("%lf %lf %lf",&ar[n].x1,&ar[n].y1,&ar[n].r);
            ar[n].ch='c';
            n++;
        }
    }
    t=1;
    while(1)
    {
        sf("%lf %lf",&x,&y);
        if(fabs(9999.9-x<eps)&&fabs( 9999.9-y)<eps)
            break;
        k=0;
        for(i=0;i<n;i++)
        {
            if(ar[i].ch=='r')
            {
            if(x>ar[i].x1&&x<ar[i].x2&&y>ar[i].y1&&y<ar[i].y2)
            {
                k=1;
                pf("Point %d is contained in figure %d\n",t,i+1);
            }
            }
            else
            {
                d=sqrt((x-ar[i].x1)*(x-ar[i].x1)+(y-ar[i].y1)*(y-ar[i].y1));
                if(d<ar[i].r)
                {
                     pf("Point %d is contained in figure %d\n",t,i+1);
                    k=1;
                }

            }
        }
        if(k==0)
            pf("Point %d is not contained in any figure\n",t);
        t++;
    }
    return 0;
}


