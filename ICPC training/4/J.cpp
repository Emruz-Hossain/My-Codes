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
int weight[200];
void make_weight(int n)
{
    int tmp=n;
    int sm=0;
    while(n>0)
    {
        int d=n%2;
        n=n/2;
        if(d==1)
            sm+=500;
        else
            sm+=250;
    }
    weight[tmp]=sm;
}

int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   for(i='A';i<='Z';i++)
    make_weight(i);
   read(t);
   for(x=1;x<=t;x++)
   {
       string up_left[]={".../\\...|","../..\\..|","./....\\.|","/......\\|","\\______/|","........|","........|"};
       string up_right[]={"|.../\\...","|../..\\..","|./....\\.","|/......\\","|\\______/","|........","|........"};
       string down_left[]={"........|","........|",".../\\...|","../..\\..|","./....\\.|","/......\\|","\\______/|"};
       string down_right[]={"|........","|........","|.../\\...","|../..\\..","|./....\\.","|/......\\","|\\______/"};
       string equ_left[]={"........|",".../\\...|","../..\\..|","./....\\.|","/......\\|","\\______/|","........|"};
       string equ_right[]={"|........","|.../\\...","|../..\\..","|./....\\.","|/......\\","|\\______/","|........"};
       string ans[100];
       string ss[100];
       for(i=0;i<8;i++)
        cin>>ss[i];
        pf("Case %d:\n",x);
        vector<char>left_weight,right_weight;
        int left=0,right=0;
        int flag=0;
       for(i=0;i<7;i++)
       {
           for(j=0;j<ss[i].size();j++)
           {
               if(ss[i][j]>='A'&&ss[i][j]<='Z')
               {
                   if(j>10)
                   {
                       right+=weight[ss[i][j]];
                       right_weight.push_back(ss[i][j]);
                   }
                   else
                   {
                       left+=weight[ss[i][j]];
                       left_weight.push_back(ss[i][j]);
                   }
               }
           }
       }
       //pf("%d %d\n",left,right);
       if(left==right)
       {
           if(ss[5][1]=='_'&&ss[5][12]=='_')
           {
               pf("The figure is correct.\n");
               flag=1;
           }
          if(!flag)
          {
            for(i=0;i<left_weight.size();i++)
           {
               equ_left[4][i+1]=left_weight[i];
           }
           for(i=0;i<right_weight.size();i++)
           {
               equ_right[4][i+2]=right_weight[i];
           }
           for(i=0;i<7;i++)
            ans[i]=equ_left[i]+equ_right[i];
          }
       }
       else if(left<right)
       {
           if(ss[4][1]=='_'&&ss[6][13]=='_')
           {
                pf("The figure is correct.\n");
               flag=1;
           }
           if(!flag)
           {
            for(i=0;i<left_weight.size();i++)
           {
               up_left[3][i+1]=left_weight[i];
           }
           for(i=0;i<right_weight.size();i++)
           {
               down_right[5][i+2]=right_weight[i];
           }
           for(i=0;i<7;i++)
            ans[i]=up_left[i]+down_right[i];
           }
       }
       else
       {
          if(ss[6][1]=='_'&&ss[4][13]=='_')
           {
                pf("The figure is correct.\n");
               flag=1;
           }
           if(!flag)
           {
            for(i=0;i<left_weight.size();i++)
           {
               down_left[5][i+1]=left_weight[i];
           }
           for(i=0;i<right_weight.size();i++)
           {
               up_right[3][i+2]=right_weight[i];
           }
           for(i=0;i<7;i++)
            ans[i]=down_left[i]+up_right[i];
           }
       }
       if(!flag)
       {
             for(i=0;i<7;i++)
             cout<<ans[i]<<endl;
       }
       left_weight.clear();
       right_weight.clear();
   }

    return 0;
}




