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
double inf=9999999999.00;
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}
P ar[100005];
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    P point,ans;
    double mind,vl,dst;
    while(scanf("%lf",&point.x)==1)
    {
        scanf("%lf %d",&point.y,&n);
        for(i=0;i<=n;i++)
            scanf("%lf %lf",&ar[i].x,&ar[i].y);
        mind=inf;
        for(i=0;i<n;i++)
        {
            P AB=mkv(ar[i],ar[i+1]);
            P AM=mkv(ar[i],point);
            vl=dtp(AB,AM);
            if(vl<=0.0+eps)
            {
               dst=sqrt((point.x-ar[i].x)*(point.x-ar[i].x)+(point.y-ar[i].y)*(point.y-ar[i].y));
               if(dst<mind)
               {
                   mind=dst;
                   ans.x=ar[i].x;
                   ans.y=ar[i].y;
               }
               continue;
            }
            P BA=mkv(ar[i+1],ar[i]);
            P BM=mkv(ar[i+1],point);
            vl=dtp(BA,BM);
            if(vl<0.0+eps)
            {
               dst=sqrt((point.x-ar[i+1].x)*(point.x-ar[i+1].x)+(point.y-ar[i+1].y)*(point.y-ar[i+1].y));
               if(dst<mind)
               {
                   mind=dst;
                   ans.x=ar[i+1].x;
                   ans.y=ar[i+1].y;
               }
               continue;
            }
            double l=dtp(AM,AB)/val(AB);
            P AL=vresize(AB,l);
            dst=fabs(crp(AM,AL)/val(AL));
            if(dst<mind)
            {
                mind=dst;
                P tm;
                P AV=mkv(tm,ar[i]);
                P LV=mkv(tm,AL);
                ans.x=AV.x+LV.x;
                ans.y=AV.y+LV.y;
            }

        }
        printf("%.4lf\n%.4lf\n",ans.x,ans.y);
    }
    return 0;
}

