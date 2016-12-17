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
int visit[605][605],grid[605][605],citiesOf[2505][105],countCity,n,m,W[2501][2501];
int visit1[2505],Parent[2505];
struct st
{
    int u,v,w;
};
vector<st>Edge;
void identifyIland(int x,int y,int ilandNo)
{
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    citiesOf[ilandNo][grid[x][y]]=1;
    countCity++;
    int p,q;
    for(int i=0;i<4;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&p<n&&q>=0&&q<m&&visit[p][q]==0&&grid[p][q]>0)
            identifyIland(p,q,ilandNo);
    }
}
void tryWith(int mid,int idx,int cnt)
{
    if(visit1[idx]==1)
        return ;
    visit1[idx]=1;
    countCity++;
    int i;
    for(i=0;i<cnt;i++)
    {
        if(visit1[i]==0&&W[idx][i]<=mid)
            tryWith(mid,i,cnt);
    }
}
int findCost(int x,int y)
{
    int cost=100,i,j;
    for(i=1;i<=100;i++)
    {
        if(citiesOf[x][i]==1&&citiesOf[y][i]==1)
            return cost=0;
        else if(citiesOf[x][i]==1)
        {
            j=i+1;
            while(j<=100)
            {
                if(citiesOf[y][j]==1)
                {

                    cost=min(cost,abs(i-j));
                    break;
                }
                j++;
            }
            j=i-1;
            while(j>=1)
            {
                if(citiesOf[y][j]==1)
                {
                    cost=min(cost,abs(i-j));
                    break;
                }
                j--;
            }
        }
    }
    return cost;
}
bool cmp(st a , st b)
{
    return a.w<b.w;
}
int findParent(int u)
{
    if(Parent[u]==u)
        return u;
    else
        return Parent[u]=findParent(Parent[u]);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,u,v;

   sf("%d %d",&n,&m);
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
        sf("%d",&grid[i][j]);
   }
   mem(visit,0);
   cnt=0;
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           if(grid[i][j]>0&&visit[i][j]==0)
           {
               for(k=0;k<=100;k++)
                citiesOf[cnt][k]=0;
               countCity=0;
               identifyIland(i,j,cnt);
               if(countCity>=100)
                 cnt++;
           }
       }
   }
  // pf("Number of Iland= %d\n",cnt);
  if(cnt<=1)
  {
      pf("0 0\n");
      return 0;
  }
   for(i=0;i<cnt;i++)
   {
       for(j=i+1;j<cnt;j++)
       {
           sm=0;
           for(k=1;k<=100;k++)
           {
                if(citiesOf[i][k]==1||citiesOf[j][k]==1)
                    sm++;

           }
           W[i][j]=W[j][i]=sm;
           //pf("difference of %d and %d = %d\n",i,j,sm);
       }
   }
   l=0;h=205;
   int minCost=305;
   while(l<=h)
   {
       int mid=(l+h)/2;
       countCity=0;
       mem(visit1,0);
       tryWith(mid,0,cnt);
       if(countCity>=cnt)
       {
           minCost=min(minCost,mid);
           h=mid-1;
       }
       else
        l=mid+1;
   }
  // pf("minCost = %d\n",minCost);
   Edge.clear();
   for(i=0;i<cnt;i++)
   {
       for(j=i+1;j<cnt;j++)
       {
           if(W[i][j]<=minCost)
           {

           st aa;
           aa.u=i;
           aa.v=j;
           aa.w=findCost(i,j);
           Edge.push_back(aa);
          // pf("%d %d = %d\n",aa.u,aa.v,aa.w);
           }
       }
   }
   for(i=0;i<cnt;i++)
    Parent[i]=i;
  sort(Edge.begin(),Edge.end(),cmp);
  sm=0;
  for(i=0;i<Edge.size();i++)
  {
     u=findParent(Edge[i].u);
     v=findParent(Edge[i].v);
     if(u!=v)
     {
         if(u<v)
            Parent[u]=v;
         else
            Parent[v]=u;
         sm+=Edge[i].w;
     }
  }
  pf("%d %d\n",minCost*minCost,sm);
    return 0;
}
