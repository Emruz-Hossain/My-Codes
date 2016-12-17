/**************************************
 *     BISMILLAHIR RAHMANIR RAHIM     *
 *        MD: EMRUZ HOSSAIN           *
 *           CUET-CSE-12              *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ull;

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
//prm[0]='*';prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
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
struct st
{
    ll x,y;
};
st ranges[500005];

ll uniq[500005];

bool cmp(st a, st b)
{
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x<b.x;
}
int main()
{
        //freopen("output3.txt","w",stdout);
        //freopen("C-small-practice.in","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%lld",&t);
   for(x=1;x<=t;x++)
   {
//       sf("%lld %lld %lld %lld %lld %lld %lld %lld",&n,&l,&r,&a,&b,&p,&q,&m);
//       ranges[0].x=min(l,r);
//       ranges[0].y=max(l,r);
//       for(i=1;i<n;i++)
//       {
//           ranges[i].x=((a*ranges[i-1].x)%m+(b*ranges[i-1].y)%m+p)%m;
//           ranges[i].y=((a*ranges[i-1].y)%m+(b*ranges[i-1].x)%m+q)%m;
//           l=min(ranges[i].x,ranges[i].y);
//           r=max(ranges[i].x,ranges[i].y);
//           ranges[i].x=l;
//           ranges[i].y=r;
//       }
ranges[0].x=5;
ranges[0].y=9;
ranges[1].x=5;
ranges[1].y=8;
ranges[2].x=5;
ranges[2].y=7;
n=3;
       sort(ranges,ranges+n,cmp);
//       for(i=0;i<n;i++)
//       {
//           pf("---%lld %lld\n",ranges[i].x,ranges[i].y);
//       }
       mem(uniq,0);
       ll mx=0;
        for(i=0;i<n;i++)
       {
           l=ranges[i].x;
           r=ranges[i].y;
           int flag1=0,flag2=0;
           for(j=i-1;j>=0;j--)
           {
               if(ranges[j].y>=l)
               {
                   l=ranges[j].y;
                   flag1=1;
               }
               if(l>=r)
                break;
           }
           if(l>r)
            continue;
           for(j=i+1;j<n;j++)
           {
               if(ranges[j].x>=l)
               {
                   if(ranges[j].x<=r)
                   {
                       uniq[i]+=ranges[j].x-l;
                       if(flag1)
                        uniq[i]--;
                       flag1=1;
                       l=ranges[j].y;
                   }
                   else
                   {
                       uniq[i]+=r-l+1;
                       if(flag1)
                        uniq[i]--;
                       l=r+1;
                   }
                   mx=max(uniq[i],mx);
               }
               if(l>r)
                break;
           }
           if(l>r)
            continue;
         uniq[i]+=r-l+1;
         if(flag1)
            uniq[i]--;
         mx=max(uniq[i],mx);
         //pf("i= %lld uniq=%lld\n",i,uniq[i]);

       }
       //printf("mx= %lld\n",mx);
       ll total_covered=0;
       p=ranges[0].x-1;
       for(i=0;i<n;i++)
       {
          if(ranges[i].x>p)
            p=ranges[i].x-1;
          if(p<ranges[i].y)
          {
          total_covered+=ranges[i].y-p;
          p=ranges[i].y;
          }
       }
       //pf("total_covered= %lld\n",total_covered);
       pf("Case #%lld: %lld\n",x,total_covered-mx);
   }

    return 0;
}


