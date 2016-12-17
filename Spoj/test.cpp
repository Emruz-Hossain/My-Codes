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

//code of sieve
int pml=32770,np=0;
char prm[10000009];
int prime[800000];
void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i+=2){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
prm[0]='*';prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
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
vector<int>PRM;
int ar[32770],mp[32770];
ll dp[32770][16];
ll rec(int mask,int start)
{
    if(mask==0)
        return ar[mask];
    ll &ret=dp[mask][start];
    if(ret!=-1LL)
        return ret;
    int i,mask2;
    //pf("%d %d\n",fixed_position,mask);
    ret=ar[mask];
    for(i=start;i<PRM.size();i++)
    {
        if(Check(mask,i))
        {
            mask2=mask;
            mask2=Reset(mask2,i);
            ret+=rec(mask2,i+1);
        }
    }
    return ret;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,x,y,i,j,k,l,r,t,tmp,mask,mx,mask2;
   ll sm,cnt,p,q;
   sieve();
   mem(mp,0);
   for(i=2;i<=50;i++)
   {
       if(prm[i]!='*')
       {
            PRM.push_back(i);
            mask=0;
            mask=Set(mask,PRM.size()-1);
            mp[mask]=1;
       }

   }
   sf("%d",&t);
   while(t--)
   {
       mem(ar,0);
       sf("%d",&n);
       for(i=0;i<n;i++)
       {
           sf("%lld",&p);
           if(p==1LL)
           {
               ar[0]++;
               continue;
           }
           mask=0;
           for(j=0;j<PRM.size();j++)
           {
             if(p%PRM[j]==0)
                 mask=Set(mask,j);
           }
            ar[mask]++;
       }
       mem(dp,-1);
       mx=(1<<15)-1;
       sm=0;
       for(i=0;i<=mx;i++)
       {
           if(ar[i]>0)
           {
               mask=(1<<15)-1;
               for(j=0;j<PRM.size();j++)
               {
                   if(Check(i,j))
                   {
                       mask=Reset(mask,j);
                   }
               }
               p=cnt=rec(mask,0);
               for(j=0;j<PRM.size();j++)
               {
                   mask2=mask;
                   if(Check(i,j))
                   {
                       mask2=Set(mask2,j);
                       q=rec(mask2,0);
                       cnt+=q-p;
                   }
               }
               if(cnt>0&&(i==0||mp[i]==1))
                cnt-=ar[i];
                sm+=cnt*ar[i];
                if(i==0||mp[i]==1)
                {
                    if(ar[i]>1)
                      sm+=ar[i]*ar[i];
                    else
                      sm+=ar[i];
                }
           }
       }
       pf("%lld\n",sm);
   }
    return 0;
}


