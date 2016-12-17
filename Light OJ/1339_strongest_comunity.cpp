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
#define     readl(n)      scanf("%lld",&n);
#define     readl2(m,n)   scanf("%lld %lld",&m,&n)
#define     readl3(m,n,p) scanf("%lld %lld %lld",&m,&n,&p)

//#define     getx() getchar()
#define     getx() getchar_unlocked()

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

 /**************************************************Code start from here**************************/
struct st
{
    int cnt,l,r;
}ar[100005];
int br[100004];
int tree[3*100004];
void update(int rt,int beg,int endd,int indx,int val)
{
    if(beg==endd)
    {
        tree[rt]=ar[val].cnt;
        return;
    }
    int mid=(beg+endd)/2;
    if(indx<=mid)
        update(2*rt,beg,mid,indx,val);
    else
        update(2*rt+1,mid+1,endd,indx,val);
    tree[rt]=max(tree[2*rt],tree[2*rt+1]);
}
int query(int rt,int beg,int endd,int l,int r)
{
    if(beg>r||endd<l)
        return 0;
    if(beg>=l&&endd<=r)
        return tree[rt];
    int mid=(beg+endd)/2;
    return max(query(2*rt,beg,mid,l,r),query(2*rt+1,mid+1,endd,l,r));
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,z,i,j,k,l,q,r,t,cnt,sm,tmp;
   readfast(t);
   for(tmp=1;tmp<=t;tmp++)
   {

       mem(tree,0);
       mem(ar,0);
       readfast(n);
       readfast(c);
       readfast(q);
       for(i=1;i<=n;i++)
       {
           read(p);
           if(ar[p].l==0)
            ar[p].l=i;
           ar[p].r=i;
           ar[p].cnt++;
           br[i]=p;
       }
       for(i=1;i<=n;i++)
       {
           update(1,1,n,i,br[i]);
       }
       pf("Case %d:\n",tmp);
       while(q--)
       {
           readfast(a);
           readfast(b);
           x=0;
           y=0;
           z=0;
           x=min(ar[br[a]].r-a,b-a)+1;
           y=min(b-ar[br[b]].l,b-a)+1;
           if(ar[br[a]].r+1<=ar[br[b]].l-1)
            z=query(1,1,n,ar[br[a]].r+1,ar[br[b]].l-1);
           pf("%d\n",max(x,max(y,z)));

       }
   }

    return 0;
}





