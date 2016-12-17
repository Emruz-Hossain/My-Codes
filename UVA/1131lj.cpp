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
#define sz 2000
unsigned long long a[20][20],b[20][20],sum[20][20],r,ans[20],mat[10];
void mat_expo(int n,int m,int mod)
{
    int i,j,k;
    if(n<=1)
        return;
    if(n%2)
        mat_expo(n-1,m,mod);
    else
        mat_expo(n/2,m,mod);
    if(n%2)
    {
        for(i=0;i<m;i++)
        {

            for(j=0;j<m;j++)
            {
                r=0;
                for(k=0;k<m;k++)
                {
                    r+=a[i][k]*b[k][j];
                }
                sum[i][j]=r%mod;
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
                    r+=a[i][k]*a[k][j];
                }
                sum[i][j]=r%mod;
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
   long long n,i,j,k,m,mod,t,x,r,q,l;
   // freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);

    scanf("%lld",&t);
    for(x=1;x<=t;x++)
    {
        memset(a,0,sizeof(a));
    scanf("%lld %lld %lld",&a[0][0],&a[0][1],&a[0][5]);
    a[1][0]=1;a[2][1]=1;
    scanf("%lld %lld %lld",&a[3][3],&a[3][4],&a[3][2]);
    a[4][3]=1;a[5][4]=1;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
            b[i][j]=a[i][j];
    }
    scanf("%lld %lld %lld %lld %lld %lld",&mat[2],&mat[1],&mat[0],&mat[5],&mat[4],&mat[3]);
    scanf("%lld",&mod);
    printf("Case %lld:\n",x);
    scanf("%lld",&q);
    for(l=0;l<q;l++)
    {
        scanf("%lld",&n);
        if(n==0)
            printf("%llu %llu\n",mat[2]%mod,mat[5]%mod);
        else if(n==1)
            printf("%llu %llu\n",mat[1]%mod,mat[4]%mod);
        else
        {
        mat_expo(n-1,6,mod);
        for(i=0;i<6;i++)
        {
        r=0;
        for(j=0;j<6;j++)
        {
            r+=(a[i][j]%mod)*(mat[j]%mod);
        }
        ans[i]=r%mod;
        }
       printf("%llu %llu\n",ans[1],ans[4]);
        for(i=0;i<6;i++)
        {
            for(j=0;j<6;j++)
            {
                a[i][j]=b[i][j];
                //printf("%llu ",a[i][j]);
            }
        }
    }
    }

    }
    return 0;
}




