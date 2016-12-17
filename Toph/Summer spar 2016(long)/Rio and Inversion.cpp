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
struct st
{
    int u,v,q,ans,box;

};
int n,BIT[10004][105],ar[10004];
vector<st>type1,type2;
st answer[10004];
void update(int x,int y,int val)
{
    if(x<=0)
        return;
    while(x<=n)
    {
        int idx=y;
        while(idx<=101)
        {
            BIT[x][idx]+=val;
            idx+=idx&(-idx);
        }
        x+=x&(-x);
    }
}
int query(int x,int y)
{
    int sm=0;
    if(x<=0)
        return sm;
    while(x>=1)
    {
        int idx=y;
        while(idx>=1)
        {
            sm+=BIT[x][idx];
            idx-=idx&(-idx);
        }
        x-=x&(-x);
    }
    return sm;
}
bool cmp( st a, st b)
{
    return a.q<b.q;
}
bool cmp2(st a, st b)
{
    if(a.box==b.box)
        return a.u<b.u;
    else
        return a.box<b.box;
}
int curInversion;
void Add(int idx)
{
    curInversion-=query(idx-1,101)-query(idx-1,ar[idx])+query(n,ar[idx]-1)-query(idx,ar[idx]-1);
    update(idx,ar[idx],-1);
}
void Remove(int idx)
{
    update(idx,ar[idx],1);
    curInversion+=query(idx-1,101)-query(idx-1,ar[idx])+query(n,ar[idx]-1)-query(idx,ar[idx]-1);
}
int main()
{
    //    freopen("output.txt","w",stdout);
       // freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,u,v;
   sf("%d",&n);
   d=sqrt(n)+1;
   mem(BIT,0);
   for(i=1;i<=n;i++)
   {
       sf("%d",&p);
       p++;
       ar[i]=p;
       update(i,p,1);
   }
   int totalInversion=0;
   for(i=1;i<=n;i++)
   {
       p=query(i-1,101)-query(i-1,ar[i]);
     //  pf("%d ",p);
       totalInversion+=p;
   }
   sf("%d",&q);
   for(i=0;i<q;i++)
   {
       sf("%d %d %d",&t,&u,&v);
       if(u>v)
        swap(u,v);
       st aa;
       aa.u=u+1;
       aa.v=v+1;
       aa.q=i;
       if(t==0)
        type1.push_back(aa);
       else
       {
         aa.box=v/d;
        type2.push_back(aa);
       }

   }
   for(i=0;i<type1.size();i++)
   {
       int sm=0;
       u=type1[i].u;
       v=type1[i].v;
       sm-=query(u-1,101)-query(u-1,ar[u])+query(n,ar[u]-1)-query(u,ar[u]-1);
      // update(u,ar[u],-1);
       sm-=query(v-1,101)-query(v-1,ar[v])+query(n,ar[v]-1)-query(v,ar[v]-1);
      // update(v,ar[v],-1);
      if(ar[u]>ar[v])
        sm++;
      // update(u,ar[v],1);
       sm+=query(u-1,101)-query(u-1,ar[v])+query(n,ar[v]-1)-query(u,ar[v]-1);
      // update(v,ar[u],1);
       sm+=query(v-1,101)-query(v-1,ar[u])+query(n,ar[u]-1)-query(v,ar[u]-1);
       if(ar[u]<ar[v])
       sm++;
       answer[i].ans=totalInversion+sm;
       answer[i].q=type1[i].q;

     //  update(u,ar[v],-1);
      // update(v,ar[u],-1);
      // update(u,ar[u],1);
     //  update(v,ar[v],1);
   }

   sort(type2.begin(),type2.end(),cmp2);
   curInversion=totalInversion;
   int curL=0,curR=0;
   for(i=0;i<type2.size();i++)
   {
       u=type2[i].u;
       v=type2[i].v;
       while(curR+1<=v)
       {
           Add(curR+1);
           curR++;
       }
       while(curR>v)
       {
           Remove(curR);
           curR--;
       }
       while(curL<u)
       {
           Remove(curL);
           curL++;
       }
       while(curL-1>=u)
       {
           Add(curL-1);
           curL--;
       }
       answer[type1.size()+i].ans=curInversion;
       answer[type1.size()+i].q=type2[i].q;

   }

   sort(answer,answer+q,cmp);
   for(i=0;i<q;i++)
   {
       pf("%d\n",answer[i].ans);
   }
    return 0;
}



