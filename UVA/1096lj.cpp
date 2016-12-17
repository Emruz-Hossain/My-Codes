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
unsigned long long a[10][10],b[10][10],sum[10][10],r;
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
    int n,i,j,k,m,mod,ac,bc,t,cc,x;
//    freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);

    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
    scanf("%d %d %d %d",&n,&ac,&bc,&cc);
    a[0][0]=ac;a[0][1]=0;a[0][2]=bc;a[0][3]=cc;a[1][0]=1;a[1][1]=0;a[1][2]=0;a[1][3]=0;a[2][0]=0;a[2][1]=1;a[2][2]=0;a[2][3]=0;a[3][0]=0;a[3][1]=0;a[3][2]=0;a[3][3]=1;
    b[0][0]=ac;a[0][1]=0;b[0][2]=bc;b[0][3]=cc;b[1][0]=1;b[1][1]=0;b[1][2]=0;b[1][3]=0;b[2][0]=0;b[2][1]=1;b[2][2]=0;b[2][3]=0;b[3][0]=0;b[3][1]=0;b[3][2]=0;b[3][3]=1;

    mod=10007;
    mat_expo(n,4,mod);
    printf("Case %d: %llu\n",x,a[2][3]);
    }
    return 0;
}



