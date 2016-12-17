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

int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   read(t);
   string ss;

   vector<int>hour,hour2,minute,minute2,second,second2;
   for(x=1;x<=t;x++)
   {
       ss.clear();
       cin>>ss;
      stack<char> Q;
       for(i=0;i<ss.size();)
       {
           if(ss[i]==')')
           {
               while(!Q.empty())
               {
                   char ch=Q.top();
                   Q.pop();
                   if(ch=='*')
                   {
                       hour.push_back(1);
                       Q.pop();
                   }
                   else
                    hour.push_back(0);
               }
           }
           else
            Q.push(ss[i]);
           ss.erase(ss.begin());
          // cout<<ss<<endl;
           if(hour.size()==2)
            break;
       }
        for(i=0;i<ss.size();i)
       {
           if(ss[i]==')')
           {
               while(!Q.empty())
               {
                   char ch=Q.top();
                   Q.pop();
                   if(ch=='*')
                   {
                       hour2.push_back(1);
                       Q.pop();
                   }
                   else
                    hour2.push_back(0);
               }
           }
           else
            Q.push(ss[i]);
           ss.erase(ss.begin());
           if(hour2.size()==4)
            break;
       }
    for(i=0;i<ss.size();i)
       {
           if(ss[i]==')')
           {
               while(!Q.empty())
               {
                   char ch=Q.top();
                   Q.pop();
                   if(ch=='*')
                   {
                       minute.push_back(1);
                       Q.pop();
                   }
                   else
                    minute.push_back(0);

               }
           }
           else
            Q.push(ss[i]);
           ss.erase(ss.begin());
           if(minute.size()==3)
            break;
       }
        for(i=0;i<ss.size();i)
       {
           if(ss[i]==')')
           {
               while(!Q.empty())
               {
                   char ch=Q.top();
                   Q.pop();
                   if(ch=='*')
                   {
                       minute2.push_back(1);
                       Q.pop();
                   }
                   else
                    minute2.push_back(0);

               }
           }
           else
            Q.push(ss[i]);
           ss.erase(ss.begin());
           if(minute2.size()==4)
            break;
       }
       for(i=0;i<ss.size();i)
       {
           if(ss[i]==')')
           {
               while(!Q.empty())
               {
                   char ch=Q.top();
                   Q.pop();
                   if(ch=='*')
                   {
                       second.push_back(1);
                       Q.pop();
                   }
                   else
                    second.push_back(0);

               }
           }
           else
            Q.push(ss[i]);
           ss.erase(ss.begin());
           if(second.size()==3)
            break;
       }
        for(i=0;i<ss.size();i)
       {
           if(ss[i]==')')
           {
               while(!Q.empty())
               {
                   char ch=Q.top();
                   Q.pop();
                   if(ch=='*')
                   {
                      second2.push_back(1);
                       Q.pop();
                   }
                   else
                   second2.push_back(0);

               }
           }
           else
            Q.push(ss[i]);
           ss.erase(ss.begin());
           if(second2.size()==4)
            break;
       }
       int h1=0,h2=0,m1=0,m2=0,s1=0,s2=0;
       //cout<<h1.size()<<endl;
       for(int i=hour.size()-1,j=0;i>=0;i--,j++)
       {
           h1+=hour[i]*pow(2,j);
       }
       //cout<<hour2.size()<<endl;
       for(int i=hour2.size()-1,j=0;i>=0;i--)
       {
           h2+=hour2[i]*pow(2,j);
           j++;
       }
       for(int i=minute.size()-1,j=0;i>=0;i--,j++)
       {
           m1+=minute[i]*pow(2,j);
       }
       for(int i=minute2.size()-1,j=0;i>=0;i--,j++)
       {
           m2+=minute2[i]*pow(2,j);
       }
       for(int i=second.size()-1,j=0;i>=0;i--,j++)
       {
           s1+=second[i]*pow(2,j);
       }
       for(int i=second2.size()-1,j=0;i>=0;i--,j++)
       {
           s2+=second2[i]*pow(2,j);
       }
       pf("Case %d: %d%d:%d%d:%d%d\n",x,h1,h2,m1,m2,s1,s2);
       hour.clear();hour2.clear();minute.clear(),minute2.clear();second2.clear();second.clear();

   }

    return 0;
}




