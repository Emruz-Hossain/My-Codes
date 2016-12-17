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
int ar[100005],tree[4*100005];
void built(int rt,int beg,int endd)
{
    if(beg==endd)
    {
        tree[rt]=1;
        return;
    }
    int mid=(beg+endd)/2;
    built(2*rt,beg,mid);
    built(2*rt+1,mid+1,endd);
    tree[rt]=tree[2*rt]+tree[2*rt+1];
}
int query(int rt,int beg,int endd,int val)
{
    if(beg==endd)
        return beg;
    int mid=(beg+endd)/2;
    if(tree[2*rt]>=val)
        return query(2*rt,beg,mid,val);
    else
        return query(2*rt+1,mid+1,endd,val-tree[2*rt]);
}
int sum(int rt,int beg,int endd,int l,int r)
{
    if(beg>r||endd<l)
     return 0;
    if(beg>=l&&endd<=r)
        return tree[rt];
    int mid=(beg+endd)/2;
    return  sum(2*rt,beg,mid,l,r)+sum(2*rt+1,mid+1,endd,l,r);
}
void update(int rt,int beg,int endd,int idx)
{
    if(beg==endd&&beg==idx)
    {
        tree[rt]=0;
        return;
    }
    int mid=(beg+endd)/2;
    if(idx<=mid)
        update(2*rt,beg,mid,idx);
    else
        update(2*rt+1,mid+1,endd,idx);
    tree[rt]=tree[2*rt]+tree[2*rt+1];
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,last_idx,next_skip,next_person,rem,mid;
 sf("%d",&t);
 while(t--)
 {
     sf("%d",&n);
     built(1,1,n);
     last_idx=1;
     next_skip=1;
     next_person=0;
     rem=n;
     while(rem>0)
     {
         next_person=(next_person%rem)+1;
        p=sum(1,1,n,last_idx,n);
        if(p>=next_person)
        {
            next_person+=sum(1,1,n,1,last_idx-1);
        }
        else
        {
            next_person-=p;
        }
        mid=query(1,1,n,next_person);
        update(1,1,n,mid);
        last_idx=mid;
        rem--;
        next_person=next_skip;
        next_skip++;
     }
     pf("%d\n",last_idx);

     //alternativ code
      //sf("%d",&n);
     dp[1]=1;
     k=n-2;
     for(i=2;i<=n;i++)
     {
         dp[i]=(dp[i-1]+k)%i+1;
         k--;
     }
     pf("%d\n",dp[n]);
 }

    return 0;
}




