
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
 P ar[100005],pvt;
 bool cmp(P a,P b)
 {
     if(a.y==b.y)
        return (a.x<b.x)?true:false;
     return (a.y<b.y)?true:false;
 }
 bool cmp2(P b,P a)
 {
     double d1,d2;
     double r=crp(mkv(pvt,a),mkv(pvt,b));
    // printf("a=%lf  %lf b=%lf %lf r=%lf\n",a.x,a.y,b.x,b.y,r);
     if(r<0.0)
        return true;
     if(r>0.0)
        return false;
     else
     {
         d1=sqrt((pvt.x-a.x)*(pvt.x-a.x)+(pvt.y-a.y)*(pvt.y-a.y));
         d2=sqrt((pvt.x-b.x)*(pvt.x-b.x)+(pvt.y-b.y)*(pvt.y-b.y));
         return (d1>d2)?true:false;
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,p,x,y,i,j,l,q,r,t,cnt,sm,tmp;
    x=0;
    while(1)
    {
        ++x;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
             scanf("%lf %lf",&ar[i].x,&ar[i].y);
        }
        sort(ar,ar+n,cmp);
        pvt=ar[0];
        sort(ar+1,ar+n,cmp2);
//        for(i=0;i<n;i++)
//              printf("%lf %lf\n",ar[i].x,ar[i].y);
        ar[n]=pvt;
       // printf("%lf\n",ART(mkv(ar[0],ar[1]),mkv(ar[0],ar[2])));
        P top1,top2,running;
        stack<P>stk;
        stk.push(ar[0]);
        stk.push(ar[1]);
        for(i=2;i<=n;i++)
        {
            top1=stk.top();
            stk.pop();
            top2=stk.top();
            stk.push(top1);
            running=ar[i];
            double k=crp(mkv(top2,top1),mkv(top1,running));
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
        l=stk.size();
        vector<P>v(l);
        for(i=0;i<l;i++)
        {
            v[i]=stk.top();
            stk.pop();
        }
        double prm=0.0;
        for(i=0;i<l-1;i++)
        {
            prm+=sqrt((v[i].x-v[i+1].x)*(v[i].x-v[i+1].x)+(v[i].y-v[i+1].y)*(v[i].y-v[i+1].y));
        }
        if(x>1)
            printf("\n");
        printf("Region #%d:\n",x);
        for(i=0;i<l;i++)
        {
            if(i>0)
                printf("-");
            printf("(%.1lf,%.1lf)",v[i].x,v[i].y);
        }
        printf("\nPerimeter length = %.2lf\n",prm);
    }

    return 0;
}
