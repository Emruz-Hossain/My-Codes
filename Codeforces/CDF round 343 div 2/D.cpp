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

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1}; //move in 8 direction
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
struct st
{
    int idx;
    double vol;
}ar[500005];
vector<int>v;
vector<double>vol;
bool cmp(st a, st b)
{
    return a.vol<b.vol;
}
double tree[4*500005];
void build(int rt,int beg,int endd)
{
    tree[rt]=0.0;
    if(beg==endd)
    {
        tree[rt]=0.00;
        return ;
    }
    int mid=(beg+endd)/2;
    build(2*rt,beg,mid);
    build(2*rt+1,mid+1,endd);
}
double query(int rt,int beg,int endd,int l,int r)
{
    if(beg>r||endd<l)
        return 0.0;
    if(beg>=l&&endd<=r)
    {
        return tree[rt];
    }
    int mid=(beg+endd)/2;
    return max(query(2*rt,beg,mid,l,r),query(2*rt+1,mid+1,endd,l,r));
}
void update(int rt,int beg,int endd,int idx,double val)
{
    if(beg==endd&&beg==idx)
    {
        tree[rt]=val;
        return;
    }
    int mid=(beg+endd)/2;
    if(idx<=mid)
        update(2*rt,beg,mid,idx,val);
    else
        update(2*rt+1,mid+1,endd,idx,val);
    tree[rt]=max(tree[2*rt],tree[2*rt+1]);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,r,t,cnt,sm,tmp;
   sf("%d",&n);
   double rad,hgt;
   for(i=0;i<n;i++)
   {
       sf("%lf %lf",&rad,&hgt);
       ar[i].idx=i;
       ar[i].vol=PI*rad*rad*hgt;
   }
   sort(ar,ar+n,cmp);
//   for(i=0;i<n;i++)
//    pf("%lf\n",ar[i].vol);
   build(1,1,n);
   for(i=0;i<n;i++)
   {
       v.clear();
       vol.clear();
      for(j=i;j<n;j++)
      {
          if(fabs(ar[j].vol-ar[i].vol)<eps)
          {
              v.push_back(ar[j].idx);
          }
          else
            break;
      }
      k=i;
      i=j-1;
      for(j=0;j<v.size();j++)
      {
          double ans=0.0;
          double q=query(1,1,n,1,v[j]);
          vol.push_back(q+ar[k+j].vol);
      }
      for(j=0;j<v.size();j++)
      {
          update(1,1,n,v[j]+1,vol[j]);
      }
   }
   pf("%.9lf\n",tree[1]);
    return 0;
}




