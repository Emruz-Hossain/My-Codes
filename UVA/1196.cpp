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
    int x,y;
};
st ar[10005],Temp[10005];
bool cmp(st a,st b)
    {
        if(a.x<b.x)
            return true;
        else if(a.x>b.x)
            return false;
        else
            return (a.y>b.y)?true:false;
    }
int main()
{
      //  freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mxl,h;
    while(scanf("%d",&n)==1&&n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].x,&ar[i].y);
        }
        sort(ar,ar+n,cmp);
        Temp[0].x=-inf;
        Temp[0].y=-inf;
        for(i=1;i<n;i++)
        {
            Temp[i].x=inf;
            Temp[i].y=inf;
        }
        mxl=0;
        for(i=0;i<n;i++)
        {
            l=0;h=mxl;
            while(l<=h)
            {
                m=(l+h)/2;
                if(Temp[m].x<=ar[i].x&&Temp[m].y<=ar[i].y)
                   l=l+1;
                else
                    h=h-1;
            }
            Temp[l].x=ar[i].x;
            Temp[l].y=ar[i].y;
            mxl=max(mxl,l);
        }
        sm=mxl;
        printf("%d\n",sm);
    }
    printf("*\n");
    return 0;
}
