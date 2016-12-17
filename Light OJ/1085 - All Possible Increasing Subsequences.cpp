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
//prm[0]='*'prm[1]='*;/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
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
 const int mod= 1000000007;
vector<int>v;
map<int,int>mp;
int ar[100005],tree[4*100005];
void build(int rt,int beg,int endd)
{
    tree[rt]=0;
    if(beg==endd)
    {
        tree[rt]=0;
        return;
    }
   int mid=(beg+endd)/2;
    build(2*rt,beg,mid);
    build(2*rt+1,mid+1,endd);
}
int query(int rt,int beg,int endd,int l,int r)
{
    if(beg>r||endd<l)
      return 0;
    if(beg>=l&&endd<=r)
        return tree[rt];
    int mid=(beg+endd)/2;
    return (query(2*rt,beg,mid,l,r)+query(2*rt+1,mid+1,endd,l,r))%mod;

}
void update(int rt,int beg,int endd,int idx,int val)
{
    if(beg==endd&&beg==idx)
    {
        tree[rt]=(tree[rt]+val)%mod;
        return;
    }
    if(beg>endd)
        return;
    int mid=(beg+endd)/2;
    if(idx<=mid)
        update(2*rt,beg,mid,idx,val);
    else
        update(2*rt+1,mid+1,endd,idx,val);
    tree[rt]=(tree[2*rt]+tree[2*rt+1])%mod;
}
int FIND(int val,int l,int h)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(v[mid]==val)
            return mid;
        else if(v[mid]<val)
            l=mid+1;
        else
            h=mid-1;
    }
    return mid;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   readfast(t);
   for(x=1;x<=t;x++)
   {
       v.clear();
       mp.clear();
       //mem(tree,0);
       //mem(ar,0);
       readfast(n);
       for(i=0;i<n;i++)
       {
           readfast(p);
          if(mp[p]!=1)
          {
              mp[p]=1;
              v.push_back(p);
          }
           ar[i+1]=p;
       }
       sort(v.begin(),v.end());
       for(i=1;i<=n;i++)
       {
          ar[i]=FIND(ar[i],0,v.size()-1)+1;
       }
       build(1,1,n);

       for(i=1;i<=n;i++)
       {
           p=query(1,1,n,1,ar[i]-1);
           update(1,1,n,ar[i],(p+1)%mod);
       }
       pf("Case %d: %d\n",x,query(1,1,n,1,n)%mod);
   }

    return 0;
}

