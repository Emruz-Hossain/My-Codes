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
using namespace std;
#define inf 1<<25
typedef unsigned long long ull;
#define sz 2000
ull mod;
unsigned long long a[5][5],b[5][5],sum[5][5],r;
void mat_expo(int n,int m)
{
    int i,j,k;
    if(n<=1)
        return;
    if(n%2)
        mat_expo(n-1,m);
    else
        mat_expo(n/2,m);
    if(n%2)
    {
        for(i=0;i<m;i++)
        {

            for(j=0;j<m;j++)
            {
                r=0;
                for(k=0;k<m;k++)
                {
                    r=(r+((a[i][k]%mod)*(b[k][j]%mod))%mod)%mod;
                }
                sum[i][j]=r;
            }
        }
    }
    else
    {
        for(i=0;i<m;i++)
        {

            for(j=0;j<m;j++)
            {
                r=0;
                for(k=0;k<m;k++)
                {
                    r=(r+((a[i][k]%mod)*(a[k][j])%mod)%mod)%mod;
                }
                sum[i][j]=r;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j]=sum[i][j];
        }
    }
}
int main()
{
    int n,i,j,k,m,t,x;
//    freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {


    scanf("%d %d %d %d",&i,&j,&n,&m);
    printf("Case %d: ",x);
        n++;
    a[0][0]=0;a[0][1]=1;a[1][0]=1;a[1][1]=1;
    b[0][0]=0;b[0][1]=1;b[1][0]=1;b[1][1]=1;
        unsigned long long d=1;
        while(m--) {
            d*=10;
        }
        mod =d;
    mat_expo(n-2,2);
    if(n==1)
        printf("%llu\n",(ull)i%d);
    else if(n==2)
        printf("%llu\n",(ull)j%d);
    else
    {

    printf("%llu\n",((i*a[1][0])%mod+(j*a[1][1])%mod)%mod);
    }
    }
    return 0;
}


