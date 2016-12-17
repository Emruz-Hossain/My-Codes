
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<iostream>
#include<iomanip>
#include<ctime>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define     mem(x,y) memset(x,y,sizeof(x))
#define     PB(x) push_back(x)
#define     POB() pop_back()
#define     SZ(a) a.size()
#define     len(a) strlen(a)
#define     all(v) v.begin(),v.end()
#define     fr(s,e,in) for(i=s;i<=e;i+=in)
#define     sf scanf
#define     pf printf
#define     read2(m,n) scanf("%d %d",&m,&n)
#define     read3(m,n,p) scanf("%d %d %d",&m,&n,&p)
#define     readl(n) scanf("%I64d",&n);
#define     readl2(m,n) scanf("%I64d %I64d",&m,&n)
#define     readl3(m,n,p) scanf("%I64d %I64d %I64d",&m,&n,&p)

#define     inf 1<<25
#define     sz 20002
#define     eps 1e-9
#define     mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}
 struct st
 {
     int sum,prop;
 }tree[3*100004];
  int read(void)
 {
     int sm=0;
     while(1)
     {
        int c = getchar_unlocked();
         if(c<'0'||c>'9')
            break;
         else
            c=c-'0';
        sm=sm*10+c;
     }
     return sm;
 }
 void propagate(int rt)
 {
     if(tree[rt].prop==-1)
        return;
     tree[2*rt].prop=tree[rt].prop;
     tree[2*rt+1].prop=tree[rt].prop;
     tree[rt].prop=-1;
 }
 int get(int rt,int l,int r)
 {
     if(tree[rt].prop==-1)
        return tree[rt].sum;
    else
        return (r-l+1)*tree[rt].prop;
 }
 void update(int rt,int beg,int endd,int l,int r,int val)
 {
     if(beg>=l&&endd<=r)
     {
         tree[rt].prop=val;
         tree[rt].sum=val*(endd-beg+1);
         return;
     }
     if(beg>r||endd<l)
        return;
     propagate(rt);
     int mid=(beg+endd)/2;
     if(l<=mid)
     update(2*rt,beg,mid,l,r,val);
     if(r>mid)
     update(2*rt+1,mid+1,endd,l,r,val);
     tree[rt].sum=get(2*rt,beg,mid)+get(2*rt+1,mid+1,endd);
 }
 int query(int rt,int beg,int endd,int l,int r,int prop)
 {
     if(beg>=l&&endd<=r)
     {
         if(prop==-1)
            prop=tree[rt].prop;
         if(prop==-1)
            return tree[rt].sum;
         else
          return (endd-beg+1)*prop;
     }
     if(beg>r||endd<l)
       return 0;
     int mid=(beg+endd)/2;
     if(prop==-1)
        prop=tree[rt].prop;
     return query(2*rt,beg,mid,l,r,prop)+query(2*rt+1,mid+1,endd,l,r,prop);
 }
 void build(int rt,int beg,int endd)
 {
     tree[rt].prop=-1;
     tree[rt].sum=0;
     if(beg==endd)
        return;
     int mid=(beg+endd)/2;
     build(2*rt,beg,mid);
     build(2*rt+1,mid+1,endd);
 }
int main()
{
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   t=read();
   for(x=1;x<=t;x++)
   {
       n=read();
       q=read();
       build(1,1,n);
       pf("Case %d:\n",x);
       while(q--)
       {
           a=read();
           b=read();
           c=read();
           if(a==1)
           {
               int val;
               val=read();
               update(1,1,n,b+1,c+1,val);
           }
           else
           {
               p=query(1,1,n,b+1,c+1,-1);
               r=c-b+1;
               if(p%r==0)
                pf("%d\n",p/r);
               else
               {
                   sm=gcd(p,r);
                   pf("%d/%d\n",p/sm,r/sm);

               }
           }


       }
   }

    return 0;
}
