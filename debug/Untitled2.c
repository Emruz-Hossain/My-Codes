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
#define sz 2000
#define inf 1<<25
int ar[sz],m;
void rec(int ind,int p,int q,int n,int sum)
{
    if(p+q==sum)
    {
        if(m>abs(p-q))
        m=abs(p-q);
    }
    if(ind+1<=n)
    {
        rec(ind+1,p+ar[ind],q,n,sum);
        rec(ind+1,p,q+ar[ind],n,sum);
    }
}
int main()
{
    int t,n,i,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }

        m=inf;
        rec(0,0,0,n,sum);
        printf("%d\n",m);
    }
    return 0;
}


