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
struct st
{
    int dur1,change1,dur2,change2,status;
};
vector<st>ar,br;
vector<int>v1,v2,tem1,tem2;
int Try(int mid)
{
    int d,k,idx,mx,cng,i;
    br=ar;
    tem1.clear();
    tem2.clear();
    int f1=1,f2=5;
    d=mid;
    k=1;
    while(k)
    {
        k=0;
        mx=-inf;
        idx=-1;
        for(i=0;i<(int)br.size();i++)
        {
            if(br[i].status==1&&br[i].dur2*f2>mx&&br[i].dur1*f1<=d)
            {
                mx=br[i].dur2*f2;
                idx=i;
            }
        }
        if(idx!=-1)
        {
            d-=br[idx].dur1*f1;
            f1=max(1,min(10,f1+br[idx].change1));
            tem1.push_back(idx);
            k=1;
            br[idx].status=0;
        }
    }
    f2=1;
    k=1;
    d=mid;
    while(k)
    {
        k=0;
        idx=-1;
        mx=-2;
        for(i=0;i<(int)br.size();i++)
        {
            if(br[i].status==1&&br[i].dur2*f2<=d&&mx<br[i].dur2*f2)
            {
               idx=i;
               mx=br[i].dur2*f2;
            }
        }
        if(idx!=-1)
        {
            d-=f2*br[idx].dur2;
            f2=max(1,min(10,f2+br[idx].change2));
            k=1;
            br[idx].status=0;
            tem2.push_back(idx);
        }
    }
    if((int)tem1.size()+(int)tem2.size()==(int)br.size())
       return 1;
    else
        return 0;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,optimal;
   sf("%d",&n);
   int total1=0,total2=0,f1=1,f2=1;
   st a;
   for(i=0;i<n;i++)
   {
       sf("%d %d %d %d",&a.dur1,&a.change1,&a.dur2,&a.change2);
       a.status=1;
      ar.push_back(a);
   }
   l=0;h=inf;
   while(l<h)
   {
       int mid=(l+h)/2;
       if(Try(mid))
       {
           optimal=mid;
           v1=tem1;
           v2=tem2;
           h=mid-1;
       }
       else
       {
           l=mid+1;
       }
   }
  // pf("*** %d ***\n",optimal);
   pf("%d\n",(int)v1.size());
   for(i=0;i<(int)v1.size();i++)
   {
       if(i>0)
        pf(" ");
       pf("%d",v1[i]+1);
   }
   pf("\n");
   pf("%d\n",(int)v2.size());
   for(i=0;i<(int)v2.size();i++)
   {
       if(i>0)
        pf(" ");
       pf("%d",v2[i]+1);
   }
   pf("\n");
    return 0;
}




