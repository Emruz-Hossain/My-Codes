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
vector<int>V,tem;
struct st
{
    int l,r,id;
}queries[100005];
int ar[100005],tree[100005],block,n;;
ll ans[100005],inversion;
double mx_cloack;
int max_size;
bool cmp(st a,st b)
{
    if(a.l/block==b.l/block)
        return a.r<b.r;
    return a.l/block<b.l/block;
}
int bs(int val)
{
    int mid,l=0,h=V.size()-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(V[mid]==val)
            return mid;
        else if(V[mid]>val)
            h=mid-1;
        else
            l=mid+1;
    }
    return mid;
}
void update(int idx,int val)
{
    while(idx<=max_size)
    {
        tree[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx)
{
    int sm=0;
    while(idx>0)
    {
        sm+=tree[idx];
        idx-=(idx&-idx);
    }
    return sm;
}
void Add(int val,int dir)
{
    if(dir==0)
      inversion+=query(val-1);
    else
      inversion+=query(max_size)-query(val);
    update(val,1);
}
void Remove(int val,int dir)
{
    if(dir==0)
    inversion-=query(val-1);
    else
    inversion-=query(max_size)-query(val);
     update(val,-1);
}
int main()
{
        //freopen("output.txt","w",stdout);
        //freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,p,x,y,i,j,k,l,q,r,t,tmp,curR,curL,L,R;
   sf("%d %d",&n,&q);
   block=sqrt(n);
   for(i=1;i<=n;i++)
   {
       sf("%d",&ar[i]);
       tem.push_back(ar[i]);
   }
   sort(tem.begin(),tem.end());
   l=tem.size();
   for(i=0;i<l;i++)
   {
       if(V.size()==0||V.back()!=tem[i])
        V.push_back(tem[i]);
   }
    for(i=1;i<=n;i++)
      ar[i]=bs(ar[i])+1;
    for(i=0;i<q;i++)
    {
        sf("%d %d",&queries[i].l,&queries[i].r);
        queries[i].id=i;
    }
    sort(queries,queries+q,cmp);
    mem(tree,0);
    max_size=V.size();
    curL=1;curR=0;inversion=0;
    for(i=0;i<q;i++)
    {
        L=queries[i].l;
        R=queries[i].r;
        while(curR<R)
        {
            curR++;
            Add(ar[curR],1);
        }
        while(curR>R)
        {
            Remove(ar[curR],1);
            curR--;
        }
        while(curL>L)
        {
            curL--;
            Add(ar[curL],0);
        }
        while(curL<L)
        {
            Remove(ar[curL],0);
            curL++;
        }
        ans[queries[i].id]=inversion;
    }
    for(i=0;i<q;i++)
        pf("%lld\n",ans[i]);
    return 0;
}
