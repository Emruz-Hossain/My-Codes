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
vector<int>Edge[400005];
int ans[400005],h,n,child_side[400005],greater_than_h[400005];
int sub_tree[400005],max_id[400005],side_id[400005];
int dfs(int u,int parent)
{
    int i,v;
    sub_tree[u]=1;
    child_side[u]=0;//contain maximum size of subtree that can be remove from subtree of u.
    int max_sub_tree=-1;
    for(i=0;i<Edge[u].size();i++)
    {
        v=Edge[u][i];
        if(v==parent)
            continue;
        int sub=dfs(v,u);
        if(sub>h)
        {
            max_id[u]=v;
            max_sub_tree=sub;
            greater_than_h[u]++;
        }
        if(sub<=h)
        {
            if(sub>max_sub_tree)
            {
                max_sub_tree=sub;
                max_id[u]=v;
            }
            if(child_side[u]<sub)
            {
                child_side[u]=sub;
                side_id[u]=v;//for identifying which node is taken for remove.
            }
        }
        else
        {
            if(child_side[u]<=child_side[v])
            {
                child_side[u]=child_side[v];
                side_id[u]=v;
            }
        }
        sub_tree[u]+=sub;
    }
    return sub_tree[u];
}
void dfs2(int u,int parent,int parent_side)
{
    int parent_subtree_size=n-sub_tree[u];
    int max_len,tmxl=parent_side;
    if(parent_subtree_size<=h)
        tmxl=max(tmxl,parent_subtree_size);
    if(parent_subtree_size>h)
    {
        greater_than_h[u]++;
        max_len=parent_subtree_size;
    }
    else
    {
        max_len=sub_tree[max_id[u]];
    }
    if(greater_than_h[u]==0)
        ans[u]=1;
    else if(greater_than_h[u]>1)
        ans[u]=0;
    else
    {
        if(max_len==parent_subtree_size)
        {
            if(max_len-tmxl<=h)
                ans[u]=1;
            else
                ans[u]=0;
        }
        else
        {
            if(max_len-child_side[max_id[u]]<=h)
                ans[u]=1;
            else
                ans[u]=0;
        }
    }
    int mxl=tmxl;
    for(int i=0;i<Edge[u].size();i++)
    {
        int v=Edge[u][i];
        if(v==parent)
            continue;
        if(side_id[u]!=v)//if removing subtree does not come from v.
        {
          if(mxl<=h)
          dfs2(v,u,max(mxl,child_side[u]));
          else
            dfs2(u,v,child_side[u]);
        }
        else // if removing subtree comes from v then we must re-calculate it from other child.
        {
            int bmxl=0;
            if(mxl<=h)
                bmxl=mxl;
            for(int j=0;j<Edge[u].size();j++)
            {
                int k=Edge[u][j];
                if(k!=v&&k!=parent)
                {
                    if(sub_tree[k]<=h)
                        bmxl=max(bmxl,sub_tree[k]);
                    else
                        bmxl=max(bmxl,child_side[k]);
                }
            }
            dfs2(v,u,bmxl);
        }
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
      //  freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,u,v;
   sf("%d",&n);
   h=n/2;
   for(i=0;i<n-1;i++)
   {
       sf("%d %d",&u,&v);
       Edge[u].push_back(v);
       Edge[v].push_back(u);
   }
   mem(greater_than_h,0);
   mem(max_id,-1);
   dfs(1,0);// calculate child subtree.
   dfs2(1,0,0); //calculate parent subtree and final ans.
   for(i=1;i<=n;i++)
   {
       if(i>1)
        pf(" ");
       pf("%d",ans[i]);
   }
   pf("\n");

    return 0;
}


