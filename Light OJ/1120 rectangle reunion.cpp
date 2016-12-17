
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
//#include<bits/stdc++.h>
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
#define     sz 30005
#define     eps 1e-9
#define     mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}

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
 struct point
 {
     ll x,ymin,ymax,is_start;
     point(ll x,ll ym,ll yx,ll ist)
     {
         this ->x=x;
         ymin=ym;
         ymax=yx;
         is_start=ist;
     }
     bool operator < (const point &p)const
     {
         return x<p.x;
     }
 };
 ll tree[sz*10],rectangle_start[sz*10];
 vector<point>Points;
 vector<ll>height;
 void update(ll rt, ll l ,ll r, ll ymin,ll ymax,ll is_start)
 {
    if(height[l]>ymax||height[r]<ymin)
        return;
    if(height[l]>=ymin&&height[r]<=ymax)
    {
        rectangle_start[rt]+=is_start;
        if(rectangle_start[rt])
            tree[rt]=height[r]-height[l];
        else
            tree[rt]=tree[2*rt]+tree[2*rt+1];// if rectangle end then height[r]-height[l] may not be the height of the rectangle we are working. In this case height is calculated during its start.
       return;
    }
    ll mid=(l+r)/2;
    if(l+1==r) // as we are updating mid to right then it will not stop calling without this condition.
        return;
    update(2*rt,l,mid,ymin,ymax,is_start);
    update(2*rt+1,mid,r,ymin,ymax,is_start);
    if(rectangle_start[rt])
        tree[rt]=height[r]-height[l]; //if a rectangles height of this range started before but not yet closed then height must remain height[r]-height[l].
    else
    tree[rt]=tree[2*rt]+tree[2*rt+1];
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,x1,x2,y1,y2;
   sf("%lld",&t);
   for(x=1;x<=t;x++)
   {
       Points.clear();
       height.clear();
       sf("%lld",&n);
       height.push_back(-1);
       for(i=0;i<n;i++)
       {
           sf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
           Points.push_back(point(x1,y1,y2,1));
           Points.push_back(point(x2,y1,y2,-1));
           height.push_back(y1);
           height.push_back(y2);
       }
       sort(Points.begin(),Points.end());
       sort(height.begin(),height.end());
       m=height.size();
       cnt=0;
       for(i=1;i<m;i++)
       {
           if(height[i]!=height[i-1])
            height[++cnt]=height[i];
       }
       m=cnt;
       mem(tree,0);
       update(1,1,m,Points[0].ymin,Points[0].ymax,Points[0].is_start);
       ll area=0;
       n=Points.size();
       for(i=1;i<n;i++)
       {
           area+=tree[1]*(Points[i].x-Points[i-1].x);
           update(1,1,m,Points[i].ymin,Points[i].ymax,Points[i].is_start);
       }
       pf("Case %lld: %lld\n",x,area);
   }

    return 0;
}
