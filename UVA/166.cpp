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
#define sz 6000
#define eps 1e-9
int dp[300][sz],sk[300][sz];
int coin[]={5,10,20,50,100,200};
int main()
{
    int i,j,ar[10],p,q;
    double f;
   memset(sk,0,sizeof(sk));
   for(i=1;i<=6;i++)
   {
       for(j=0;j<=5000;j+=5)
       {
           if(j>=coin[i-1])
           {
               p=j/coin[i-1];
           if(sk[i-1][j]!=0)
             sk[i][j]=min(sk[i-1][j],(p+sk[i-1][j-p*coin[i-1]]));
           else
            sk[i][j]=p+sk[i-1][j-p*coin[i-1]];
           }
           else
            sk[i][j]=sk[i-1][j];

       }
   }
   while(scanf("%d %d %d %d %d %d",&ar[0],&ar[1],&ar[2],&ar[3],&ar[4],&ar[5])==6)
   {

       if(ar[0]==0&&ar[1]==0&&ar[2]==0&&ar[3]==0&&ar[4]==0&&ar[5]==0)
         break;
        scanf("%lf",&f);

       double d=f*100+eps;
       q=d;
        //printf("%d\n",q);
      memset(dp,0,sizeof(dp));
       for(i=1;i<=6;i++)
       {
       for(j=0;j<=5000;j+=5)
       {
           if(j>=coin[i-1]&&ar[i-1]!=0)
           {
                p=j/coin[i-1];
                if(p>ar[i-1])
                    p=ar[i-1];
                if((dp[i-1][j-p*coin[i-1]])!=0||j-p*coin[i-1]==0)
                {
                if(dp[i-1][j]!=0)
                    dp[i][j]=min(dp[i-1][j],(p+dp[i-1][j-p*coin[i-1]]));
                else
                    dp[i][j]=p+dp[i-1][j-p*coin[i-1]];
                }
               else
                dp[i][j]=dp[i-1][j];
        }
        else
            dp[i][j]=dp[i-1][j];
       }
    }
    for(i=0;i<=5000;i+=5)
    {
        if(dp[6][i]==0)
            dp[6][i]=inf;
    }
    for(i=0;i<=5000;i+=5)
    {
        for(j=i;i+j<=5000;j+=5)
        {
            if(dp[6][j]!=0&&sk[6][j-i]!=0)
            {
                dp[6][i]=min(dp[6][i],dp[6][j]+sk[6][j-i]);
            }
        }
    }
//   for(i=0;i<=120;i+=5)
//        printf("%d ",sk[6][i]);
//    printf("\n");
//    for(i=0;i<=120;i+=5)
//        printf("%d ",dp[6][i]);
//    printf("\n");
    printf("%3d\n",dp[6][q]);
   }

    return 0;
}

