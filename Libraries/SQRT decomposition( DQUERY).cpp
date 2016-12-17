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
     int L,R,id,ans,block;
 }Q[300005];
int ar[300005],visit[1000006],ans;

bool cmp1(st a,st b)
{
    if(a.block==b.block)
        return a.R<b.R;
    return a.block<b.block;
}
bool cmp2(st a,st b)
{
    return a.id<b.id;
}
void Add(int pos)
{
    if(visit[ar[pos]]==0)
        ans++;
    visit[ar[pos]]++;
}
void Remove(int pos)
{
    visit[ar[pos]]--;
    if(visit[ar[pos]]==0)
        ans--;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    sf("%d",&n);
    mem(visit,0);
    for(i=1;i<=n;i++)
    {
        sf("%d",&ar[i]);
        if(visit[ar[i]]==0)
            ans++;
        visit[ar[i]]++;
    }
    sf("%d",&q);
    d=sqrt(n);
    if(d*d<n)
        d++;
    for(i=0;i<q;i++)
    {
        sf("%d %d",&a,&b);
        Q[i].id=i;
        Q[i].L=a;
        Q[i].R=b;
        p=a/d;
        if(p*d<a)
            p++;
        Q[i].block=p;
    }
    sort(Q,Q+q,cmp1);
    int CL=1,CR=n,L,R;
    for(i=0;i<q;i++)
    {
        L=Q[i].L;
        R=Q[i].R;
        if(CL<L)
        {
            while(CL<L)
            {
                Remove(CL);
                CL++;
            }
        }
        else if(CL>L)
        {
            CL--;
            while(CL>L)
            {
                Add(CL);
                CL--;
            }
            Add(CL);
        }
        if(CR<R)
        {
            CR++;
            while(CR<R)
            {
                Add(CR);
                CR++;
            }
            Add(CR);
        }
        else if(CR>R)
        {
            while(CR>R)
            {
                Remove(CR);
                CR--;
            }
        }
        Q[i].ans=ans;

    }
    sort(Q,Q+q,cmp2);
    for(i=0;i<q;i++)
    {
       pf("%d\n",Q[i].ans);
    }
    return 0;
}

