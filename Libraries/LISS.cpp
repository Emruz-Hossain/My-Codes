//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int ar[1000],lis[100],P[1000],mx,mp;
int liss(int n)
{
    int i,j;
   for(i=0;i<n;i++)
   {
       for(j=i;j>=0;j--)
       {
          if(ar[i]>ar[j])
            {
                if(lis[i]<lis[j]+1)
                {
                    lis[i]=lis[j]+1;
                    P[i]=j;
                    if(lis[i]>mx)
                    {
                        mx=lis[i];mp=i;
                    }
                }
            }
       }
   }
}

void path(int p)
{
    if(P[p]==-1)
      {
          printf("%d",ar[p]);
          return;
      }
    path(P[p]);
    printf(" %d",ar[p]);
}

int main()
{
    int i,j,k,l,m,n,a,b,u;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&ar[i]);
    memset(lis,0,sizeof(lis));
     memset(P,-1,sizeof(P));
    mx=0;
    liss(n);
    printf("%d\n",mx+1);
    path(mp);
    printf("\n");
    return 0;
}



