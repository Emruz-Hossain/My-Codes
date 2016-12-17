/**************************************
 *    BISMILLAHIR RAHMANIR RAHIM      *
 *        MD: EMRUZ HOSSAIN           *
 *           CUET-CSE-12              *
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
#define     eps  1e-9
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
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}

 /*****************************Code start from here**************************/

 /*****************************Convex Hull**********************************/
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
    sort(Points.begin(),Points.end(),cmp1);
    n=Points.size();
    if(n<3)
        return Points;
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
    hull.pop_back();
    return hull;
}

/**************************Area of convex polygon***************************/
double area_of_convex_polygon(vector<P>polygon)
{
    int i;
    double ans=0;
    for(i=1;i<polygon.size()-1;i++)
        ans+=ART(mkv(polygon[0],polygon[i]),mkv(polygon[0],polygon[i+1]));
    return fabs(ans);
}

/************************Intersection point of two lines*****************/
int isParallel;
P Intersection_of(P A, P B, P C , P D)
{
    double a1,b1,c1,a2,b2,c2;
    P ip;

    a1=B.y-A.y;
    b1=A.x-B.x;
    c1=a1*A.x+b1*A.y;

    a2=D.y-C.y;
    b2=C.x-D.x;
    c2=a2*C.x+b2*C.y;
    double det=a1*b2-a2*b1;
    if(det==0)
    {
        isParallel=1;
        return ip;
    }
    ip.x=(b2*c1-b1*c2)/det;
    ip.y=(a1*c2-a2*c1)/det;
    return ip;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   vector<P>inner_Points,outer_points;
   P A;
   for(i=0;i<5;i++)
   {
       sf("%lf %lf",&A.x,&A.y);
       inner_Points.push_back(A);
   }
   vector<P>inner_hull=creat_convex_hull(inner_Points);
   if(inner_hull.size()<5)
   {
       pf("No\n");

   }
   else
   {
//       for(i=0;i<5;i++)
//       {
//           pf("%lf %lf\n",inner_hull[i].x,inner_hull[i].y);
//       }
       P ip;
       isParallel=0;
       ip=Intersection_of(inner_hull[0],inner_hull[1],inner_hull[2],inner_hull[3]);
       if(isParallel)
       {
           pf("No\n");
       }
       else
       {
           outer_points.push_back(ip);
           ip=Intersection_of(inner_hull[1],inner_hull[2],inner_hull[3],inner_hull[4]);
           if(isParallel)
           {
               pf("No\n");
           }
           else
           {
               outer_points.push_back(ip);
               ip=Intersection_of(inner_hull[2],inner_hull[3],inner_hull[4],inner_hull[0]);
               if(isParallel)
               {
                   pf("No\n");
               }
               else
               {
                   outer_points.push_back(ip);
                   ip=Intersection_of(inner_hull[3],inner_hull[4],inner_hull[0],inner_hull[1]);
                   if(isParallel)
                   {
                       pf("No\n");
                   }
                   else
                   {
                       outer_points.push_back(ip);
                       ip=Intersection_of(inner_hull[4],inner_hull[0],inner_hull[1],inner_hull[2]);
                       if(isParallel)
                       {
                           pf("No\n");
                       }
                       else
                       {
                           outer_points.push_back(ip);
                           vector<P>outer_hull=creat_convex_hull(outer_points);
                           if(outer_hull.size()<5)
                            pf("No\n");
                           else
                            pf("Yes\n");

                       }

                   }

               }
           }
       }
   }

    return 0;
}
//0 0
//6 0
//5 5
//3 6
//0 5
