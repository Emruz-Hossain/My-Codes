//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct st
{
    int pos,dim[12];
}ar[35],dd;
struct st2
{
    int cur,mx;
}dp[55][55];
int m,n;
vector<st>E,v;
bool cmp(st a,st b)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a.dim[i]<b.dim[i])
            return true;
        else if(a.dim[i]>b.dim[i])
            return false;
    }
}
int rec(int prev,int ind,int p)
{
    int i,j,w=0,q=0,r;
    if(ind>=m)
    {
        if(v.size()>E.size())
        {
            E.clear();
            for(i=0;i<v.size();i++)
            {
                for(j=0;j<n;j++)
                {
                    dd.dim[j]=v[i].dim[j];
                }
                dd.pos=v[i].pos;
                E.push_back(dd);
            }
        }
        return v.size();
    }
    if(dp[prev][ind].cur>p)
        return dp[prev][ind].mx;
    if(prev==50)
    {
        for(i=0;i<n;i++)
        {
            dd.dim[i]=ar[ind].dim[i];
        }
        dd.pos=ar[ind].pos;
        v.push_back(dd);
        w=rec(ind,ind+1,p+1);
        v.pop_back();
        q=rec(prev,ind+1,p);
    }
    else
    {
        r=1;
        for(i=0;i<n;i++)
        {
            if(ar[ind].dim[i]<=ar[prev].dim[i])
            {
                r=0;break;
            }
        }
        if(r==1)
        {
            for(i=0;i<n;i++)
                dd.dim[i]=ar[ind].dim[i];
            dd.pos=ar[ind].pos;
            v.push_back(dd);
             w=rec(ind,ind+1,p+1);
             v.pop_back();
        }

       q=rec(prev,ind+1,p);
    }
    dp[prev][ind].cur=p;
    dp[prev][ind].mx=max(w,q);
    return dp[prev][ind].mx;

}
int main()
{
      //  freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    while(scanf("%d %d",&m,&n)==2)
    {
        v.clear();
        E.clear();
        memset(dp,0,sizeof(dp));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&ar[i].dim[j]);
            }
            ar[i].pos=i+1;
            sort(ar[i].dim,ar[i].dim+n);
        }
      sort(ar,ar+m,cmp);
      rec(50,0,0);
//    for(i=0;i<m;i++)
//    {
//        printf("pos=%d ",ar[i].pos);
//        for(j=0;j<n;j++)
//            printf("%d ",ar[i].dim[j]);
//        printf("\n");
//    }

    printf("%d\n",E.size());
    for(i=0;i<E.size();i++)
    {
        printf("%d",E[i].pos);
        if(i<E.size()-1)
            printf(" ");
    }
    printf("\n");
   // printf("\n\n________________\n\n");
    }
    return 0;
}

