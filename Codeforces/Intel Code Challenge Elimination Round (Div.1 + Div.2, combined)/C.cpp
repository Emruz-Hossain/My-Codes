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
#define     mod  1000000007
#define     PI   2.0*acos(0.0)

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

////code of sieve
//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i+=2){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
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
    ll sm,dest,un_destroyed_right,un_destroyed_left;
}tree[4*100005];
ll ar[100005];
const long long IN=-10000000000000000LL;
void build(int rt,int beg,int endd)
{
    tree[rt].dest=0;
    tree[rt].un_destroyed_left=0;
    tree[rt].un_destroyed_right=0;
    if(beg==endd)
    {
        tree[rt].sm=ar[beg];
        tree[rt].un_destroyed_left=ar[beg];
        tree[rt].un_destroyed_right=ar[beg];
        return;
    }
    int mid=(beg+endd)/2;
    build(2*rt,beg,mid);
    build(2*rt+1,mid+1,endd);
    tree[rt].sm=tree[2*rt].sm+tree[2*rt+1].sm;
    tree[rt].un_destroyed_left=tree[rt].sm;
    tree[rt].un_destroyed_right=tree[rt].sm;
}
 void update(int rt,int beg,int endd,int pos,int p)
{
    if(beg==endd&&beg==pos)
    {
        tree[rt].sm=IN;
        tree[rt].dest=1;
        tree[rt].un_destroyed_left=IN;
        tree[rt].un_destroyed_right=IN;
        return ;
    }
    int mid=(beg+endd)/2;
    if(pos<=mid)
        update(2*rt,beg,mid,pos,0);
    else
        update(2*rt+1,mid+1,endd,pos,1);
    tree[rt].dest=tree[2*rt].dest|tree[2*rt+1].dest;
    if(tree[rt].dest)
    {
        tree[rt].sm=max(tree[2*rt].sm,tree[2*rt+1].sm);
            if(tree[2*rt].dest==0)
            {
              if(tree[2*rt+1].un_destroyed_left>0)
               tree[rt].un_destroyed_left=tree[2*rt].sm+tree[2*rt+1].un_destroyed_left;
              else
                tree[rt].un_destroyed_left=tree[2*rt].sm;
            }
            else
              tree[rt].un_destroyed_left=tree[2*rt].un_destroyed_left;
             if(tree[2*rt+1].dest==0)
             {
                 if(tree[2*rt].un_destroyed_right>0)
                    tree[rt].un_destroyed_right=tree[2*rt+1].sm+tree[2*rt].un_destroyed_right;
                 else
                    tree[rt].un_destroyed_right=tree[2*rt+1].sm;

             }
            else
                tree[rt].un_destroyed_right=tree[2*rt+1].un_destroyed_right;


        tree[rt].sm=max(tree[rt].sm,tree[2*rt].un_destroyed_right+tree[2*rt+1].un_destroyed_left);
    }
    else
    {
        tree[rt].sm=tree[2*rt].sm+tree[2*rt+1].sm;
        tree[rt].un_destroyed_left=tree[rt].sm;
        tree[rt].un_destroyed_right=tree[rt].sm;
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
        //freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%lld",&n);
   for(i=1;i<=n;i++)
   {
       sf("%lld",&ar[i]);
   }
   build(1,1,n);
   for(i=0;i<n;i++)
   {
       sf("%lld",&p);
       update(1,1,n,(int)p,0);
       d=tree[1].sm;
       if(d==IN)
        d=0;
       pf("%lld\n",d);
   }

    return 0;
}


