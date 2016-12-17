/**************************************
 *     BISMILLAHIR RAHMANIR RAHIM     *
 *        MD: EMRUZ HOSSAIN           *
 *           CUET-CSE-12              *
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
    int l,r,id;
}queries[50005];
const int mz=50001;
const int msz=mz*2;
int prefix_sum[mz+5],lower_active_bound_of[msz+5],upper_active_bound_of[msz+5];
int tree[2*msz];
int ans[mz+5],block,ar[mz+5];
vector<int>indexes_of[2*mz+5];
bool cmp(st a ,st b)
{
    if(a.l/block==b.l/block)
        return a.r<b.r;
    return a.l/block<b.l/block;
}
void update(int p,int val)
{
    for(tree[p+=msz]=val;p>1;p>>=1)
        tree[p>>1]=max(tree[p],tree[p^1]);
}
int query(int l,int r)
{
    int res=-inf;
    for(l+=msz,r+=msz;l<r;l>>=1,r>>=1)
    {
        if(l&1) res=max(res,tree[l++]);
        if(r&1) res=max(res,tree[--r]);
    }
    return res;
}
void Add(int val,int dir)
{
    if(dir==1)
    {
        upper_active_bound_of[val]++;
        if(lower_active_bound_of[val]==-1)
            lower_active_bound_of[val]=0;
    }
    else
    {
        lower_active_bound_of[val]--;
    }
    //pf("val= %d lb= %d ub=%d ",val,lower_active_bound_of[val],upper_active_bound_of[val]);
    //pf("%d\n",indexes_of[val][upper_active_bound_of[val]]-indexes_of[val][lower_active_bound_of[val]]);
    update(val,indexes_of[val][upper_active_bound_of[val]]-indexes_of[val][lower_active_bound_of[val]]);
}
void Remove(int val,int dir)
{    if(lower_active_bound_of[val]>upper_active_bound_of[val])
        return;
    if(dir==1)
    {
        upper_active_bound_of[val]--;
    }
    else
    {
        lower_active_bound_of[val]++;
    }
   // pf("--val= %d ub= %d lb=%d ",val,upper_active_bound_of[val],lower_active_bound_of[val]);
   // pf("idu=%d idl=%d\n",indexes_of[val][upper_active_bound_of[val]],indexes_of[val][lower_active_bound_of[val]]);
    if(lower_active_bound_of[val]>upper_active_bound_of[val])
        return ;
    update(val,indexes_of[val][upper_active_bound_of[val]]-indexes_of[val][lower_active_bound_of[val]]);
}
int main()
{
        //freopen("out2.txt","w",stdout);
        //freopen("gen.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,curL,curR,L,R;
   sf("%d %d",&n,&m);
   prefix_sum[0]=0;
   indexes_of[mz].push_back(0);
   for(i=1;i<=n;i++)
   {
       sf("%d",&ar[i]);
       prefix_sum[i]=prefix_sum[i-1]+ar[i];
       indexes_of[prefix_sum[i]+mz].push_back(i);
   }
//   for(i=0;i<indexes_of[50020].size();i++)
//    pf("%d ",indexes_of[50020][i]);
//   pf("\n");
//   return 0;
    for(i=0;i<m;i++)
    {
        sf("%d %d",&queries[i].l,&queries[i].r);
        queries[i].id=i;
        queries[i].l--;
    }
    block=sqrt(n);
    sort(queries,queries+m,cmp);

    for(i=0;i<=2*mz;i++)
        lower_active_bound_of[i]=upper_active_bound_of[i]=-1;
    lower_active_bound_of[mz]=upper_active_bound_of[mz]=0;
    curL=0;curR=0;
    mem(tree,0);
    for(i=0;i<m;i++)
    {
        L=queries[i].l;
        R=queries[i].r;
        while(curR<R)
        {
            curR++;
            Add(prefix_sum[curR]+mz,1);
        }
        while(curR>R)
        {
            Remove(prefix_sum[curR]+mz,1);
            curR--;
        }
        while(curL>L)
        {
            curL--;
            Add(prefix_sum[curL]+mz,0);
        }
        while(curL<L)
        {
            Remove(prefix_sum[curL]+mz,0);
            curL++;
        }
        ans[queries[i].id]=query(0,msz);
    }
    for(i=0;i<m;i++)
        pf("%d\n",ans[i]);
    return 0;
}


//10
//5
//1 -1 -1 -1 1 1 -1 -1 1 1
//2 5
//3 6
//1 6
//2 10
//1 10


