
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int ar[100000],Br[100000];


 void Inorder(int n)
 {
     if(Br[n-1]>-1)
     {

         Inorder(2*n);
         printf(" %d",Br[n-1]);
         Inorder(2*n+1);
     }
 }


void Binarytree(int n,int k,int m)
{
    if(k>=m)
        return;
    if(Br[n-1]==-1)
    {
        Br[n-1]=ar[k];
    }
    else
    {
       if(ar[k]>Br[n-1])
       {
           Binarytree(2*n+1,k,m);
       }
       else
       {
           Binarytree(2*n,k,m);
       }
       if(n==1)
       Binarytree(n,k+1,m);
    }

}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,u,v;
     while(sn("%d",&n)==1)
     {
         memset(ar,-1,sizeof(ar));
         memset(Br,-1,sizeof(Br));
         for(i=0;i<n;i++)
         {
             scanf("%d",&ar[i]);
         }
         Br[0]=ar[0];
         Binarytree(1,1,n);
         for(i=0;i<n*2+2;i++)
            pf(" %d",Br[i]);
         pf("\n");
         Inorder(1);
         pf("\n");
     }
    return 0;
}

