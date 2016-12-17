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
int ar[100000];
 void Preorder(int n)
 {
     if(ar[n-1]>-1)
     {
         printf(" %d",ar[n-1]);
         Preorder(2*n);
         Preorder(2*n+1);
     }
 }

 void Inorder(int n)
 {
     if(ar[n-1]>-1)
     {

         Inorder(2*n);
         printf(" %d",ar[n-1]);
         Inorder(2*n+1);
     }
 }

 void Postorder(int n)
 {
     if(ar[n-1]>-1)
     {

         Postorder(2*n);

         Postorder(2*n+1);
         printf(" %d",ar[n-1]);
     }
 }

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,u,v;
     while(sn("%d",&n)==1)
     {
         memset(ar,-1,sizeof(ar));
         for(i=0;i<n;i++)
         {
             scanf("%d",&ar[i]);
         }
         Preorder(1);
         pf("\n");
         Inorder(1);
         pf("\n");
         Postorder(1);
         pf("\n");
     }
    return 0;
}

