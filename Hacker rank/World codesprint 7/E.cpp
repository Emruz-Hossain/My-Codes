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
int tree[4*262145],freq_tree[4*262145],ar[4*262145],freq[262155];
vector<int>V,temp;
set<int>elements_of_freq[2*262145];
int max_depth;
vector<int>F1,F2;
int bs(int val)
{
    int l=0,h=V.size(),mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(V[mid]==val)
            return mid;
        else if( V[mid]>val)
            h=mid-1;
        else
            l=mid+1;
    }
    return mid;
}
void build(int rt,int beg,int endd)
{
    if(beg==endd)
    {
        freq_tree[rt]++;
        tree[rt]=rt;
        return;
    }
    int mid=(beg+endd)/2;
    build(2*rt+1,beg,mid);
    build(2*rt+2,mid+1,endd);
    tree[rt]=tree[2*rt+1];
    freq_tree[tree[rt]]++;
}
int GET(int frq,int val)
{
    int p=*elements_of_freq[frq].upper_bound(val);
    elements_of_freq[frq].erase(p);

    return p;
}
void build2(int rt,int beg,int endd,int depth,int val)
{
    tree[rt]=val;
    if(beg==endd)
    {
        return;
    }
    int mid=(beg+endd)/2;
    build2(2*rt+1,beg,mid,depth+1,val);
    int p=GET(max_depth-depth,val);
    build2(2*rt+2,mid+1,endd,depth+1,p);

}
int main()
{
    //    freopen("output.txt","w",stdout);
        //freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,l,q,r,t,cnt,sm,tmp;
   sf("%d",&n);
   max_depth=log2(n)+1;
   for(i=0;i<2*n-1;i++)
   {
       sf("%d",&ar[i]);
       temp.push_back(ar[i]);
   }
   sort(temp.begin(),temp.end());
   for(i=0;i<temp.size();i++)
   {
       if(V.size()==0||V.back()!=temp[i])
        V.push_back(temp[i]);
   }
   if(V.size()!=n)
   {
       pf("NO\n");
       return 0;
   }
   mem(freq,0);
   for(i=0;i<2*n-1;i++)
   {
       int idx=bs(ar[i]);
       freq[idx]++;
   }
  int  mx=0;
   int mxid=0;
   for(i=0;i<n;i++)
   {
     F1.push_back(freq[i]);
     elements_of_freq[freq[i]].insert(i);
     if(freq[i]>mx)
     {
         mx=freq[i];
         mxid=i;
     }
   }
   cnt=0;
   mem(freq_tree,0);
   build(0,1,n);
   for(i=n-1;i<=2*n-2;i++)
   {
     F2.push_back(freq_tree[i]);
   }
   sort(F1.begin(),F1.end());
   sort(F2.begin(),F2.end());
   if(F1!=F2)
   {
       pf("NO\n");
       return 0;
   }
   mem(tree,0);
   build2(0,1,n,1,mxid);

       pf("YES\n");
       for(i=0;i<2*n-1;i++)
       {
           if(i>0)
            pf(" ");
           pf("%d",V[tree[i]]);
       }
       pf("\n");

    return 0;
}


