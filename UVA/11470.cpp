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
#define sz 20
#define eps 1e-9
int ar[sz][sz];
int dfs(int x,int y,int n)
{
    int sum=0,i;
    for(i=x;i<=n-x-1;i++)
    {
        sum+=ar[y][i];
    }
    for(i=y+1;i<=n-x-1;i++)
        sum+=ar[i][n-x-1];
    for(i=x;i<=n-x-2;i++)
        sum+=ar[n-x-1][i];
    for(i=y+1;i<=n-x-2;i++)
        sum+=ar[i][y];
    return sum;

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int n,i,j,t=0;
    vector<int>E;
    while(1)
    {

        scanf("%d",&n);
        if(n==0)
            break;
        t++;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&ar[i][j]);
            }
        }
        for(i=0;i<=n/2;i++)
        {
           int r= dfs(i,i,n);
           if(r>0)
          E.push_back(r);
        }
        printf("Case %d: ",t);
        for(i=0;i<E.size();i++)
        {
            printf("%d",E[i]);
            if(i<E.size()-1)
                printf(" ");
        }
        printf("\n");
        E.clear();
    }


    return 0;
}


