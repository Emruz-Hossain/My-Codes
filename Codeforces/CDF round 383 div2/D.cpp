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
const int sz=1005;
int n,m,w,cnt,Beauty[sz],Weight[sz],visit[sz];
ll GB[sz],GW[sz],dp[sz][sz];
vector<int>Edge[sz],Group[sz];
vector<int> find_group(int u)
{
    vector<int>members,tmp;
    int i,j,v;
    members.clear();
    if(visit[u]!=0)
        return members;
    visit[u]=1;
    for(i=0;i<Edge[u].size();i++)
    {
        v=Edge[u][i];
        if(visit[v]==0)
        {
            tmp=find_group(v);
            for(j=0;j<tmp.size();j++)
                members.push_back(tmp[j]);
        }
    }
    members.push_back(u);
    return members;
}
ll rec(int cur,int rem)
{
    int i,u;
    if(cur>=cnt||rem<=0)
        return 0;
    ll &ret=dp[cur][rem];
    if(ret!=-1)
        return ret;
    ret=0;
    if(rem>=GW[cur])
        ret=rec(cur+1,rem-GW[cur])+GB[cur];
    for(i=0;i<Group[cur].size();i++)
    {
        u=Group[cur][i];
        if(rem>=Weight[u])
            ret=max(ret,rec(cur+1,rem-Weight[u])+Beauty[u]);
    }
    ret=max(ret,rec(cur+1,rem));
    return ret;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,u,v,d,h,p,x,y,i,j,k,l,q,r,t,sm,tmp;
   sf("%d %d %d",&n,&m,&w);
    for(i=1;i<=n;i++)
        sf("%d",&Weight[i]);
    for(i=1;i<=n;i++)
        sf("%d",&Beauty[i]);
    for(i=1;i<=m;i++)
    {
        sf("%d %d",&u,&v);
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
    mem(visit,0);
    cnt=0;
    for(i=1;i<=n;i++)
    {
        if(visit[i]==0)
            Group[cnt++]=find_group(i);
    }
    ll gw,gb;
    for(i=0;i<cnt;i++)
    {
        gw=0;
        gb=0;
        for(j=0;j<Group[i].size();j++)
        {
            u=Group[i][j];
            gw+=Weight[u];
            gb+=Beauty[u];
            //pf("%d ",u);
        }
        //pf("\n");
        GW[i]=gw;
        GB[i]=gb;
    }
    mem(dp,-1);
    pf("%lld\n",rec(0,w));
    return 0;
}

