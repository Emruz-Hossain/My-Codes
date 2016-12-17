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
#define sz 100005
#define eps 1e-9
int ar[sz],br[sz];
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int i,j,n,t,x;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&ar[i]);
        }
        sort(ar,ar+n);
        for(i=0;i<n;i++)
        {
            if(i%2==1&&i+1<n)
                swap(ar[i],ar[i+1]);
            printf("%d",ar[i]);
            if(i<n-1)
                printf(" ");
        }
        printf("\n");
    }


    return 0;
}


