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
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    int m,i,j,k,ar[100][100],br[100][100],sum[100][100],r=0;
    memset(sum,0,sizeof(sum));
    scanf("%d",&m);
    printf("Enter First matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    printf("Enter Second Matrix:\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&br[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            r=0;
            for(k=0;k<m;k++)
            {
                r+=ar[i][k]*br[k][j];
            }
            sum[i][j]=r;
        }
    }
    printf("Resultant matrix is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
