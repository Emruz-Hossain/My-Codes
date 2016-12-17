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
    ll mn,mx;
}tree[4*1000005];
ll ar[1000005],m,n,hmin,hmax;
void update(ll rt, ll beg, ll endd,ll idx,ll val)
{
    if(beg==endd&&beg==idx)
    {
        tree[rt].mn=val;
        tree[rt].mx=val;
        return;
    }
    ll mid=(beg+endd)/2;
    if(idx<=mid)
        update(2*rt,beg,mid,idx,val);
    else
        update(2*rt+1,mid+1,endd,idx,val);
    tree[rt].mn=min(tree[2*rt].mn,tree[2*rt+1].mn);
    tree[rt].mx=max(tree[2*rt].mx,tree[2*rt+1].mx);
}
st query(ll rt, ll beg, ll endd, ll L ,ll R)
{
    st aa;
    if(beg>R||endd<L)
    {
        aa.mn=4000000000LL;
        aa.mx=-4000000000LL;
        return aa;
    }
    if(beg>=L&&endd<=R)
        return tree[rt];
    ll mid=(beg+endd)/2;
    st p=query(2*rt,beg,mid,L,R);
    st q=query(2*rt+1,mid+1,endd,L,R);
    aa.mn=min(p.mn,q.mn);
    aa.mx=max(p.mx,q.mx);
    return aa;
}
bool Valid(ll L, ll R)
{
    st aa;
    if(L==R)
    {

        aa=query(1,1,n+1,L,R);
        if(aa.mn<m)
            return false;
        else
            return true;
    }
    else
    {

        aa=query(1,1,n+1,L+1,R);
        if(aa.mn<hmin||aa.mx>hmax)
            return false;
        else
            return true;
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,start,minL,minR,maxL,maxR;
   sf("%lld",&n);
   ar[1]=-3000000000LL;
   for(i=2;i<n+2;i++)
    sf("%lld",&ar[i]);
   ar[n+2]=3000000000LL;
   sf("%lld %lld %lld",&m,&hmin,&hmax);
   for(i=2;i<=n+1;i++)
    update(1,1,n+1,i,ar[i]-ar[i-1]);
   start=-40000000000LL;
   for(i=2;i<n+2;i++)
   {
       l=i;h=n+1;
       while(l<=h)
       {
           j=(l+h)/2;
           if(Valid(i,j)) //check if the range is valid.
           {
               if(ar[j]-ar[i]+1==m)
               {
                   start=ar[i];
                   break;
               }
               else if(ar[j]-ar[i]+1<m)
               {
                   minR=hmin;
                   maxR=min(ar[j+1]-ar[j],hmax);
                   minL=hmin;
                   maxL=min(ar[i]-ar[i-1],hmax);
                    if(ar[j]+minR-1<=ar[j+1]&&ar[i]+m-1>=ar[j]+minR-1&&ar[i]+m-1<=ar[j]+maxR-1) //fix left extend right.
                    {
                        start=ar[i];
                        break;
                    }
                    else if(ar[i]-minL+1>=ar[i-1]&&ar[j]-m+1<=ar[i]-minL+1&&ar[j]-m+1>=ar[i]-maxL+1) //fix right extend left
                    {
                        start=ar[j]-m+1;
                        break;
                    }
                    else if(ar[i]-minL+1>=ar[i-1]&&ar[j]+minR-1<=ar[j+1]&&(ar[j]+maxR-1)-(ar[i]-maxL+1)+1>=m) //extend both side.
                    {
                        start= max(ar[i]-maxL+1,ar[j]+minR-1-m+1);
                        break;
                    }
                    else
                        l=j+1;
               }
               else
                h=j-1;
           }
           else
            h=j-1;
       }
       if(start!=-40000000000LL)
        break;
   }
   pf("%lld\n",start);
    return 0;
}
