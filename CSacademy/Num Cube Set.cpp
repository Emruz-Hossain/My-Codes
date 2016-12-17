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
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)
#define     imax 2147483647
#define     lmax 9223372036854775807LL

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}
template <typename T> T BigMod (T b,T p,T m){if (p == 0)return 1;if (p%2 == 0){ll s = BigMod(b,p/2,m)%m;return (s*s)%m;}ll sm=((b%m)*(BigMod(b,p-1,m)%m))%m;return sm;}
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

//code of sieve
int pml=1000008,np=0;
char prm[10000009];
int prime[800000];
void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i+=2){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
prm[0]='*';prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
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
const int sz=1000005;
ll normalType[sz],inverseNormalType[sz],freqA[sz],freqB[sz],ar[sz],br[sz];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
  // sieve();
   for(i=1;i<=sz-5;i++)
   {

       normalType[i]=1;
       inverseNormalType[i]=1;
       ar[i]=i;
   }
   for(i=2;i*i<=sz-5;i++)
   {
       //factorize(i);
       if(ar[i]!=i)
        continue;
       for(j=2;j*ar[i]<=sz-5;j++)
       {
           d=j*ar[i];
           cnt=0;
           while(ar[d]%ar[i]==0)
           {
               cnt++;
               ar[d]/=ar[i];
           }
           cnt%=3;
           if(cnt>0)
           {

               if(cnt==1)
               {
                   p=ar[i];
                   q=ar[i]*ar[i];
               }
               else
               {
                   p=ar[i]*ar[i];
                   q=ar[i];
               }
               normalType[d]*=p;
               inverseNormalType[d]*=q;
           }

       }

   }
   for(i=2;i<=sz-5;i++)
   {
       if(ar[i]>1)
       {
           normalType[i]*=ar[i];
           inverseNormalType[i]*=ar[i]*ar[i];
       }
       if(inverseNormalType[i]>sz-5)
        inverseNormalType[i]=-1;
   }
    mem(freqA,0);
    mem(freqB,0);
   sf("%lld",&t);
   while(t--)
   {
       sf("%lld %lld",&n,&m);
       for(i=0;i<n;i++)
       {
           sf("%lld",&ar[i]);
           p=normalType[ar[i]];
           if(p!=-1)
            freqA[p]++;
         //  pf("%lld = %lld\n",ar[i],p);
       }
       for(i=0;i<m;i++)
       {
           sf("%lld",&br[i]);
           p=normalType[br[i]];
           if(p!=-1)
            freqB[p]++;
          // pf("%lld == %lld\n",br[i],p);
       }
       sm=-1;
       for(i=0;i<n;i++)
       {
           p=normalType[ar[i]];
           q=inverseNormalType[ar[i]];
           if(p!=-1&&q!=-1&&freqA[p]>0&&freqB[q]>0)
           {
               d=freqA[p]*freqA[p]+freqB[q]*freqB[q];
               if(d>sm)
                sm=d;
           }
       }
       pf("%lld\n",sm);

       //clean up
       for(i=0;i<n;i++)
        freqA[normalType[ar[i]]]--;
       for(i=0;i<m;i++)
        freqB[normalType[br[i]]]--;

   }



    return 0;
}
//1
//6 3
//12 18 18 45 324 96
//12 144 486
