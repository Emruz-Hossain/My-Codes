
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
int ar[10005],br[10005],temp1[10005],temp2[10005],lis1[10005],lis2[10005];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mxl1,mxl2,h,mx;
    while(scanf("%d",&n)==1)
    {
        memset(lis1,0,sizeof(lis1));
        memset(lis2,0,sizeof(lis2));
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            br[n-i-1]=ar[i];
        }

        temp1[0]=-inf;
        temp2[0]=-inf;
        for(i=1;i<=n;i++)
        {
            temp1[i]=inf;
            temp2[i]=inf;
        }
        mxl1=0;
        mxl2=0;
        for(i=0;i<n;i++)
        {
            l=0;h=mxl1;
            while(l<=h)
            {
                m=(l+h)/2;
                if(temp1[m]<ar[i])
                    l=l+1;
                else
                    h=h-1;
            }
            temp1[l]=ar[i];
            lis1[i]=l;
            if(mxl1<l)
                mxl1=l;
            l=0;h=mxl2;
            while(l<=h)
            {
                m=(l+h)/2;
                if(temp2[m]<br[i])
                    l=l+1;
                else
                    h=h-1;
            }
            temp2[l]=br[i];
            lis2[i]=l;
            if(mxl2<l)
                mxl2=l;
        }
        mx=0;
//        for(i=0;i<n;i++)
//            printf("%d ",lis1[i]);
//        printf("\n");
//        for(i=0;i<n;i++)
//            printf("%d ",lis2[i]);
//        printf("\n");
        for(i=0;i<n;i++)
        {
            if(lis1[i]>=lis2[n-i-1])
            mx=max(mx,2*lis2[n-i-1]);
            else
                mx=max(mx,2*lis1[i]);
        }
        printf("%d\n",mx-1);
    }

    return 0;
}
