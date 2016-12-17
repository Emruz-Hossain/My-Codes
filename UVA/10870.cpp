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
unsigned long long a[20][20],b[20][20],sum[20][20],r,coef[sz],val[sz],ans[20];
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
   long long n,i,j,k,m,mod,t,d;
    freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);

   while(1)
   {
    scanf("%lld %lld %lld",&d,&n,&mod);
    if(d==0&&n==0&&mod==0)
        break;
    for(i=0;i<d;i++)
    {
        scanf("%lld",&coef[i]);
    }
    for(i=1;i<=d;i++)
        scanf("%lld",&val[i]);
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
        {
            if(i==0)
            {
                a[i][j]=b[i][j]=coef[j];
            }
            else
            {
                if(j==i-1)
                    a[i][j]=b[i][j]=1;
                else
                    a[i][j]=b[i][j]=0;
            }

        }
    }
    if(n==1||n==2)
        printf("%lld\n",val[n]);
    else
    {
    mat_expo(n-1,d,mod);
    for(i=0;i<d;i++)
        {
            r=0;
            for(j=0;j<d;j++)
            {
                r+=(a[i][j]%mod)*(val[j+1]%mod);
            }
            ans[i]=r%mod;
        }

    for(i=0;i<d;i++);
    {
        printf("%llu\n",ans[1]);
    }
    }
    }
    return 0;
}





