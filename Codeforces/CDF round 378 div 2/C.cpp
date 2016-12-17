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
    int l,r;
}ranges[5005];
int ar[505],br[505],done_before;
struct st2
{
    int idx;
    char ch;
};
vector<st2>ans;
vector<int> change(vector<int> v,int idx1,int idx2)
{
    vector<int>tmp;
    int i;
    for(i=0;i<idx1;i++)
        tmp.push_back(v[i]);
    tmp.push_back(v[idx1]+v[idx2]);
    for(i=idx2+1;i<v.size();i++)
        tmp.push_back(v[i]);
    return tmp;
}
bool possible(vector<int>v)
{
    int i,flag=0;
    if(v.size()==1)
        return true;
    vector<pair<int,int> >tmp;
    for(i=0;i<v.size();i++)
    {
        tmp.push_back(make_pair(v[i],i));
    }
    sort(tmp.begin(),tmp.end());
    for(i=tmp.size()-1;i>=0;i--)
    {
        pair<int,int>aa;
        aa=tmp[i];
        if(aa.second>0&&v[aa.second-1]<v[aa.second])
        {
            st2 bb;
            bb.idx=done_before+aa.second;
            bb.ch='L';
            ans.push_back(bb);
            v=change(v,aa.second-1,aa.second);
            flag=1;
            break;
        }
        else if(aa.second+1<v.size()&&v[aa.second+1]<v[aa.second])
        {
            st2 bb;
            bb.idx=done_before+aa.second;
            bb.ch='R';
            ans.push_back(bb);
            v=change(v,aa.second,aa.second+1);
            flag=1;
            break;
        }
    }
    if(flag==0)
        return false;
    if(v.size()>1)
        return possible(v);
    else
        return true;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%d",&n);
   for(i=0;i<n;i++)
    sf("%d",&ar[i]);
   sf("%d",&k);
   for(i=0;i<k;i++)
    sf("%d",&br[i]);
   l=0;
   for(i=0;i<k;i++)
   {
     ranges[i].l=l;
     sm=0;
     while(l<n&&br[i]>sm)
     {
         sm+=ar[l];
         l++;
     }
    // pf("%d %d\n",br[i],sm);
     if(br[i]==sm)
     {
         ranges[i].r=l-1;
     }
     else
     {
         pf("NO\n");
         return 0;
     }
   }
   if(l<n)
   {
       pf("NO\n");
       return 0;
   }
  // pf("done\n");
   done_before=0;
   for(i=0;i<k;i++)
   {
       vector<int>v;
       for(j=ranges[i].l;j<=ranges[i].r;j++)
         v.push_back(ar[j]);
       if(!possible(v))
       {
           //pf("%d =%d %d\n",br[i],ranges[i].l,ranges[i].r);
        pf("NO\n");
        return 0;
       }
       else
       {
           done_before++;
       }
   }
   pf("YES\n");
   for(i=0;i<ans.size();i++)
    pf("%d %c\n",ans[i].idx+1,ans[i].ch);

    return 0;
}

