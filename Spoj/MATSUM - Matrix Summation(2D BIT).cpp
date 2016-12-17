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

 /**************************************************Code start from here**************************/
int BIT[1025][1025],ar[1025][1025];
char ss[10];
int n;
void update(int x,int y,int val)
{
    while(x<=n)
    {
       int idx=y;
        while(idx<=n)
        {
            BIT[x][idx]+=val;
            idx+=(idx&-idx);
        }
        x+=(x&-x);
    }
}
ll query(int x,int y)
{
    ll sm=0;
    while(x>0)
    {
        int idx=y;
        while(idx>0)
        {
            sm+=BIT[x][idx];
            idx-=(idx&-idx);
        }
        x-=(x&-x);
    }
    return sm;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
  // ios_base::sync_with_stdio(false);
  int a,b,x,y,q,r,t,tmp,p,i;
   char END[]={'E','N','D','\0'};
   char SET[]={'S','E','T','\0'};
    readfast(t);
   for(i=1;i<=t;i++)
    {
        readfast(n);
        mem(BIT,0);
        mem(ar,0);
        while(1)
        {
            sf("%s",&ss);
            if(strcmp(END,ss)==0)
                break;
            if(strcmp(SET,ss)==0)
            {
             readfast(a);
             readfast(b);
             readfast(p);
                a++;
                b++;
                update(a,b,-ar[a][b]);
                update(a,b,p);
                ar[a][b]=p;
            }
            else
            {
                readfast(x);readfast(y);readfast(a);readfast(b);
                x++;y++;a++;b++;
                ll sm=0;
                sm+=query(a,b);
                sm-=query(x-1,b);
                sm-=query(a,y-1);
                sm+=query(x-1,y-1);
              pf("%lld\n",sm);
            }
        }
        pf("\n");
    }
    return 0;
}




