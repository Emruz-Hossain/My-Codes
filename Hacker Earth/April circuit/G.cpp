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

int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%d",&t);
   while(t--)
   {
       sf("%d %d %d %d %d",&d,&b1,&b2,&b3,&b4);
       if(d==1)
       {
           pos[1]=2;
           lev[1]=b2;
           pf("%d %d\n",pos[1],lev[1]);
       }
       else if(d==2)
       {
           pos[1]=2;
           lev[1]=b2;
           pf("%d %d\n",pos[1],lev[1]);
       }
       else if(d==3)
       {
           pos[1]=3;
           lev[1]=b3;
           pf("%d %d\n",pos[1],lev[1]);
       }
       else
       {
           pos[1]=4;
           lev[1]=b4;
           pf("%d %d\n",pos[1],lev[1]);
       }
      //*********stage 2*********************
      sf("%d %d %d %d %d",&d,&b1,&b2,&b3,&b4);
       if(d==1)
       {
           if(b1==4)
            pos[2]=1;
           else if(b2==4)
            pos[2]=2;
           else if(b3==4)
            pos[2]=3;
           else
            pos[2]=4;
           lev[2]=4;
           pf("%d %d\n",pos[2],lev[2]);
       }
       else if(d==2)
       {
          if(pos[1]==1)
          {
              pos[2]=1;
              lev[2]=b1;
          }
          else if(pos[1]==2)
          {
              pos[2]=2;
              lev[2]=b2;
          }
          else if(pos[1]==3)
          {
              pos[2]=3;
              lev[2]=b3;
          }
          else
          {
             pos[2]=4;
             lev[2]=b4;
          }
           pf("%d %d\n",pos[2],lev[2]);
       }
       else if(d==3)
       {
           pos[2]=3;
           lev[2]=b3;
           pf("%d %d\n",pos[2],lev[2]);
       }
       else
       {
          if(pos[1]==1)
          {
              pos[2]=1;
              lev[2]=b1;
          }
          else if(pos[1]==2)
          {
              pos[2]=2;
              lev[2]=b2;
          }
          else if(pos[1]==3)
          {
              pos[2]=3;
              lev[2]=b3;
          }
          else
          {
             pos[2]=4;
             lev[2]=b4;
          }
           pf("%d %d\n",pos[2],lev[2]);

       }
       //*********stage 3*******************

         sf("%d %d %d %d %d",&d,&b1,&b2,&b3,&b4);
       if(d==1)
       {
         if(pos[2]==1)
          {
              pos[3]=1;
              lev[3]=b1;
          }
          else if(pos[2]==2)
          {
              pos[3]=2;
              lev[3]=b2;
          }
          else if(pos[2]==3)
          {
              pos[3]=3;
              lev[3]=b3;
          }
          else
          {
             pos[3]=4;
             lev[3]=b4;
          }
           pf("%d %d\n",pos[3],lev[3]);
       }
       else if(d==2)
       {
          if(pos[1]==1)
          {
              pos[3]=1;
              lev[3]=b1;
          }
          else if(pos[1]==2)
          {
              pos[3]=2;
              lev[3]=b2;
          }
          else if(pos[1]==3)
          {
              pos[3]=3;
              lev[3]=b3;
          }
          else
          {
             pos[3]=4;
             lev[3]=b4;
          }
           pf("%d %d\n",pos[3],lev[3]);
       }
       else if(d==3)
       {
           pos[3]=3;
           lev[3]=b3;
           pf("%d %d\n",pos[3],lev[3]);
       }
       else
       {
          if(b1==4)
            pos[3]=1;
           else if(b2==4)
            pos[3]=2;
           else if(b3==4)
            pos[3]=3;
           else
            pos[3]=4;
           lev[3]=4;
           pf("%d %d\n",pos[3],lev[3]);

       }
       //*************stage 4********************

       sf("%d %d %d %d %d",&d,&b1,&b2,&b3,&b4);
       if(d==1)
       {
         if(pos[1]==1)
          {
              pos[4]=1;
              lev[4]=b1;
          }
          else if(pos[1]==2)
          {
              pos[4]=2;
              lev[4]=b2;
          }
          else if(pos[1]==3)
          {
              pos[4]=3;
              lev[4]=b3;
          }
          else
          {
             pos[4]=4;
             lev[4]=b4;
          }
           pf("%d %d\n",pos[4],lev[4]);
       }
       else if(d==2)
       {
          pos[4]=2;
          lev[4]=b2;
           pf("%d %d\n",pos[4],lev[4]);
       }
       else if(d==3)
       {
           pos[3]=3;
           lev[3]=b3;
           pf("%d %d\n",pos[3],lev[3]);
       }
       else
       {
          if(b1==4)
            pos[3]=1;
           else if(b2==4)
            pos[3]=2;
           else if(b3==4)
            pos[3]=3;
           else
            pos[3]=4;
           lev[3]=4;
           pf("%d %d\n",pos[3],lev[3]);

       }
    return 0;
}




