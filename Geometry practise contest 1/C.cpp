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
#define pf printf

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
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
 P pvt,pvt2;
 bool cmp1(P a,P b)
 {
     if(a.y==b.y)
        return (a.x<b.x)?true:false;
     else
        return(a.y<b.y)?true:false;
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
        double r=crp(mkv(pvt,pvt2),mkv(pvt,a));
        //printf("a= %lf %lf b=%lf %lf r=%lf\n",a.x,a.y,b.x,b.y,r);
         double dst1=sqrt((pvt.x-a.x)*(pvt.x-a.x)+(pvt.y-a.y)*(pvt.y-a.y));
         double dst2=sqrt((pvt.x-b.x)*(pvt.x-b.x)+(pvt.y-b.y)*(pvt.y-b.y));
         if(r<0.0)
         return(dst1>dst2)?true:false;
         else
             return(dst1<dst2)?true:false;
     }
 }
int main()
{
    int d,h,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    P ar[1005];
    double m;
    scanf("%d %lf",&n,&m);
    for(i=0;i<n;i++)
    scanf("%lf %lf",&ar[i].x,&ar[i].y);
    sort(ar,ar+n,cmp1);
    pvt=ar[0];
    pvt2=ar[n-1];
    sort(ar+1,ar+n,cmp2);;
     stack<P>stk;
    P top1,top2,running;
    stk.push(pvt);
    stk.push(ar[1]);
    ar[n]=pvt;
    for( i=2;i<=n;i++)
    {
        top1=stk.top();
        stk.pop();
        top2=stk.top();
        stk.push(top1);
        running=ar[i];
        double k=crp(mkv(top2,top1),mkv(top1,running));
    if(k<=0.0)
        {
            while(k<=0.0)
            {
                stk.pop();
                if(stk.size()==1)
                    break;
                top1=stk.top();
                stk.pop();
                top2=stk.top();
                stk.push(top1);
                k=crp(mkv(top2,top1),mkv(top1,running));
            }
            stk.push(running);
        }
        else
            stk.push(running);
    }
     l=stk.size();
    vector<P>v(l);
    r=l-1;
    P pnt,pp1,pp2;
    while(!stk.empty())
    {
        pnt=stk.top();
        v[r--]=pnt;
        stk.pop();
    }
    double ans=0.0;
    P a,b,c;
    double pi=3.141592653589793;
    for(i=0;i<v.size()-1;i++)
    {
        pp1=v[i];
        pp2=v[i+1];
        ans+=sqrt((pp1.x-pp2.x)*(pp1.x-pp2.x)+(pp1.y-pp2.y)*(pp1.y-pp2.y));
        a=v[i];
        b=v[i+1];
        if(i==0)
            c=v[v.size()-2];
        else
            c=v[i-1];
        double prdt=dtp(mkv(a,b),mkv(a,c));
        double vl=val(mkv(a,b))*val(mkv(a,c));
        if(vl==0.0)
            continue;
        double angle=acos(prdt/vl);
        angle=pi-angle;
        ans+=m*angle;

    }
//    int rans=ans;
//    double frac=0.66666666667;
//    if(((double)rans+frac)<ans)
//        rans++;
    pf("%.0lf\n",ans);


    return 0;
}
