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
#define     PI   2.0*acos(0.0)

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}

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

ll  mod1=1000000009,mod2=1000000007;
ll lp1=66047,lp2=999983;
ll BigMod(ll b,ll p,ll m)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll sm=BigMod(b,p/2,m);
        sm=((sm%m)*(sm%m))%m;
        return sm;
    }
    else
    {
        ll sm=BigMod(b,p-1,m);
        sm=((sm%m)*(b%m))%m;
        return sm;
    }
}
string ss;
vector<ll>Hash_value1,Hash_value2;
long long process1(void)
{
   ll sm=0;
   ll l=ss.size(),i;
    for(i=0;i<l;i++)
    {
       ll t=BigMod(lp1,l-i-1,mod1);
       ll tmp=((t%mod1)*(ss[i]%mod1))%mod1;
       sm=((sm%mod1)+(tmp%mod1))%mod1;
    }
    return sm;
}
long long process2(void)
{
   ll sm=0;
   ll l=ss.size(),i;
    for(i=0;i<l;i++)
    {
       ll t=BigMod(lp2,l-i-1,mod2);
       ll tmp=((t%mod2)*(ss[i]%mod2))%mod2;
       sm=((sm%mod2)+(tmp%mod2))%mod2;
    }
    return sm;
}
int bs1(long long val)
{
    int l=0,h=Hash_value1.size()-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(Hash_value1[mid]==val)
            return mid;
        else if(Hash_value1[mid]<val)
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}
int bs2(long long val)
{
    int l=0,h=Hash_value2.size()-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(Hash_value2[mid]==val)
            return mid;
        else if(Hash_value2[mid]<val)
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,x,y,i,j,k,q,r,t,cnt,d1,d2;
  ll sm1,sm2,p1,p2,tmp1,tmp2;
   read2(n,m);
   for(i=0;i<n;i++)
   {
       cin>>ss;
       Hash_value1.push_back(process1());
       Hash_value2.push_back(process2());
   }
   sort(Hash_value1.begin(),Hash_value1.end());
   sort(Hash_value2.begin(),Hash_value2.end());
   for(j=0;j<m;j++)
   {
       cin>>ss;
       ll l=ss.size();
       sm1=process1();
       sm2=process2();
       int flag=0;
       for(i=0;i<l;i++)
       {
           if(ss[i]=='a')
           {
               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('a'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('a'%mod2)*(tmp2%mod2))%mod2;
               p1=(sm1-tmp1)%mod1;
               p1=(p1+mod1)%mod1;
               p2=(sm2-tmp2)%mod2;
               p2=(p2+mod2)%mod2;
               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('b'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('b'%mod2)*(tmp2%mod2))%mod2;
               p1=(p1+tmp1)%mod1;
               p2=(p2+tmp2)%mod2;
               d1=bs1(p1);
               d2=bs2(p2);
               if(d1!=-1&&d2!=-1)
               {
                   flag=1;
                   break;
               }


               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('a'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('a'%mod2)*(tmp2%mod2))%mod2;
               p1=(sm1-tmp1)%mod1;
               p1=(p1+mod1)%mod1;
               p2=(sm2-tmp2)%mod2;
               p2=(p2+mod2)%mod2;
               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('c'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('c'%mod2)*(tmp2%mod2))%mod2;
               p1=(p1+tmp1)%mod1;
               p2=(p2+tmp2)%mod2;
               d1=bs1(p1);
               d2=bs2(p2);
               if(d1!=-1&&d2!=-1)
               {
                   flag=1;
                   break;
               }
           }
           else if(ss[i]=='b')
           {
                tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('b'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('b'%mod2)*(tmp2%mod2))%mod2;
               p1=(sm1-tmp1)%mod1;
               p1=(p1+mod1)%mod1;
               p2=(sm2-tmp2)%mod2;
               p2=(p2+mod2)%mod2;
               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('a'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('a'%mod2)*(tmp2%mod2))%mod2;
               p1=(p1+tmp1)%mod1;
               p2=(p2+tmp2)%mod2;
               d1=bs1(p1);
               d2=bs2(p2);
               if(d1!=-1&&d2!=-1)
               {
                   flag=1;
                   break;
               }


               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('b'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('b'%mod2)*(tmp2%mod2))%mod2;
               p1=(sm1-tmp1)%mod1;
               p1=(p1+mod1)%mod1;
               p2=(sm2-tmp2)%mod2;
               p2=(p2+mod2)%mod2;
               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('c'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('c'%mod2)*(tmp2%mod2))%mod2;
               p1=(p1+tmp1)%mod1;
               p2=(p2+tmp2)%mod2;
               d1=bs1(p1);
               d2=bs2(p2);
               if(d1!=-1&&d2!=-1)
               {
                   flag=1;
                   break;
               }
           }
           else
           {

               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('c'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('c'%mod2)*(tmp2%mod2))%mod2;
               p1=(sm1-tmp1)%mod1;
               p1=(p1+mod1)%mod1;
               p2=(sm2-tmp2)%mod2;
               p2=(p2+mod2)%mod2;
               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('b'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('b'%mod2)*(tmp2%mod2))%mod2;
               p1=(p1+tmp1)%mod1;
               p2=(p2+tmp2)%mod2;
               d1=bs1(p1);
               d2=bs2(p2);
               if(d1!=-1&&d2!=-1)
               {
                   flag=1;
                   break;
               }


               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('c'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('c'%mod2)*(tmp2%mod2))%mod2;
               p1=(sm1-tmp1)%mod1;
               p1=(p1+mod1)%mod1;
               p2=(sm2-tmp2)%mod2;
               p2=(p2+mod2)%mod2;
               tmp1=BigMod(lp1,l-i-1,mod1);
               tmp1=(('a'%mod1)*(tmp1%mod1))%mod1;
               tmp2=BigMod(lp2,l-i-1,mod2);
               tmp2=(('a'%mod2)*(tmp2%mod2))%mod2;
               p1=(p1+tmp1)%mod1;
               p2=(p2+tmp2)%mod2;
               d1=bs1(p1);
               d2=bs2(p2);
               if(d1!=-1&&d2!=-1)
               {
                   flag=1;
                   break;
               }
           }

       }
       if(flag)
        pf("YES\n");
       else
        pf("NO\n");
   }

    return 0;
}
//1 5
//acbacbacb
//acbaabacb



