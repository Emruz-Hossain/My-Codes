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
//prm[0]='*'prm[1]='*;/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}

/**************************************************Code start from here**************************/
int next[100];
void Failure(string P)
{
    int q=0 , k , m = P.size();
    next[0] = 0;                      // ১ টি ক্যারেক্টার এর জন্য সঠিক উপসর্গ বা সঠিক প্রত্যয় থাকেনা
    for(int i=1;i<m;i++)
    {
        while(q > 0 && P[i]!=P[q])   // ক্যারেক্টার ম্যাচ না করলে P কে (q – k) ধর ডানে শিফট করতে থাকব
        {
            k  =  next[q-1];
            q  =  k;
        }
        if(P[q]==P[i]) q++;            // ক্যারেক্টার ম্যাচ করলে q এর মান 1 বাড়াব।
        next[i] = q;                    // next অ্যারেতে P এর ক্যারেক্টারগুলোর পুনরাবৃত্তির সংখ্যা সেভ করব
    }
}

int Matcher(string T, string P)
{
    int q = 0 , k , n  = T.size() , m  = P.size();
    Failure(P);                  // ফেইলিওর-ফাংশন দিয়ে next অ্যারে জেনারেট করে নিচ্ছি
    for(int i=0;i<n;i++)
    {
        while(q>0 && T[i]!=P[q])    // ক্যারেক্টার ম্যাচ না করলে P কে (q – k) ধর ডানে শিফট করতে থাকব
        {
            k  =  next[q-1];
            q  =  k;
        }
        if(P[q]==T[i])  q++;           // ক্যারেক্টার ম্যাচ করলে q এর মান 1 বাড়াব।
        if(q==m)                      // সম্পূর্ণ প্যাটার্ন ম্যাচ হয়ে গেলে
        {
            k  =  next[q];
            q  =  k;
            return (i-m+1);            // আমরা P কে সম্পূর্ণভাবে T এর সাবস্ট্রিং হিসেবে খুঁজে পেলে T এর যে ইন্ডেক্স থেকে P শুরু হয়েছে তা রিটার্ন করব
        }
    }
    return -1;                      // সমগ্র T তে P কে একবারও খুঁজে না পাওয়া গেলে নির্দেশনা স্বরূপ -1 রিটার্ন করব
}
int main()
{
    string T = "bacbabababacaab", P = "ababaca";
    int ans = Matcher(T,P);
    if(ans==-1)
       puts("Pattern Not Found");
    else
     pf("Pattern Found At Index %d\n",ans);
}




