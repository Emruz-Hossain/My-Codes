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
int main()
{

   unsigned long long expo1[5][5],expo2[5][5],sum[5][5],ans[5],r[5];
    int i,n,j;
    expo1[0][0]=1;expo1[0][1]=1;expo1[1][0]=1;expo1[1][1]=0;
    expo2[0][0]=1;expo2[0][1]=1;expo2[1][0]=1;expo2[1][1]=0;
    r[0]=1;r[1]=1;
    scanf("%d",&n);
    n=n-3;
    while(n--)
    {
        sum[0][0]=expo1[0][0]*expo2[0][0]+expo1[0][1]*expo2[1][0];
        sum[1][0]=expo1[1][0]*expo2[0][0]+expo1[1][1]*expo2[1][0];
        sum[0][1]=expo1[0][0]*expo2[0][1]+expo1[0][1]*expo2[1][1];
        sum[1][1]=expo1[1][0]*expo2[0][1]+expo1[1][1]*expo2[1][1];
         expo1[0][0]=sum[0][0];expo1[0][1]=sum[0][1];expo1[1][0]=sum[1][0];expo1[1][1]=sum[1][1];

    }
//    for(i=0;i<2;i++)
//    {
//        for(j=0;j<2;j++)
//        {
//            printf("%lld ",sum[i][j]);
//        }
//        printf("\n");
//    }
    ans[0]=sum[0][0]*r[0]+sum[0][1]*r[1];
    printf("%llu\n",ans[0]);
    return 0;
}


