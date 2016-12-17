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

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1}; //move in 8 direction
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2}; //move of knight

////code of sieve
//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
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
char A[105],B[105],virus[105];
int dp[102][102][102],la,lb,lv,next[105];
void largest_prefix_which_is_suffix(void)
{
    int q=0 , k , m =lv;
    next[0] = 0;
    for(int i=1;i<m;i++)
    {
        while(q > 0 && virus[i]!=virus[q])
        {
            k  =  next[q-1];
            q  =  k;
        }
        if(virus[q]==virus[i]) q++;
        next[i] = q;
    }
}
int rec(int ida,int idb,int idv)
{
    if(ida>=la||idb>=lb)
        return 0;
    int &ret=dp[ida][idb][idv];
    if(ret!=-1)
        return ret;
    int sm=0;
    if(A[ida]==B[idb])
    {
        if(A[ida]==virus[idv]&&idv<lv-1)
            sm=max(sm,rec(ida+1,idb+1,idv+1)+1);
        else if(A[ida]!=virus[idv])
        {
            while(idv>0&&A[ida]!=virus[idv])
                idv=next[idv-1];
            if(A[ida]==virus[idv])
                  idv++;
            sm=max(sm,rec(ida+1,idb+1,idv)+1);
        }

    }
    sm=max(sm,rec(ida+1,idb,idv));
    sm=max(sm,rec(ida,idb+1,idv));
    return ret=sm;
}
void print(int ida,int idb,int idv,int rem)
{
    if(rem==0)
        return;
    if(A[ida]==B[idb])
    {
        if(A[ida]!=virus[idv])
        {
            printf("%c",A[ida]);
             while(idv>0&&A[ida]!=virus[idv])
                idv=next[idv-1];
            if(A[ida]==virus[idv])
                  idv++;
            print(ida+1,idb+1,idv,rem-1);
        }
        else if(A[ida]==virus[idv]&&idv<lv-1)
        {
            if(dp[ida+1][idb+1][idv]==rem)
                print(ida+1,idb+1,idv,rem);
            else
            {
                 printf("%c",A[ida]);
            print(ida+1,idb+1,idv+1,rem-1);
            }

        }
        else
        {
            if(dp[ida+1][idb][idv]==rem)
              print(ida+1,idb,idv,rem);
            else
              print(ida,idb+1,idv,rem);
        }

    }
    else
    {
        if(dp[ida+1][idb][idv]==rem)
            print(ida+1,idb,idv,rem);
        else
            print(ida,idb+1,idv,rem);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    sf("%s %s %s",&A,&B,&virus);
    la=strlen(A);
    lb=strlen(B);
    lv=strlen(virus);
    largest_prefix_which_is_suffix();
//    for(i=0;i<lv;i++)
//        pf("%d ",next[i]);
//    pf("\n");

    mem(dp,-1);
    d=rec(0,0,0);
    //pf("%d\n",d);
    if(d>0)
    {
         print(0,0,0,d);
         pf("\n");
    }
    else
        pf("%d\n",d);


    return 0;
}




