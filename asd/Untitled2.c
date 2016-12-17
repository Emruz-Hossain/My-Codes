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
#define sz 20000
#define eps 1e-9
#include<stdio.h>
int n,kk,ar[1500];
vector<int>v;
int checker(int m)
{
    int k,sum=0,j,c=0;
    k=1;
    while(k<=kk)
    {
        sum=0;
         for(j=c;j<=n;j++)
         {
             sum+=ar[j];
             if(sum>m)
             {
                 c=j;
                 k++;
                break;
             }

         }
          if(j==n+1)
          break;
    }
    if(k<=kk)
        return 1;
    else
    return 0;
}
int main()
{
    int i,h,l,m,p,x,t;
     //    freopen("output.txt","w",stdout);
        freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        v.clear();
        scanf("%d %d",&n,&kk);
        h=0;
        for(i=0;i<=n;i++)
            scanf("%d",&ar[i]);
        l=ar[0];
        for(i=0;i<=n;i++)
        {
            h+=ar[i];
            if(l<ar[i])
                l=ar[i];
        }
        kk++;
        while(l<=h)
        {
            m=(h+l)/2;
            p=checker(m);
            if(p==1)
            {
                p=checker(m-1);
                if(p==1)
                h=m-1;
                else
                break;
            }

            if(p==0)
                l=m+1;
        }
        printf("Case %d: %d\n",x,m);
        sum=0;
        i=0;
        while(kk)
        {
            sum+=ar[i];
            if(kk==n-d)
            {
                for(int j=d+1;)
            }
            if(sum>=m)
            {
                if(sum==m)
                    v.push_back(sum);
                else
                {
                    v.push_back(sum-ar[i]);
                    i--;
                }
                kk--;
                int d=i;
            }
            i++;
        }
    }
    return 0;
}
