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
//prm[0]='*'prm[1]='*;/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
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
char ss[10][100005];
int next[10][100005],match,is_substring;
void calculate_next(int idx)
{
    int q=0,m=strlen(ss[idx]),i;
    next[idx][0]=0;
    for(i=1;i<m;i++)
    {
        while(q>0&&ss[idx][i]!=ss[idx][q])
            q=next[idx][q-1];
        if(ss[idx][q]==ss[idx][i])
           q++;
//        if(ss[idx][q]==ss[idx][i])
//           next[idx][i]=next[idx][q];
//        else
            next[idx][i]=q;
    }
}
void KMP(int idx1,int idx2)
{
    calculate_next(idx2);
    int q=0,n=strlen(ss[idx1]),m=strlen(ss[idx2]),i;
    for(i=0;i<n;i++)
    {
        while(q>0&&ss[idx1][i]!=ss[idx2][q])
            q=next[idx2][q-1];
        if(ss[idx1][i]==ss[idx2][q])
            q++;
        if(i==n-1)
        match=q;
        if(q==m)
        {
             q=next[idx2][q];
             is_substring=1;
        }

    }
}
int substring(int idx1,int idx2)
{
    is_substring=0;
    KMP(idx1,idx2);
    return is_substring;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,sub01,sub02,sub10,sub12,sub20,sub21;
   sf("%s %s %s",&ss[0],&ss[1],&ss[2]);
   sm=strlen(ss[0])+strlen(ss[1])+strlen(ss[2]);
   sub01=substring(0,1);
   sub02=substring(0,2);
   sub10=substring(1,0);
   sub12=substring(1,2);
   sub20=substring(2,0);
   sub21=substring(2,1);
   if(sub01&&sub02)
   {
      sm=strlen(ss[0]);
   }
   else if(sub10&&sub12)
   {
      sm=strlen(ss[1]);
   }
   else if(sub20&&sub21)
   {
       sm=strlen(ss[2]);
   }
   else if(sub01||sub21)
   {
       d=strlen(ss[0])+strlen(ss[2]);
       KMP(0,2);
       sm=min(sm,d-match);
       KMP(2,0);
       sm=min(sm,d-match);
   }
   else if(sub02||sub12)
   {
       d=strlen(ss[0])+strlen(ss[1]);
       KMP(0,1);
       sm=min(sm,d-match);
       KMP(1,0);
       sm=min(sm,d-match);
   }
   else if(sub10||sub20)
   {
       d=strlen(ss[1])+strlen(ss[2]);
       KMP(1,2);
       sm=min(sm,d-match);
       KMP(2,1);
       sm=min(sm,d-match);
   }
   else
   {

       KMP(0,1);
       l=strlen(ss[0]);
       l-=match;
       for(i=0;i<l;i++)
        ss[3][i]=ss[0][i];
       l=strlen(ss[1]);
       for(j=0;j<l;j++,i++)
        ss[3][i]=ss[1][j];
       ss[3][i]='\0';
       d=strlen(ss[3])+strlen(ss[2]);
       KMP(3,2);
       sm=min(sm,d-match);
       KMP(2,3);
       sm=min(sm,d-match);



       KMP(0,2);
       l=strlen(ss[0]);
       l-=match;
       for(i=0;i<l;i++)
        ss[4][i]=ss[0][i];
       l=strlen(ss[2]);
       for(j=0;j<l;j++,i++)
        ss[4][i]=ss[2][j];
       ss[4][i]='\0';
       d=strlen(ss[4])+strlen(ss[1]);
       KMP(4,1);
       sm=min(sm,d-match);
       KMP(1,4);
       sm=min(sm,d-match);


       KMP(2,0);
       l=strlen(ss[2]);
       l-=match;
       for(i=0;i<l;i++)
        ss[5][i]=ss[2][i];
       l=strlen(ss[0]);
       for(j=0;j<l;j++,i++)
        ss[5][i]=ss[0][j];
       ss[5][i]='\0';
       d=strlen(ss[5])+strlen(ss[1]);
       KMP(5,1);
       sm=min(sm,d-match);
       KMP(1,5);
       sm=min(sm,d-match);

       KMP(2,1);
       l=strlen(ss[2]);
       l-=match;
       for(i=0;i<l;i++)
        ss[6][i]=ss[2][i];
       l=strlen(ss[1]);
       for(j=0;j<l;j++,i++)
        ss[6][i]=ss[1][j];
       ss[6][i]='\0';
       d=strlen(ss[6])+strlen(ss[0]);
       KMP(6,0);
       sm=min(sm,d-match);
       KMP(0,6);
       sm=min(sm,d-match);



       KMP(1,2);
       l=strlen(ss[1]);
       l-=match;
       for(i=0;i<l;i++)
        ss[7][i]=ss[1][i];
       l=strlen(ss[2]);
       for(j=0;j<l;j++,i++)
        ss[7][i]=ss[2][j];
       ss[7][i]='\0';
        d=strlen(ss[7])+strlen(ss[0]);
       KMP(7,0);
       sm=min(sm,d-match);
       KMP(0,7);
       sm=min(sm,d-match);


       KMP(1,0);
       l=strlen(ss[1]);
       l-=match;
       for(i=0;i<l;i++)
        ss[8][i]=ss[1][i];
       l=strlen(ss[0]);
       for(j=0;j<l;j++,i++)
        ss[8][i]=ss[0][j];
       ss[8][i]='\0';
        d=strlen(ss[8])+strlen(ss[2]);
       KMP(8,2);
       sm=min(sm,d-match);
       KMP(2,8);
       sm=min(sm,d-match);
   }
   pf("%d\n",sm);
    return 0;
}




