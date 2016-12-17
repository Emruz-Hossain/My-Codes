/**************************************
 *    BISMILLAHIR RAHMANIR RAHIM      *
 *         MD: EMRUZ HOSSAIN          *
 *            CUET-CSE-12             *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ULL;

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
string Operand1,Operand2,Operator,Equal,Result,ans;
map<int,char>mp,base_character;
map<char,int>pm;
int sgn,op1sgn,op2sgn;
bool valid(int base)
{
    int i,extra=0;
    if(base==1)
        extra=1;
    for(i=0;i<Operand1.size();i++)
    {
       // cout<<Operand1[i]<<" "<<mp[base]<<endl;
        if(Operand1[i]>='0'+extra&&Operand1[i]<mp[base]+extra)
            continue;
        else
            return false;
    }
    for(i=0;i<Operand2.size();i++)
    {
        if(Operand2[i]>='0'+extra&&Operand2[i]<mp[base]+extra)
            continue;
        else
            return false;
    }
    for(i=0;i<Result.size();i++)
    {
        if(Result[i]>='0'+extra&&Result[i]<mp[base]+extra)
            continue;
        else
            return false;
    }
    return true;
}
bool is_Ok(int base)
{
    ll op1=0,op2=0,res=0,res2;
    int j,i;
    for(i=Operand1.size()-1,j=0;i>=0;i--,j++)
    {
        op1+=pm[Operand1[i]]*pow(base,j);
    }
    for(i=Operand2.size()-1,j=0;i>=0;i--,j++)
    {
        op2+=pm[Operand2[i]]*pow(base,j);
    }
     for(i=Result.size()-1,j=0;i>=0;i--,j++)
    {
        res+=pm[Result[i]]*pow(base,j);
    }
    if(op1sgn==1)
        op1*=(-1);
    if(op2sgn==1)
        op2*=(-1);
    if(sgn==1)
        res=res*(-1);
    if(Operator[0]=='+')
    {
        if(op1+op2==res)
            return true;
        else
            return false;
    }
    else if(Operator[0]=='-')
    {
        if(op1-op2==res)
         return true;
         else
            return false;
    }
    else if(Operator[0]=='*')
    {
        if(op1*op2==res)
         return true;
         else
            return false;
    }
    else if(Operator[0]=='/')
    {
        if(op1%op2)
            return false;
        if(op1/op2==res)
         return true;
         else
            return false;
    }
    return false;
}
int main()
{
    //    freopen("output.txt","w",stdout);
       // freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   for(i=0;i<=9;i++)
   {
       mp[i]=i+'0';
       pm[mp[i]]=i;
   }
   for(i=10;i<36;i++)
   {
       mp[i]='a'+i-10;
       pm[mp[i]]=i;
   }
   mp[36]='z'+1;
   pm[mp[36]]=36;
   for(i=1;i<=9;i++)
    base_character[i]=i+'0';
   for(i=10;i<=35;i++)
   {
       base_character[i]='a'+i-10;
   }
   base_character[36]='0';

   sf("%d",&t);
   while(t--)
   {
       cin>>Operand1>>Operator>>Operand2>>Equal>>Result;
       sgn=0;op1sgn=0;op2sgn=0;
       if(Operand1[0]=='-')
       {
           op1sgn=1;
           Operand1.erase(Operand1.begin());
       }
       if(Operand2[0]=='-')
       {
           op2sgn=1;
           Operand2.erase(Operand2.begin());
       }
       if(Result[0]=='-')
       {
           sgn=1;
           Result.erase(Result.begin());
       }
      // cout<<Operand1<<" "+Operator<<" "<<Operand2<<" = "<<Result<<endl;
       ans="";
       for(i=1;i<=36;i++)
       {
           if(valid(i))
           {
               if(is_Ok(i))
               {
                   ans+=base_character[i];
               }
           }
       }
       if(ans.size()==0)
        cout<<"invalid"<<endl;
       else
        cout<<ans<<endl;
   }


    return 0;
}




