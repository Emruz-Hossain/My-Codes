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

string s1,s2;
int node;
map<string,int>mp;
map<int,string>name;
vector<int>E[200];
vector<int>graph[200],graph_rev[200],ans[200];
vector<int>v1,v2;
int visit[200],used[200];
void dfs(int rt)
{
    int i;
    if(visit[rt]==1)
        return;
    visit[rt]=1;
    for(i=0;i<graph[rt].size();i++)
    {
        if(visit[graph[rt][i]]==0&&used[graph[rt][i]]==0)
        {
              v1.push_back(graph[rt][i]);
              dfs(graph[rt][i]);
        }

    }
}
void dfs_rev(int rt)
{
    int i;
    if(visit[rt]==1)
        return;
    visit[rt]=1;
    for(i=0;i<graph_rev[rt].size();i++)
    {
        if(visit[graph_rev[rt][i]]==0&&used[graph_rev[rt][i]]==0)
        {
           v2.push_back(graph_rev[rt][i]);
           dfs(graph_rev[rt][i]);

        }
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   t=1;
   while(1)
   {
       mp.clear();
       read2(n,m);
       for(i=0;i<=n;i++)
       {
           E[i].clear();
           graph[i].clear();
           graph_rev[i].clear();
           ans[i].clear();
       }
       node=1;
       if(n+m==0)
         break;
        for(i=0;i<m;i++)
        {
            cin>>s1>>s2;
            if(mp[s1]==0)
            {
                mp[s1]=node;
                name[node]=s1;
                node++;
            }
            if(mp[s2]==0)
            {
                mp[s2]=node;
                name[node]=s2;
                node++;
            }
            graph[mp[s1]].push_back(mp[s2]);
            graph_rev[mp[s2]].push_back(mp[s1]);
        }
        int cycle=0;
        mem(used,0);
        for(i=1;i<node;i++)
        {
            if(used[i]==0)
            {
                ans[cycle].push_back(i);
                mem(visit,0);
                dfs(i);
                mem(visit,0);
                dfs_rev(i);
                for(j=0;j<v1.size();j++)
                {
                    for(k=0;k<v2.size();k++)
                    {
                        if(v1[j]==v2[k])
                        {
                            ans[cycle].push_back(v1[j]);
                            used[v1[j]]=1;
                            break;
                        }
                    }
                }
                v1.clear();
                v2.clear();
                cycle++;
                used[i]=1;
            }
        }
        if(t>1)
            pf("\n");
        pf("Calling circles for data set %d:\n",t++);
        for(i=0;i<cycle;i++)
        {
            for(j=0;j<ans[i].size();j++)
            {
                if(j>0)
                pf(", ");
                cout<<name[ans[i][j]];
            }
            pf("\n");
        }
   }
    return 0;
}




