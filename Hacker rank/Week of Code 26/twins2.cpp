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
template<typename T>
T MultiplyMod(T a, T b, T mod) { //computes a * b % mod
    T r = 0;
    a %= mod, b %= mod;
    while (b) {
        if (b & 1) r = (r + a) % mod;
        b >>= 1, a = ( a << 1) % mod;
    }
    return r;
}
template<typename T>
T PowerMod(T a, T n, T mod) {  //computes a^n % mod
    T r = 1;
    while (n) {
        if (n & 1) r = MultiplyMod(r, a, mod);
        n >>= 1, a = MultiplyMod(a, a, mod);
    }
    return r;
}
template<typename T>
bool isprime(T n) { //determines if n is a prime number
    const int pn = 9, p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for (int i = 0; i < pn; ++i)
        if (n % p[i] == 0) return n == p[i];
    if (n < p[pn - 1]) return 0;
    T s = 0, t = n - 1;
    while (~t & 1)
        t >>= 1, ++s;
    for (int i = 0; i < pn; ++i) {
        T pt = PowerMod<T> (p[i], t, n);
        if (pt == 1) continue;
        bool ok = 0;
        for (int j = 0; j < s && !ok; ++j) {
            if (pt == n - 1) ok = 1;
            pt = MultiplyMod(pt, pt, n);
        }
        if (!ok) return 0;
    }
    return 1;
}
int check_prime(int p)
{
    for(int i=2;i*i<=p;i++)
    {
        if(p%i==0)
            return 0;
    }
    return 1;
}
int main()
{
      // freopen("output2.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%d %d",&n,&m);
   cnt=0;
   for(i=max(3,n);i<=m-2;)
   {
       if(check_prime(i))
       {
           if(check_prime(i+2))
           {
               //pf("%d %d\n",i,i+1);
                cnt++;
               i+=2;
           }
           else
            i+=2;
       }
       else
        i++;
   }
   pf("%d\n",cnt);

    return 0;
}

//999000000 1000000000
