/**************************************
 *     BISMILLAHIR RAHMANIR RAHIM     *
 *        MD: EMRUZ HOSSAIN           *
 *           CUET-CSE-12              *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
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
#define     imax 2147483647
#define     lmax 9223372036854775807LL

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
int forbidden[100005],ans[100005],n,visit[100005];
struct st
{
    int val,mx,mn;
};
st EvenTree[4*100005],OddTree[4*100005];

void build(int rt, int beg,int endd)
{
    OddTree[rt].val=0;
    OddTree[rt].mn=n+5;
    OddTree[rt].mx=-1;

    EvenTree[rt].val=0;
    EvenTree[rt].mn=n+5;
    EvenTree[rt].mx=-1;

    if(beg==endd)
    {
        if(forbidden[beg]==0)
        {
            if(beg%2)
            {
                OddTree[rt].val=1;
                OddTree[rt].mn=OddTree[rt].mx=beg;

            }
            else
            {
                EvenTree[rt].val=1;
                EvenTree[rt].mn=EvenTree[rt].mx=beg;

            }
        }
        return;
    }
    int mid=(beg+endd)/2;
    build(2*rt,beg,mid);
    build(2*rt+1,mid+1,endd);
    OddTree[rt].val=OddTree[2*rt].val+OddTree[2*rt+1].val;
    OddTree[rt].mn=min(OddTree[2*rt].mn,OddTree[2*rt+1].mn);
    OddTree[rt].mx=max(OddTree[2*rt].mx,OddTree[2*rt+1].mx);

    EvenTree[rt].val=EvenTree[2*rt].val+EvenTree[2*rt+1].val;
    EvenTree[rt].mn=min(EvenTree[2*rt].mn,EvenTree[2*rt+1].mn);
    EvenTree[rt].mx=max(EvenTree[2*rt].mx,EvenTree[2*rt+1].mx);
}
st QueryOnOddTree(int rt,int beg,int endd,int l,int r)
{
    st aa,bb;
    if(beg>r||endd<l||OddTree[rt].val==0)
    {
        aa.mn=n+5;
        aa.mx=-1;
        return aa;
    }
    if(beg>=l&&endd<=r)
        return OddTree[rt];
    int mid=(beg+endd)/2;
    aa=QueryOnOddTree(2*rt,beg,mid,l,r);
    bb=QueryOnOddTree(2*rt+1,mid+1,endd,l,r);
    aa.mn=min(aa.mn,bb.mn);
    aa.mx=max(aa.mx,bb.mx);
    return aa;
}
st QueryOnEvenTree(int rt,int beg,int endd,int l,int r)
{
    st aa,bb;
    if(beg>r||endd<l||EvenTree[rt].val==0)
    {
        aa.mn=n+5;
        aa.mx=-1;
        return aa;
    }
    if(beg>=l&&endd<=r)
        return EvenTree[rt];
    int mid=(beg+endd)/2;
    aa=QueryOnEvenTree(2*rt,beg,mid,l,r);
    bb=QueryOnEvenTree(2*rt+1,mid+1,endd,l,r);
    aa.mn=min(aa.mn,bb.mn);
    aa.mx=max(aa.mx,bb.mx);
    return aa;
}
void update(int rt,int beg,int endd,int idx,int type)
{
    if(beg==endd&&beg==idx)
    {
        if(type==1)
        {
            OddTree[rt].val=0;
            OddTree[rt].mn=n+5;
            OddTree[rt].mx=-1;
        }
        else
        {
            EvenTree[rt].val=0;
            EvenTree[rt].mn=n+5;
            EvenTree[rt].mx=-1;
        }
        return;
    }
    if(beg>idx||endd<idx)
        return;
    int mid=(beg+endd)/2;
    if(idx<=mid)
        update(2*rt,beg,mid,idx,type);
    else
        update(2*rt+1,mid+1,endd,idx,type);

    OddTree[rt].val=OddTree[2*rt].val+OddTree[2*rt+1].val;
    OddTree[rt].mn=min(OddTree[2*rt].mn,OddTree[2*rt+1].mn);
    OddTree[rt].mx=max(OddTree[2*rt].mx,OddTree[2*rt+1].mx);

    EvenTree[rt].val=EvenTree[2*rt].val+EvenTree[2*rt+1].val;
    EvenTree[rt].mn=min(EvenTree[2*rt].mn,EvenTree[2*rt+1].mn);
    EvenTree[rt].mx=max(EvenTree[2*rt].mx,EvenTree[2*rt+1].mx);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,s;
   sf("%d %d %d %d",&n,&k,&m,&s);
   mem(forbidden,0);
   mem(visit,0);
   for(i=0;i<m;i++)
   {
       sf("%d",&p);
       forbidden[p]=1;
   }
   mem(ans,-1);
   ans[s]=0;
   queue<int>Q;
   Q.push(s);
   build(1,1,n);
  // pf("build complete\n");
   visit[s]=1;
   update(1,1,n,s,s%2);
   int ml,mr;
   vector<int>tmp;
   while(!Q.empty())
   {
       p=Q.front();
       Q.pop();
       l=max(1,p-k+1);
       r=min(n,p+k-1);
       ml=2*l+k-p-1;
       mr=2*r-k-p+1;

       if((k%2==0&&p%2==0)||(k%2==1&&p%2==1))
       {
          // pf("Odd Query1 started with %d %d\n",ll,rr);
           st aa=QueryOnOddTree(1,1,n,ml,min(mr,p-1));
          // pf("Odd Query1 Complete\n");
           q=aa.mx;
           tmp.clear();
           while(q>=ml)
           {
               if(visit[q]==1)
                ;
               else
               {
                   if(forbidden[q]==0)
                   {
                       visit[q]=1;
                       ans[q]=ans[p]+1;
                       tmp.push_back(q);
                       update(1,1,n,q,1);
                   }
               }
               q-=2;
           }
           for(i=tmp.size()-1;i>=0;i--)
            Q.push(tmp[i]);

           //pf("Odd Query2 started with %d %d\n",ll,rr);

           aa=QueryOnOddTree(1,1,n,max(p+1,ml),mr);
          // pf("Odd Query2 Complete\n");
           q=aa.mn;
           tmp.clear();
           while(q<=mr)
           {
               if(visit[q]==1)
               ;
               else
               {
                   if(forbidden[q]==0)
                   {
                       visit[q]=1;
                       tmp.push_back(q);
                       ans[q]=ans[p]+1;
                       update(1,1,n,q,1);
                   }
               }
               q+=2;
           }
           for(i=tmp.size()-1;i>=0;i--)
            Q.push(tmp[i]);

       }
       else
       {
           //pf("Even Query1 started with %d %d\n",ll,rr);
           st aa=QueryOnEvenTree(1,1,n,ml,min(mr,p-1));
           //pf("Even Query1 Complete\n");
           q=aa.mx;
           //pf("%d\n",q);
           tmp.clear();
           while(q>=ml)
           {
               if(visit[q]==1)
                ;
               else
               {
                   if(forbidden[q]==0)
                   {
                       visit[q]=1;
                      tmp.push_back(q);
                       ans[q]=ans[p]+1;
                       update(1,1,n,q,0);
                   }
               }
               q-=2;
           }
           for(i=tmp.size()-1;i>=0;i--)
            Q.push(tmp[i]);
          // pf("Even Query2 started with %d %d\n",ll,rr);
           aa=QueryOnEvenTree(1,1,n,max(p+1,ml),mr);
           //pf("Even Query2 Complete\n");
           q=aa.mn;
           //pf("%d %d\n",q,rr);
           tmp.clear();
           while(q<=mr)
           {
               if(visit[q]==1)
                ;
               else
               {
                   if(forbidden[q]==0)
                   {
                       visit[q]=1;
                      tmp.push_back(q);
                       ans[q]=ans[p]+1;
                       //pf("Update called\n");
                       update(1,1,n,q,0);
                      // pf("Update complete\n");
                   }
               }
               q+=2;
           }
           for(i=tmp.size()-1;i>=0;i--)
            Q.push(tmp[i]);

       }
   }
   for(i=1;i<=n;i++)
   {
       if(i>1)
        pf(" ");
       pf("%d",ans[i]);
   }
   pf("\n");

    return 0;
}

