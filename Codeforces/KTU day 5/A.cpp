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
struct st
{

    ll v,sum[105];
}tree[4*10004];
ll ar[10005];
ll m;
void build(ll rt,ll beg,ll endd)
{
    if(beg==endd)
    {
        tree[rt].v=ar[beg];
        for(ll i=0;i<=(ll)100;i++)
        {
            tree[rt].sum[i]=0;
        }
        tree[rt].sum[tree[rt].v%m]=tree[rt].v;
        return;
    }
    ll mid=(beg+endd)/2;
    build(2*rt,beg,mid);
    build(2*rt+1,mid+1,endd);
    for(ll i=0;i<=(ll)100;i++)
    {
        tree[rt].sum[i]=tree[2*rt].sum[i]+tree[2*rt+1].sum[i];
    }
}
ll update(ll rt,ll beg,ll endd,ll pos,ll val)
{
    if( beg>pos||endd<pos)
        return (ll)0;
    if(beg==endd&&beg==pos)
    {
        ll k=tree[rt].v;
        if(val<(ll)0)
        {
            if(k<abs(val))
            {
                return k;
            }
        }
        tree[rt].v+=val;
       for(ll i=0;i<=(ll)100;i++)
          tree[rt].sum[i]=0;
        tree[rt].sum[tree[rt].v%m]=tree[rt].v;
        return tree[rt].v;
    }
    ll mid=(beg+endd)/2;
    ll d;
    if(pos<=mid)
        d=update(2*rt,beg,mid,pos,val);
    else
       d=update(2*rt+1,mid+1,endd,pos,val);
    for(ll i=0;i<=(ll)100;i++)
    {
        tree[rt].sum[i]=tree[2*rt].sum[i]+tree[2*rt+1].sum[i];
    }
    return d;
}
ll query(ll rt, ll beg, ll endd,ll l,ll r,ll v)
{
    if(beg>r||endd<l)
        return (ll)0;
    if(beg>=l&&endd<=r)
    {
        return tree[rt].sum[v];
    }
    ll mid=(beg+endd)/2;
    return query(2*rt,beg,mid,l,r,v)+query(2*rt+1,mid+1,endd,l,r,v);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   readl2(n,m);
   char ss[20];
   for(i=1;i<=n;i++)
    readl(ar[i]);
   build(1,1,n);
   readl(q);
   while(q--)
   {
       sf("%s",&ss);
       if(ss[0]=='+')
       {
           readl2(a,b);
           sm=update(1,1,n,a,b);
           pf("%I64d\n",sm);
       }
       else if(ss[0]=='-')
       {
           readl2(a,b);
           sm=update(1,1,n,a,-1*b);
           pf("%I64d\n",sm);
       }
       else if(ss[0]=='s')
       {
           sf("%I64d %I64d %I64d",&a,&b,&c);
           pf("%I64d\n",query(1,1,n,a,b,c));
       }
   }

    return 0;
}




