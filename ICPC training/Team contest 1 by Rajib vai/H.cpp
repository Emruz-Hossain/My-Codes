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
struct st
{
    int x,len;
}ar[100005];
int L[100005],R[100005],tree[4*100005];
bool cmp(st a,st b)
{
    return a.x<b.x;
}
void built(int rt,int beg,int endd)
{
    if(beg==endd)
    {
        tree[rt]=beg;
        return;
    }
    int mid=(beg+endd)/2;
    built(2*rt,beg,mid);
    built(2*rt+1,mid+1,endd);
    tree[rt]=max(tree[2*rt],tree[2*rt+1]);
}
void push_down(int rt,int val)
{
    tree[2*rt]=min(tree[2*rt],val);
    tree[2*rt+1]=min(tree[2*rt+1],val);
}
int query(int rt,int beg,int endd,int idx)
{
    if(idx<1)
        return 0;
    if(beg==endd&&beg==idx)
    {
        return tree[rt];
    }
    push_down(rt,tree[rt]);
    int mid=(beg+endd)/2;
    if(mid<=idx)
        return query(2*rt,beg,mid,idx);
    else
        return query(2*rt+1,mid+1,endd,idx);
}
void update(int rt,int beg,int endd,int l,int r,int val)
{
    if(beg>r||endd<l)
        return;
    if(beg>=l&&endd<=r)
    {
        tree[rt]=min(tree[rt],val);
        return;
    }
    push_down(rt,tree[rt]);
    int mid=(beg+endd)/2;
    update(2*rt,beg,mid,l,r,val);
    update(2*rt+1,mid+1,endd,l,r,val);
    tree[rt]=max(tree[2*rt],tree[2*rt+1]);

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%d",&n);
   for(i=1;i<=n;i++)
   {
       sf("%d %d",&ar[i].x,&ar[i].len);
   }
   sort(ar+1,ar+n+1,cmp);
   for(i=1;i<=n;i++)
   {
       L[i]=i;
       R[i]=i;
   }
   for(i=1;i<=n;i++)
   {
       for(j=i-1;j>=1;j--)
       {
           if(ar[j].x>=ar[i].x-ar[i].len)
           {
               L[i]=L[j];
               j=L[j];
           }
           else
            break;
       }
   }
   for(i=n;i>=1;i--)
   {
       for(j=i+1;j<=n;j++)
       {
           if(ar[j].x<=ar[i].x+ar[i].len)
           {
               R[i]=R[j];
               j=R[j];
           }
           else
            break;
       }
   }
   for(i=1;i<=n;i++)
   {
       pf("%d = %d %d\n",i,L[i],R[i]);
   }
   built(1,1,n);

   for(i=1;i<=n;i++)
   {
       pf("%d\n",i);
       p=query(1,1,n,L[i]-1);
       pf("q1\n");
       update(1,1,n,1,i,p+1);
       pf("u1\n");
       p=query(1,1,n,i-1);
       pf("q2\n");
       update(1,1,n,1,R[i],p+1);
       pf("u2\n");
   }
   pf("%d\n",query(1,1,n,n));
    return 0;
}




