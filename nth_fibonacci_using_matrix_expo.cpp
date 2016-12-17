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
    int n,i,j,k,m;
//    freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);

    while(scanf("%d",&n)==1)
    {
    a[0][0]=0;a[0][1]=1;a[1][0]=1;a[1][1]=1;
    b[0][0]=0;b[0][1]=1;b[1][0]=1;b[1][1]=1;
    mat_expo(n-2,2);
    if(n==1||n==2)
        printf("1\n");
    else
    printf("%llu\n",(a[1][0]+a[1][1]));
    }
    return 0;
}


