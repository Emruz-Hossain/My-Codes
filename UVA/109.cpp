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
 P pvt,ar[200];
 vector<P>E[100];
 double area[100];
 int n;
 bool cmp(P a,P b)
 {
     if(a.y==b.y)
        return (a.x<b.x)?true:false;
     else
        return (a.y<b.y)?true:false;
 }
 bool cmp2(P b, P a)
 {
     double r=crp(mkv(pvt,a),mkv(pvt,b));
     if(r<0.0)
        return true;
     else if(r>0.0)
        return false;
     else
     {
         double dst1=sqrt((pvt.x-a.x)*(pvt.x-a.x)-(pvt.y-a.y)*(pvt.y-a.y));
         double dst2=sqrt((pvt.x-b.x)*(pvt.x-b.x)-(pvt.y-b.y)*(pvt.y-b.y));
         if(dst1>dst2)
            return true;
        else
            return false;
     }
 }
vector<P> build_hull()
 {
    stack<P>stk;
    P top1,top2,running;
    int i;
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
    if(k<0.0)
        {
            while(k<0.0)
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
    int l=stk.size();
    vector<P>v(l);
    int r=l-1;
    while(!stk.empty())
    {
        v[r--]=stk.top();
        stk.pop();
    }
    return v;
 }
 double Find_area(vector<P>vv)
 {
    double ara=0.0;
    int i;
    for(i=1;i<vv.size()-1;i++)
    {
        ara+=ART(mkv(vv[0],vv[i]),mkv(vv[0],vv[i+1]));
    }
    return ara;
 }
 int check(vector<P>v,P p)
 {
     int i;
     double c;
     for(i=0;i<v.size()-1;i++)
     {
         c=crp(mkv(v[i],v[i+1]),mkv(v[i],p));
         if(c<0.0)
            return 0;
     }
     return 1;
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int b,c,d,h,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    d=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&ar[i].x,&ar[i].y);
        }
        sort(ar,ar+n,cmp);
        pvt=ar[0];
        sort(ar+1,ar+n,cmp2);
//        for(i=0;i<n;i++)
//            printf("%lf %lf\n",ar[i].x,ar[i].y);
        E[d]=build_hull();
       // printf("__________________________\n");
//        for(i=0;i<E[d].size();i++)
//            printf("%lf %lf\n",E[d][i]);
        area[d]=Find_area(E[d]);
//        printf("area=%lf\n",area[d]);
//        printf("______________________________\n");
        d++;
    }
    P point;
    double tarea=0.0;
    int visit[100];
    memset(visit,0,sizeof(visit));
    while(scanf("%lf %lf",&point.x,&point.y)==2)
    {
        for(i=0;i<d;i++)
        {
            if(visit[i]==0)
            {
                p=check(E[i],point);
                if(p==1)
                {
                    visit[i]=1;
                    tarea+=area[i];
                }
            }
        }
    }
    printf("%.2lf\n",tarea);

    return 0;
}
