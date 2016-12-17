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

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct st
{
    int w,h;
}ar[20002],Temp[20002];
int Lis[20002],mp[20002];
bool cmp(st a,st b)
{
    if(a.w<b.w)
        return true;
    else if(a.w>b.w)
        return false;
    else
        return (a.h>b.h)?true:false;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mxl;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d",&ar[i].w,&ar[i].h);
        sort(ar,ar+n,cmp);
        Temp[0].w=0;
        Temp[0].h=0;
        for(i=1;i<=n;i++)
        {
            Temp[i].h=inf;
            Temp[i].w=inf;
        }
        mxl=0;
        for(i=0;i<n;i++)
        {
            l=0;h=mxl;
            while(l<=h)
            {
                m=(l+h)/2;
                if(Temp[m].h<ar[i].h&&Temp[m].w<ar[i].w)
                    l=l+1;
                else
                    h=h-1;
            }
            Temp[l].h=ar[i].h;
            Temp[l].w=ar[i].w;
            Lis[i]=l;
            mxl=max(mxl,l);
        }
        for(i=0;i<n;i++)
            printf("%d ",Lis[i]);
        printf("\n");
        for(i=0;i<=mxl;i++)
            mp[i]=0;
        for(i=n-1;i>=0;i--)
        {
            mp[Lis[i]]++;
        }
        b=0;sm=0;
        for(i=mxl;i>=0;i--)
        {
             if(mp[i]-b>0)
             {
                 sm+=max(0,mp[i]-b);
                 b+=mp[i]-b;
             }

        }
        printf("%d\n",sm);
    }

    return 0;
}

