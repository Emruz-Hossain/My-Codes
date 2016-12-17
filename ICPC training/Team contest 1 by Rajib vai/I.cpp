/***************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                *
 *                      MD: EMRUZ HOSSAIN                      *
 *                         CUET-CSE-12                         *
 ***************************************************************/
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
#define     read(n)       scanf("%d",&n)
#define     read2(m,n)    scanf("%d %d",&m,&n)
#define     read3(m,n,p)  scanf("%d %d %d",&m,&n,&p)
#define     readl(n)      scanf("%I64d",&n);
#define     readl2(m,n)   scanf("%I64d %I64d",&m,&n)
#define     readl3(m,n,p) scanf("%I64d %I64d %I64d",&m,&n,&p)

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

 /**************************************************Code start from here**************************/
struct pt
{
    int s,e,v;
}ar[1005];
int dp1[12005],dp2[1005][130],n,k,t,l;
bool cmp(pt a, pt b)
{
    if(a.s==b.s)
        return a.e<b.e;
    return a.s<b.s;
}
int nearest(int time)
{
    int l=0,h=n-1,mid,ans=-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(ar[mid].s>=time)
        {
            ans=mid;
            if(mid==0)
                return ans;
            if(ar[mid-1].s<time)
                return ans;
            h=mid-1;
        }
        else
        {
            if(mid==n-1)
                return ans;
            if(ar[mid+1].s>=time)
                return mid+1;
            l=mid+1;
        }
    }
    return ans;
}
int rec(int idx,int rem)
{
    int d,nid,p;
    if(idx>=n||rem<=0)
        return 0;
    int &ret=dp2[idx][rem];
    if(ret!=-inf)
        return ret;
    int sm=-inf;
    d=ar[idx].e-ar[idx].s;
    if(d<=rem)
    {
        sm=max(sm,ar[idx].v);
        nid=nearest(ar[idx].e);
        if(nid!=-1)
        {
             p=rem-d;
             p=p-(ar[nid].s-ar[idx].e);
             sm=max(sm,rec(nid,p)+ar[idx].v);
        }
    }
    sm=max(sm,rec(idx+1,rem-(ar[idx+1].s-ar[idx].s)));
    return ret=sm;

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,p,x,y,i,j,q,r,cnt,sm,tmp,nid,dt;
   sf("%d",&x);
   while(x--)
   {
       sf("%d %d %d %d",&n,&t,&k,&l);
       for(i=0;i<n;i++)
       {
            sf("%d %d %d",&ar[i].s,&ar[i].e,&ar[i].v);
       }
       sort(ar,ar+n,cmp);
       for(i=0;i<=12000;i++)
        dp1[i]=-inf;
        for(i=0;i<=1000;i++)
            for(j=0;j<=120;j++)
               dp2[i][j]=-inf;
       dp1[0]=0;
       ar[n].s=ar[n-1].e+130;
       for(i=0;i<=11000;i++)
       {
           if(dp1[i]!=-inf)
           {
               nid=nearest(i);
               if(nid==-1)
                continue;
               for(dt=0;dt<=l;dt++)
               {
                   p=rec(nid,t+dt-(ar[nid].s-i));
                   dp1[i+t+dt+k+dt]=max(dp1[i+t+dt+k+dt],dp1[i]+p-dt*dt);
               }
           }
       }
       sm=0;
       for(i=0;i<=12000;i++)
        sm=max(sm,dp1[i]);
       pf("%d\n",sm);

   }
    return 0;
}
//1
//3 16 8 4
//26 30 10
//29 31 28
//30 43 21


