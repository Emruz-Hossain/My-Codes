/**************************************
 *           BISMILLAHIR RAHMANIR RAHIM             *
 *                MD: EMRUZ HOSSAIN                    *
 *                     CUET-CSE-12                          *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;

#define     mem(x,y)   memset(x,y,sizeof(x))
#define     PB(x)      push_back(x)
#define     POB()      pop_back()
#define     SZ(a)      a.size()
#define     len(a)     strlen(a)
#define     SQR(a)     (a*a)
#define     all(v)     v.begin(),v.end()
#define     fr(i,a,b)  for(i=a;i<=b;i++)
#define     rfr(i,a,b) for(i=a;i>=b;i--)
#define     sf  scanf
#define     pf  printf
#define     mkp make_pair
#define     fs  first
#define     sd  second

#define     getx() getchar()
//#define     getx() getchar_unlocked()

#define     inf  1<<25
#define     sz   20002
#define     eps  0.5
#define     mod  1000000007
#define     PI   2.0*acos(0.0)

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Swap(T &a,T &b) {T tmp=a;a=b;b=tmp;}
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}
double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
template<class T>inline bool readfast(T &x)
{
    int c=getx();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getx();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getx())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1}; //move in 8 direction
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2}; //move of knight

////code of sieve
//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i+=2){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*'prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
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
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}

 /*****************************Code start from here**************************/

 vector<P>remaining_points;
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
vector<P> creat_convex_hull(vector<P> Points)
{
    int n,i,l,r;
    remaining_points.clear();
    sort(Points.begin(),Points.end(),cmp1);
    n=Points.size();
    if(n<3)
    {
        vector<P>vv;
        for(i=Points.size()-1;i>=0;i--)
            vv.push_back(Points[i]);
         return vv;
    }

    pvt=Points[0];
    pvt2=Points[n-1];
    sort(Points.begin()+1,Points.end(),cmp2);
    stack<P>stk;
    P top1,top2,running;
    stk.push(pvt);
    stk.push(Points[1]);
    Points.push_back(pvt);
    for( i=2;i<=n;i++)
    {
        top1=stk.top();
        stk.pop();
        top2=stk.top();
        stk.push(top1);
        running=Points[i];
        double k=crp(mkv(top2,top1),mkv(top1,running));
        if(k<=0.0)
        {
            while(k<=0.0)
            {
                stk.pop();
                remaining_points.push_back(top1);
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
     l=stk.size(); // if l==2 then all the points are in same line.
    vector<P>hull(l);
    r=l-1;
    P pnt,pp1,pp2;
    while(!stk.empty())
    {
        pnt=stk.top();
        hull[r--]=pnt;
        stk.pop();
    }
    return hull;
}
long long ART(P a,P b,P c)
{
    ll x1,x2,x3,y1,y2,y3;
    x1=(ll)a.x;
    y1=(ll)a.y;
    x2=(ll)b.x;
    y2=(ll)b.y;
    x3=(ll)c.x;
    y3=(ll)c.y;
    return abs((x1-x3)*(y2-y1)-(x1-x2)*(y3-y1));
}
ll  area_of_convex_polygon(vector<P>polygon)
{
    int i;
    long long ans=0;
    for(i=1;i<polygon.size()-2;i++)
    {
        ans+=ART(polygon[0],polygon[i],polygon[i+1]);
    }

    return ans;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,tmp;
   sf("%d",&t);
   while(t--)
   {
       sf("%d",&n);
       vector<P>Points;
       P pp;
       for(i=0;i<n;i++)
       {
            sf("%lf %lf",&pp.x,&pp.y);
            Points.push_back(pp);
       }
       vector<P>outer_convex_hull=creat_convex_hull(Points);
       if(outer_convex_hull.size()==n+1)
       {
           pf("-1\n");
           continue;
       }
       vector<P>inner_convex_hull=creat_convex_hull(remaining_points);
       if(inner_convex_hull.size()>2)
       inner_convex_hull.pop_back();
       int ptr1=0,ptr2=0;
       ll area;
       ll min_area=ART(outer_convex_hull[ptr1],outer_convex_hull[ptr1+1],inner_convex_hull[ptr2]);

       for(i=0;i<inner_convex_hull.size();i++)
       {
           if(ART(outer_convex_hull[ptr1],outer_convex_hull[ptr1+1],inner_convex_hull[i])<min_area)
           {
               min_area=ART(outer_convex_hull[ptr1],outer_convex_hull[ptr1+1],inner_convex_hull[i]);
               ptr2=i;
           }
       }
       int si=inner_convex_hull.size();
       while(ptr1<outer_convex_hull.size()-1)
       {
          P P1=outer_convex_hull[ptr1];
          P P2=outer_convex_hull[ptr1+1];
          P P3=inner_convex_hull[ptr2];
          area=ART(P1,P2,P3);
          while(area>ART(P1,P2,inner_convex_hull[(ptr2+1)%si]))
          {
              area=ART(P1,P2,inner_convex_hull[(ptr2+1)%si]);
              ptr2=(ptr2+1)%si;
          }
       min_area=min(min_area,area);
       ptr1++;
       }
       ll final_area=area_of_convex_polygon(outer_convex_hull);
       final_area-=min_area;
       ll sm=final_area;
       pf("%lld\n",sm);
   }

    return 0;
}
//1
//13
//-3 0
//-2 4
//0 4
//4 3
//4 0
//3 -3
//0 -4
//-3 -3
//2 2
//2 -2
//-2 -2
//-2 2
//0 1

