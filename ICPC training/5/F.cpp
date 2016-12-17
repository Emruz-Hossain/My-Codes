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
struct st
{
    int val,idx,actual_idx;
};
vector<st>ar,br;
struct st2
{
    int pos1,pos2,point;
};
vector<st2>v;
bool cmp2(st2 a,st2 b)
{
    return a.point>b.point;
}
bool cmp(st a,st b)
{
    return a.val<=b.val;
}
vector<st2>ans[1005];
int visit[1005];
void SORT(void)
{
    int i,j,tmp;
    for(i=0;i<br.size();i++)
    {
        tmp=i;
        for(j=i+1;j<br.size();j++)
        {
            if(br[j].val<br[tmp].val||(br[j].val==br[tmp].val&&tmp!=i))
                tmp=j;
        }
        if(tmp!=i)
            swap(br[i],br[tmp]);
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   read(n);
   for(i=0;i<n;i++)
   {
       read(p);
       st a;
       a.idx=i;
       a.val=p;
       ar.push_back(a);
       br.push_back(a);
   }
  SORT();
   for(i=0;i<br.size();i++)
   {
       ar[br[i].idx].actual_idx=i;
   }
   d=1;
   int step=0;
   while(d)
   {
       d=0;
      // pf("---------------\n");
       for(i=0;i<n;i++)
       {
           //pf("%d %d\n",ar[i].idx,ar[i].actual_idx);
           if(ar[i].idx!=ar[i].actual_idx)
           {
               st2 aa;
               aa.pos1=i;
               aa.pos2=ar[i].actual_idx;
               q=ar[ar[i].actual_idx].actual_idx;
               if(q==i)
                aa.point=2;
               else
                aa.point=1;
               v.push_back(aa);
           }
       }
       sort(v.begin(),v.end(),cmp2);
       mem(visit,0);
       for(i=0;i<v.size();i++)
       {
           st2 a=v[i];
           if(visit[a.pos1]==0&&visit[a.pos2]==0)
           {
               if(d==0)
                step++;
               st2 aa;
               aa.pos1=a.pos1;
               aa.pos2=a.pos2;
               visit[a.pos1]=1;
               visit[a.pos2]=1;
               swap(ar[a.pos1],ar[a.pos2]);
               ar[a.pos2].idx=ar[a.pos2].actual_idx;
               if(a.point==2)
               ar[a.pos1].idx=ar[a.pos1].actual_idx;
               else
                ar[a.pos1].idx=a.pos2;
               ans[step].push_back(aa);
               d=1;
           }
       }
       v.clear();
   }
   pf("%d\n",step);
   if(step>0)
   {
       for(i=1;i<=step;i++)
       {
           if(i>1)
              pf("\n");
           pf("%d",ans[i].size());
           for(j=0;j<ans[i].size();j++)
           {
               pf(" %d %d",ans[i][j].pos1+1,ans[i][j].pos2+1);
           }
           pf("\n");
       }
   }
    return 0;
}




