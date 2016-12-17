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
#define     imax 2147483647
#define     lmax 9223372036854775807LL

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}
template <typename T> T BigMod (T b,T p,T m){if (p == 0)return 1;if (p%2 == 0){ll s = BigMod(b,p/2,m)%m;return (s*s)%m;}ll sm=((b%m)*(BigMod(b,p-1,m)%m))%m;return sm;}
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
    ll w,h,l,idx;
}ar[100005];
vector<ll>v,con1[300005],con2[300005],con3[300005];
ll bs(ll val)
{
    ll l=0,h=v.size()-1;
    while(l<=h)
    {
        ll mid=(l+h)/2;
        if(v[mid]==val)
            return mid;
        else if(v[mid]>val)
            h=mid-1;
        else
           l=mid+1;
    }
    return 0;
}
bool cmp1(ll a, ll b)
{
    if(ar[a].l==ar[b].l)
        return ar[a].h<ar[b].h;
    return ar[a].l<ar[b].l;
}
bool cmp2(ll a, ll b)
{
     if(ar[a].h==ar[b].h)
        return ar[a].w<ar[b].w;
    return ar[a].h<ar[b].h;
}
bool cmp3(ll a, ll b)
{
     if(ar[a].w==ar[b].w)
        return ar[a].l<ar[b].l;
    return ar[a].w<ar[b].w;
}
ll bs1(ll p,ll val)
{
    ll l=0,h=con1[p].size()-1,ans=-1;
    while(l<=h)
    {
        ll mid=(l+h)/2;
        if(ar[con1[p][mid]].l==val)
        {
            ans=mid;
            l=mid+1;
        }
        else if(ar[con1[p][mid]].l<val)
            l=mid+1;
        else
            h=mid-1;
    }
    return ans;
}
ll bs2(ll p,ll val)
{
    ll l=0,h=con2[p].size()-1,ans=-1;
    while(l<=h)
    {
        ll mid=(l+h)/2;
        if(ar[con2[p][mid]].h==val)
        {
            ans=mid;
            l=mid+1;
        }
        else if(ar[con2[p][mid]].h<val)
            l=mid+1;
        else
            h=mid-1;
    }
    return ans;
}
ll bs3(ll p,ll val)
{
    ll l=0,h=con3[p].size()-1,ans=-1;
    while(l<=h)
    {
        ll mid=(l+h)/2;
        if(ar[con3[p][mid]].h==val)
        {
            ans=mid;
            l=mid+1;
        }
        else if(ar[con3[p][mid]].h<val)
            l=mid+1;
        else
            h=mid-1;
    }
    return ans;
}
int main()
{
    //    freopen("output.txt","w",stdout);
       freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,sm1,sm2,id1,id21,id22;
   sf("%lld",&n);
   vector<ll>tmp;
   for(i=0;i<n;i++)
   {
    sf("%lld %lld %lld",&ar[i].w,&ar[i].l,&ar[i].h);
    ar[i].idx=i;
    tmp.push_back(ar[i].w);
    tmp.push_back(ar[i].l);
    tmp.push_back(ar[i].h);

   }
   sort(tmp.begin(),tmp.end());
   for(i=0;i<tmp.size();i++)
   {
       if(v.size()==0||v.back()!=tmp[i])
        v.push_back(tmp[i]);
   }
   sm1=0;
   id1=-1;
   for(i=0;i<n;i++)
   {
       d=min(ar[i].w,min(ar[i].l,ar[i].h));
       if(d>sm1)
       {
           sm1=d;
           id1=i;
       }
   }
   for(i=0;i<n;i++)
   {
       con1[bs(ar[i].w)].push_back(i);
       con2[bs(ar[i].l)].push_back(i);
       con3[bs(ar[i].h)].push_back(i);

   }
   for(i=0;i<n;i++)
   {
       p=bs(ar[i].w);
   sort(con1[p].begin(),con1[p].end(),cmp1);
   p=bs(ar[i].l);
   sort(con2[p].begin(),con2[p].end(),cmp2);
   p=bs(ar[i].w);
   sort(con3[p].begin(),con3[p].end(),cmp3);
   }
   sm2=0;
   id21=-1;
   id22=-1;
   for(i=0;i<n;i++)
   {
       p=bs(ar[i].w);
       q=bs1(p,ar[i].l);
       if(q!=-1)
       {
           if(con1[p][q]==i&&q>0&&ar[con1[p][q-1]].l==ar[i].l)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {

            d=min(ar[i].w,min(ar[i].l,ar[i].h+ar[con1[p][q]].h));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con1[p][q];
            }
           }

       }
       q=bs2(p,ar[i].l);
       if(q!=-1)
       {
           if(con2[p][q]==i&&q>0&&ar[con2[p][q-1]].h==ar[i].l)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {

            d=min(ar[i].w,min(ar[i].l,ar[i].h+ar[con2[p][q]].w));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con2[p][q];
            }
           }

       }
       q=bs3(p,ar[i].l);
       if(q!=-1)
       {
           if(con3[p][q]==i&&q>0&&ar[con3[p][q-1]].w==ar[i].l)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {

            d=min(ar[i].w,min(ar[i].l,ar[i].h+ar[con3[p][q]].l));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con3[p][q];
            }
           }

       }

       //********************
       p=bs(ar[i].l);
       q=bs1(p,ar[i].h);
       if(q!=-1)
       {
           if(con1[p][q]==i&&q>0&&ar[con1[p][q-1]].l==ar[i].h)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {

            d=min(ar[i].l,min(ar[i].h,ar[i].w+ar[con1[p][q]].h));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con1[p][q];
            }
           }

       }
       q=bs2(p,ar[i].h);
       if(q!=-1)
       {
           if(con2[p][q]==i&&q>0&&ar[con2[p][q-1]].h==ar[i].h)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {

            d=min(ar[i].h,min(ar[i].l,ar[i].w+ar[con2[p][q]].w));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con2[p][q];
            }

           }
       }
       q=bs3(p,ar[i].h);
       if(q!=-1)
       {
           if(con3[p][q]==i&&q>0&&ar[con3[p][q-1]].w==ar[i].h)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {

            d=min(ar[i].h,min(ar[i].l,ar[i].w+ar[con3[p][q]].l));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con3[p][q];
            }
           }

       }
       //********************
        p=bs(ar[i].w);
       q=bs1(p,ar[i].h);
       if(q!=-1)
       {
           if(con1[p][q]==i&&q>0&&ar[con1[p][q-1]].l==ar[i].h)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {
            d=min(ar[i].w,min(ar[i].h,ar[i].l+ar[con1[p][q]].h));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con1[p][q];
            }

           }

       }
       q=bs2(p,ar[i].h);
       if(q!=-1)
       {
           if(con2[p][q]==i&&q>0&&ar[con2[p][q-1]].h==ar[i].h)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {

            d=min(ar[i].w,min(ar[i].h,ar[i].l+ar[con2[p][q]].w));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con2[p][q];
            }

           }
       }
       q=bs3(p,ar[i].h);
       if(q!=-1)
       {
           if(con3[p][q]==i&&q>0&&ar[con3[p][q-1]].h==ar[i].w)
           {
               q--;
           }
           if(con1[p][q]!=i)
           {

            d=min(ar[i].w,min(ar[i].h,ar[i].l+ar[con3[p][q]].l));
            if(sm2<d)
            {
                sm2=d;
                id21=i;
                id22=con3[p][q];
            }

           }
       }
   }
   pf("%d %d\n",sm1,sm2);
   if(sm1>=sm2)
   {
       pf("1\n%d\n",id1+1);
   }
   else
   {
       pf("2\n%d %d\n",id21+1,id22+1);
   }

    return 0;
}

