/**************************************
 *           BISMILLAHIR RAHMANIR RAHIM             *
 *                MD: EMRUZ HOSSAIN                    *
 *                     CUET-CSE-12                          *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ULL;

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
vector<ULL>ar[10004];
const int MAX_ROW=11,MAX_COLUMN=27;
ULL zob[MAX_ROW][MAX_COLUMN];
int ar_len[10004],block,ans[500005];
map<ULL,int>freq;
string str[100005];
struct st
{
    int l,r,id,ln;
    ULL num;
}queries[500005];

bool cmp(st a,st b)
{
    if(a.l/block==b.l/block)
        return a.r<b.r;
    return a.l/block<b.l/block;
}

void init_hash()
{
    srand(time(NULL));
    for(int i=0;i<MAX_ROW;i++)
    {
        for(int j=0;j<MAX_COLUMN;j++)
        {
            zob[i][j]=((ULL)rand()<<32)+rand();
        }
    }
}

ULL get_hash(string sp)
{
  ULL result=0;
  int s=0;
  int e=sp.size()-1;
  for(int i=s;i<=e;i++)
    result^=zob[i][sp[i]-'a'];
  return result;
}
void Add(ULL idx)
{
    freq[idx]++;
}
void Remove(ULL idx)
{
    freq[idx]--;
}
int main()
{
        //freopen("output.txt","w",stdout);
        //freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,curR,curL,L,R;
   init_hash();
   sf("%d",&n);
   block=sqrt(n)+1;
   char ss[15];
   for(i=1;i<=n;i++)
   {
       sf("%s",&ss);
       l=strlen(ss);
       string sp(ss);
       set<string>S;
       set<string>::iterator itt;
       for(j=1;j<=l;j++)
       {
           for(k=0;k+j<=l;k++)
           {
               string sl="";
               int tt=j;
               for(r=k;tt&&r<sp.size();r++,tt--)
                sl+=sp[r];
               S.insert(sl);
           }
       }
       for(itt=S.begin();itt!=S.end();++itt)
       {
           string sd=*itt;
           ar[i].push_back(get_hash(sd));
       }

   }
   //pf("%llu\n",ar[1][0][3]);
   sf("%d",&m);
   for(i=0;i<m;i++)
   {
       sf("%d %d %s",&queries[i].l,&queries[i].r,&ss);
       if(queries[i].l>queries[i].r)
        swap(queries[i].l,queries[i].r);
       queries[i].id=i;
       string sp(ss);
       queries[i].num=get_hash(sp);
   }
   sort(queries,queries+m,cmp);
   freq.clear();
   curL=1;curR=0;
   for(i=0;i<m;i++)
   {
       L=queries[i].l;
       R=queries[i].r;
       while(curR<R)
       {
           curR++;
           for(j=0;j<ar[curR].size();j++)
            Add(ar[curR][j]);
       }
      while(curR>R)
       {
            for(j=0;j<ar[curR].size();j++)
            Remove(ar[curR][j]);
           curR--;
       }
      while(curL>L)
       {
           curL--;
           for(j=0;j<ar[curL].size();j++)
            Add(ar[curL][j]);
       }
      while(curL<L)
       {
            for(j=0;j<ar[curL].size();j++)
            Remove(ar[curL][j]);
           curL++;
       }
       ans[queries[i].id]=freq[queries[i].num];

   }
   for(i=0;i<m;i++)
    pf("%d\n",ans[i]);
    return 0;
}
