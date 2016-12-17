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
ll A[1000005],prefix_sum[1000005],block,lower_active_bound_of[1000005],upper_active_bound_of[1000005];
vector<ll>indexes_of[1000005];
ll tree[8*1000005],k,ans[1000004];
struct st
{
    ll l,r,id;
}queries[1000005];
bool cmp(st a,st b)
{
    if(a.l/block==b.l/block)
        return a.r<b.r;
    return a.l/block<b.l/block;
}
void update(ll rt,ll beg,ll endd,ll idx,ll val)
{
    if(beg==endd)
    {
        tree[rt]=val;
        return;
    }
    ll mid=(beg+endd)/2;
    if(idx<=mid)
        update(2*rt,beg,mid,idx,val);
    else
        update(2*rt+1,mid+1,endd,idx,val);
    tree[rt]=max(tree[2*rt],tree[2*rt+1]);
}
void Add(ll val,int dirrection)
{
    if(dirrection==1)
    {
        upper_active_bound_of[val]++;
        if(lower_active_bound_of[val]==-1)
            lower_active_bound_of[val]=0;
    }
    else
    {
        lower_active_bound_of[val]--;
    }
    update(1,1,k-1,val,indexes_of[val][upper_active_bound_of[val]]-indexes_of[val][lower_active_bound_of[val]]);
}
void Remove(ll val,int dirrection)
{
    if(lower_active_bound_of[val]>upper_active_bound_of[val])
        return;
    if(dirrection==1)
    {
        lower_active_bound_of[val]++;
    }
    else
    {
        upper_active_bound_of[val]--;
    }
    if(lower_active_bound_of[val]>upper_active_bound_of[val])
        return;
    update(1,1,k-1,val,indexes_of[val][upper_active_bound_of[val]]-indexes_of[val][lower_active_bound_of[val]]);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,n,p,x,y,i,j,l,q,r,t,cnt,sm,tmp,curL,curR,L,R;
   sf("%lld %lld %lld",&n,&m,&k);
   block=250;
   for(i=1;i<=n;i++)
   {
       sf("%lld",&A[i]);
   }
   prefix_sum[0]=0;
   indexes_of[0].push_back(0);
   for(i=1;i<=n;i++)
   {
       prefix_sum[i]=(prefix_sum[i-1]+A[i])%k;
       indexes_of[prefix_sum[i]].push_back(i);
   }
   for(i=0;i<m;i++)
   {
       sf("%lld %lld",&queries[i].l,&queries[i].r);
       queries[i].id=i;
       queries[i].l--;
   }
   sort(queries,queries+m,cmp);
   for(i=0;i<k;i++)
   {
       lower_active_bound_of[i]=upper_active_bound_of[i]=-1;
   }
   curL=0;curR=0;
   for(i=0;i<m;i++)
   {
       L=queries[i].l;
       R=queries[i].r;
       while(curR<=R)
       {
           Add(prefix_sum[curR],1);
           curR++;
       }
       while(curR>R+1)
       {
           Remove(prefix_sum[curR-1],0);
           curR--;
       }
       while(curL>L)
       {

           Add(prefix_sum[curL-1],0);
           curL--;
       }
       while(curL<L)
       {
           Remove(prefix_sum[curL],1);
           curL++;
       }
       ans[queries[i].id]=tree[1];
   }
   for(i=0;i<m;i++)
    pf("%lld\n",ans[i]);
    return 0;
}
//
//10 1 10
//2 5 3 2 6 4 6 4 3 3
