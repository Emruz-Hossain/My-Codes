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
#define     sf scanf
#define     pf printf

#define     inf 1<<25
#define     sz 2000
#define     eps 1e-9
#define     mod  1000000007
int ar[100005],lis[100005];
struct st
{
    int mn,mx;
}tree[3*100005];
void build(int node,int beg,int endd)
{
    if(beg==endd)
    {
        tree[node].mn=ar[beg];
        tree[node].mx=ar[beg];
        return;
    }
    int mid=(beg+endd)/2;
    build(2*node,beg,mid);
    build(2*node+1,mid+1,endd);
    tree[node].mx=max(tree[2*node].mx,tree[2*node+1].mx);
     tree[node].mn=min(tree[2*node].mn,tree[2*node+1].mn);
}
int query(int node,int beg,int endd,int left,int right,int val)
{
    if(beg>right||endd<left)
        return 0;
    if(beg==endd&&tree[node].mx>=val)
        return 0;
    if(tree[node].mn>=val)
        return 0;
    if(tree[node].mx<val)
        return lis[endd]-lis[beg-1];
    int mid=(beg+endd)/2;
    return (query(2*node,beg,mid,left,right,val)+query(2*node+1,mid+1,endd,left,right,val))%mod;

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   scanf("%d",&t);
   for(x=1;x<=t;x++)
   {
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       {
           scanf("%d",&ar[i]);
       }
       build(1,1,n);
       lis[1]=1;lis[0]=0;
       for(i=2;i<=n;i++)
       {
           lis[i]=((query(1,1,n,1,i-1,ar[i])+lis[i-1])%mod+1)%mod;
       }
       printf("Case %d: %d\n",x,lis[n]);
   }
    return 0;
}

