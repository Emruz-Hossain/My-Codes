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

#define     getx() getchar()
//#define     getx() getchar_unlocked()
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


 struct st
 {
     int L,R,id,block;
     ll ans;
 }Q[300005];
ll ar[300005],visit[1000006];
ll ans;

bool cmp1(st a,st b)
{
    if(a.block==b.block)
        return a.R<b.R;
    return a.block<b.block;
}
bool cmp2(st a,st b)
{
    return a.id<b.id;
}
void Add(int pos)
{
    ll d=visit[ar[pos]];
    ans+=ar[pos]*(2*d+1);
    visit[ar[pos]]++;
}
void Remove(int pos)
{
   ll d=visit[ar[pos]];
    ans+=ar[pos]*(1-2*d);
    visit[ar[pos]]--;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    readfast(n);
    readfast(q);
    ans=0;
    for(i=1;i<=n;i++)
    {
        readfast(ar[i]);
        Add(i);
    }
    d=sqrt(n);
    if(d*d<n)
        d++;
    for(i=0;i<q;i++)
    {
        readfast(a);
        readfast(b);
        Q[i].id=i;
        Q[i].L=a;
        Q[i].R=b;
        p=a/d;
        if(p*d<a)
            p++;
        Q[i].block=p;
    }
    sort(Q,Q+q,cmp1);
    int CL=1,CR=n,L,R;
    for(i=0;i<q;i++)
    {
        L=Q[i].L;
        R=Q[i].R;
        if(CL<L)
        {
            while(CL<L)
            {
                Remove(CL);
                CL++;
            }
        }
        else if(CL>L)
        {
            CL--;
            while(CL>L)
            {
                Add(CL);
                CL--;
            }
            Add(CL);
        }
        if(CR<R)
        {
            CR++;
            while(CR<R)
            {
                Add(CR);
                CR++;
            }
            Add(CR);
        }
        else if(CR>R)
        {
            while(CR>R)
            {
                Remove(CR);
                CR--;
            }
        }
        Q[i].ans=ans;

    }
    sort(Q,Q+q,cmp2);
    for(i=0;i<q;i++)
    {
       pf("%lld\n",Q[i].ans);
    }
    return 0;
}

