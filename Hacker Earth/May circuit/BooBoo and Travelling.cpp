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
#define     mod  1000000003
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


//code of sieve
int pml=10008,np=0;
char prm[10000009];
vector<int>prime;
void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i+=2){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
prm[0]='*';prm[1]='*';prime.push_back(2);for(i=3;i<pml;i+=2){if(prm[i]!='*')prime.push_back(i);}}
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
int N,M;
int least_prime_factor_of[10001];
vector<int>number_of[10001];
void calculate(void)
{
    int i,j;
    for(i=2;i<=M;i++)
    {
        if(prm[i]!='*')
        {
            least_prime_factor_of[i]=i;
            continue;
        }
        for(j=0;prime[j]<=i;j++)
        {
            if(i%prime[j]==0)
            {
                least_prime_factor_of[i]=prime[j];
                break;
            }
        }
    }
    for(i=2;i<=M;i++)
    {
        number_of[least_prime_factor_of[i]].push_back(i);
    }
}
ll dp[2][10001],visit[10001];
int A[2001][10001],B[2001][10001],num[10001];
ll Spre,Snow,Wpre,Wnow;
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,S0,W0,P,Q,R,X,Y,Z,cur,pre;
   sieve();
   sf("%d %d",&N,&M);
   sf("%d %d %d %d",&S0,&P,&Q,&R);
   Spre=S0;
   for( i = 0; i < (N*M); i++)
    {
        Snow = (((((P * Spre)%mod) * Spre)%mod) + (((Q * Spre)%mod) + R)%mod)%mod;
        A[(i/M) + 1][(i%M) + 1] = (int)Snow;
        Spre=Snow;
    }
    sf("%d %d %d %d",&W0,&X,&Y,&Z);
    Wpre=W0;
    for(i = 0; i < (N*M); i++)
    {
        Wnow = ((((X * Wpre)%mod * Wpre)%mod + ((Y * Wpre)%mod + Z)%mod))%mod;
        B[(i/M) + 1][(i%M) + 1] = (int)Wnow;
        Wpre=Wnow;
    }
//    for(i=1;i<=N;i++)
//    {
//        for(j=1;j<=M;j++)
//            pf("%d ",A[i][j]);
//        pf("\n");
//    }
//    pf("\n");
//    for(i=1;i<=N;i++)
//    {
//        for(j=1;j<=M;j++)
//            pf("%d ",B[i][j]);
//        pf("\n");
//    }
//    pf("\n");
   calculate();
   cur=1;pre=0;
   mem(dp,0);
   int flag=0;
   if(N<=100&&M<=100)
    flag=1;
   for(i=N-1;i>=1;i--)
   {
       mem(visit,-1);
       for(j=1;j<=M;j++)
       {
           if(j==1)
           {
               dp[cur][j]=(dp[pre][1]+(ll)A[i][j]);
               continue;
           }
           else
           {
              // pf("i=%d j=%d dp=%lld\n",i,j,dp[cur][j]);
               dp[cur][j]=dp[pre][1]+(ll)B[i][j];
           }
           p=least_prime_factor_of[j];
           if(visit[p]==-1LL||flag)
           {
               for(r=0;r<number_of[p].size();r++)
               {
                   k=number_of[p][r];
                   if(visit[p]==-1LL)
                   {
                     visit[p]=dp[pre][k];
                     num[p]=k;
                   }
                   else
                   {
                       if(visit[p]>dp[pre][k])
                       {
                        num[p]=k;
                        visit[p]=dp[pre][k];
                       }
                   }
                   if(j==k)
                   {
                      dp[cur][j]=min(dp[cur][j],dp[pre][k]+(ll)A[i][j]);
                   }
                   else
                   {
                     dp[cur][j]=min(dp[cur][j],dp[pre][k]+(ll)B[i][j]);
                   }
               }
                   //pf("i=%d j=%d k=%d visit[p]=%d\n",i,j,k,visit[p]);
           }
           else
           {
           // pf("i=%d j=%d visit[p]=%d A=%d B=%d\n",i,j,visit[p],A[i][j],B[i][j]);
            dp[cur][j]=min(dp[cur][j],min((ll)A[i][j]+dp[pre][j],visit[p]+((num[p]==j)?(ll)A[i][j]:(ll)B[i][j])));
           }

       }
       pre=!pre;
       cur=!cur;

   }
   ll ans=100000000000000000LL;
   for(i=1;i<=M;i++)
   {
    ans=min(ans,dp[pre][i]);
   // printf("%lld\n",ans);
   }
   pf("%lld\n",ans);
    return 0;
}

//100 10000
//9 3 1 8
//5 4 25 7
