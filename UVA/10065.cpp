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
 int n;
 P ar[105],br[105],pvt;
 double find_area(int lm)
 {
      P strt;
      int i;
      double sm=0.0;
     for(i=0;i<lm;i++)
     {
         sm+=ART(mkv(strt,br[i]),mkv(strt,br[i+1]));
     }
     return fabs(sm);
 }
 bool cmp1(P a,P b)
 {
     if(a.y==b.y)
        return(a.x<b.x)?true:false;
    else
        return (a.y<b.y)?true:false;
 }
 bool cmp2(P b,P a)
 {
     double k=crp(mkv(pvt,a),mkv(pvt,b));
     if(k<0.0)
        return true;
     else if(k>0.0)
        return false;
     else
     {
         double dst1=sqrt((pvt.x-a.x)*(pvt.x-a.x)+(pvt.y-a.y)*(pvt.y-a.y));
         double dst2=sqrt((pvt.x-b.x)*(pvt.x-b.x)+(pvt.y-b.y)*(pvt.y-b.y));
         return(dst1>dst2)?true:false;
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int d,h,m,p,x,y,i,j,l,q,r,t,cnt,sm,tmp;
    x=0;
    while(1)
    {
        ++x;
        double area_t,area_h,loss;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&ar[i].x,&ar[i].y);
           br[i]=ar[i];
        }
        br[n]=br[0];
        area_t=find_area(n);
        sort(ar,ar+n,cmp1);
        pvt=ar[0];
        sort(ar+1,ar+n,cmp2);
        ar[n]=pvt;
        stack<P>stk;
        double k;
        P top,stop,running;
        stk.push(ar[0]);
        stk.push(ar[1]);
        for(i=2;i<=n;i++)
        {
            running=ar[i];
            top=stk.top();
            stk.pop();
            stop=stk.top();
            stk.push(top);
            k=crp(mkv(stop,top),mkv(top,running));
            while(k<0.0)
            {
                stk.pop();
                if(stk.size()==1)
                    break;
                top=stk.top();
                stk.pop();
                stop=stk.top();
                stk.push(top);
                 k=crp(mkv(stop,top),mkv(top,running));
            }
            stk.push(running);
        }
        l=stk.size();
        for(i=l-1;i>=0;i--)
        {
            br[i]=stk.top();
            stk.pop();
        }
        area_h=find_area(l-1);
        loss=((area_h-area_t)/area_h)*100.0;
        printf("Tile #%d\nWasted Space = %.2lf %%\n\n",x,loss);
    }

    return 0;
}

