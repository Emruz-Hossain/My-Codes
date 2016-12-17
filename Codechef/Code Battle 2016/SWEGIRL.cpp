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
    int sum,prop,l,r;
}tree[8*1000005];
int ar[500005],MakeX[100005],MakeO[100005];
char ss[500005];
void build(int rt,int beg,int endd)
{
    tree[rt].prop=-1;
    tree[rt].l=beg;
    tree[rt].r=endd;
    if(beg==endd)
    {
        tree[rt].sum=ar[beg];
        return ;
    }
    int mid=(beg+endd)/2;
    build(2*rt,beg,mid);
    build(2*rt+1,mid+1,endd);
    tree[rt].sum=tree[2*rt].sum+tree[2*rt+1].sum;

}
void propagate(int rt)
{

    tree[2*rt].prop=tree[rt].prop;
    tree[2*rt].sum=(tree[2*rt].r-tree[2*rt].l+1)*tree[2*rt].prop;
    tree[2*rt+1].prop=tree[rt].prop;
    tree[2*rt+1].sum=(tree[2*rt+1].r-tree[2*rt+1].l+1)*tree[2*rt+1].prop;
    tree[rt].sum=tree[2*rt].sum+tree[2*rt+1].sum;
    tree[rt].prop=-1;
}
void update(int rt,int beg,int endd,int l,int r,int v)
{
    if(beg>r||endd<l)
    return;
    if(beg>=l&&endd<=r)
    {
        tree[rt].prop=v;
        tree[rt].sum=(endd-beg+1)*tree[rt].prop;
        return;
    }
    if(tree[rt].prop!=-1)
       propagate(rt);
    int mid=(beg+endd)/2;
    update(2*rt,beg, mid,l,r,v);
    update(2*rt+1,mid+1,endd,l,r,v);
    tree[rt].sum=tree[2*rt].sum+tree[2*rt+1].sum;

}
int querey(int rt,int beg,int endd,int l,int r)
{
    if(beg>r||endd<l)
    return 0;
    if(beg>=l&&endd<=r)
    {
        return tree[rt].sum;
    }
    if(tree[rt].prop!=-1)
       propagate(rt);
    int mid=(beg+endd)/2;
    return querey(2*rt,beg,mid,l,r)+querey(2*rt+1,mid+1,endd,l,r);

}
int main()
{
    //    freopen("output.txt","w",stdout);
       // freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%d",&t);
   while(t--)
   {
     sf("%s",&ss);
     n=strlen(ss);
     for(i=0;i<n;i++)
     {
        if(ss[i]=='X')
         ar[i+1]=1;
         else
         ar[i+1]=0;
     }
     build(1,1,n);
     sf("%d",&k);
     for(i=0;i<k;i++)
     {
        sf("%d %d %d",&a,&l,&r);
        if(a==1)
        {
          update(1,1,n,l,r,1);

        }
        else
        {
            update(1,1,n,l,r,0);

        }
     }
     for(i=1;i<=n;i++)
     {
        ar[i]=querey(1,1,n,i,i);
        //pf("%d ",ar[i]);
     }
     //pf("\n");
     MakeX[0]=0;
     for(i=1;i<=n;i++)
     {
         MakeX[i]=MakeX[i-1];
         if(ar[i]==0)
            MakeX[i]++;
        pf("%d ",MakeX[i]);
     }
     pf("\n");
     MakeX[n+1]=MakeX[n];
     MakeO[n+1]=0;
     for(i=n;i>0;i--)
     {
         MakeO[i]=MakeO[i+1];
         if(ar[i]==1)
            MakeO[i]++;
        pf("%d ",MakeO[i]);
     }
     pf("\n");
     MakeO[0]=MakeO[1];
     sm=n+1;
     for(i=0;i<=n+1;i++)
        sm=min(sm,MakeX[i]+MakeO[i]);
     pf("%d\n",sm);
   }

    return 0;
}


