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
const int sz=1001;
int dp[3][sz][sz][3],dir[3][sz][sz][3],n;
int rec(int idx,int startColor,int r,int y,int b,int prevColor,int cnt)
{
    if(idx==n)
    {
        return 1;
    }
    int &ret=dp[startColor][r][y][prevColor];
    if(ret!=-1)
        return ret;
    ret=0;
    if(idx==n-1)
    {
        if(startColor!=0&&prevColor!=0&&r>0)
        {
            ret=rec(idx+1,startColor,r-1,y,b,0,cnt+1);
            if(ret==1)
            dir[startColor][r][y][prevColor]=0;  
        }
        else if(startColor!=1&&prevColor!=1&&y>0)
        {
            ret=rec(idx+1,startColor,r,y-1,b,1,cnt+1);
            if(ret==1)
            dir[startColor][r][y][prevColor]=1;  
        }
        else if(startColor!=2&&prevColor!=2&&b>0)
        {
            ret=rec(idx+1,startColor,r,y,b-1,2,cnt+1);
            if(ret==1)
            dir[startColor][r][y][prevColor]=2;  
        }
    }
    else
    {
        if(prevColor!=0&&r>0)
        {
          ret=rec(idx+1,startColor,r-1,y,b,0,cnt+1);
          if(ret==1)
            dir[startColor][r][y][prevColor]=0;  
        }
        if(!ret&&prevColor!=1&&y>0)
        {
            ret=rec(idx+1,startColor,r,y-1,b,1,cnt+1);
            if(ret==1)
            dir[startColor][r][y][prevColor]=1;
        }
        if(!ret&&prevColor!=2&&b>0)
        {
            ret=rec(idx+1,startColor,r,y,b-1,2,cnt+1);
            if(ret==1)
            dir[startColor][r][y][prevColor]=2;
        }
    }
    // for(int j=0;j<cnt;j++)
    //     pf(" ");
    // pf("%d %d %d = %d\n",r,y,b,ret);
    return ret;
}
string result;
void generateString(int startColor,int r,int y,int b,int prevColor)
{
    if(result.size()==n)
        return;
    int &ret=dir[startColor][r][y][prevColor];
    if(ret!=-1)
    {
        if(ret==0)
        {
            r--;
            result+='R';
        }
        else if(ret==1)
        {
            y--;
            result+='Y';
        }
        else if(ret==2)
        {
            b--;
            result+='B';
        }
        generateString(startColor,r,y,b,ret);
    }
}
int main()
{
       freopen("output2.txt","w",stdout);
        freopen("B-small-attempt0.in","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,o,v,g;
   sf("%d",&t);
   for(x=1;x<=t;x++)
   {
       sf("%d %d %d %d %d %d %d",&n,&r,&o,&y,&g,&b,&v);
       mem(dp,-1);
       mem(dir,-1);
       cnt=0;
       if(r>0)
       {
       cnt=rec(1,0,r-1,y,b,0,0);
       a=0;
       }
       if(!cnt&&y>0)
       {
           cnt=rec(1,1,r,y-1,b,1,0);
           a=1;
       }
       if(!cnt&&b>0)
       {
           cnt=rec(1,2,r,y,b-1,2,0);
           pf("%d\n",cnt);
           a=2;
       }
       if(!cnt)
       {
           pf("Case #%d: IMPOSSIBLE\n",x);
       }
       else 
       {
           result="";
           if(a==0)
           {
            result+='R';
            r--;
           }
           else if(a==1)
           {
            result+='Y';
               y--;
           }
           else if(a==2)
           {
               result+='B';
               b--;
           }
           generateString(a,r,y,b,a);
           pf("Case #%d: ",x);
           cout<<result<<endl;
       }
   }

    return 0;
}

