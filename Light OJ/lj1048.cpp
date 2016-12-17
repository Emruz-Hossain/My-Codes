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
#define eps 1e-9
int ar[sz];
vector<int>v,vv;
int check(int m,int n,int k)
{
    int i,sum=0,d;
    vv.clear();
    for(i=0;i<=n;i++)
    {
        sum+=ar[i];
        if(sum>=m)
        {
            if(sum==m)
            vv.push_back(sum);
            else
            {
                vv.push_back(sum-ar[i]);
                i--;
            }
            k--;
            sum=0;
            d=i+1;
        }
        if(k<0)
            return 0;
    }
    if(k>0)
       {
           while(k>0)
           {
               vv.push_back(ar[d]);
               d++;
               k--;
               if(k==1)
               {
                   sum=0;
                   for(i=d;i<=n;i++)
                    sum+=ar[i];
                   vv.push_back(sum);
                   k--;
               }

           }
       }
       return 1;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i,x,n,m,k,p,l,h,mm,sum;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        sum=0;
        scanf("%d %d",&n,&k);
        for(i=0;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }
        l=0;h=sum;
        while(l<=h)
        {
            m=(l+h)/2;
            p=check(m,n,k+1);
            if(p==1)
            {
                v.clear();
                v=vv;
                h=m-1;
            }
            else
                l=m+1;
        }
        mm=0;
        for(i=0;i<v.size();i++)
            mm=max(mm,v[i]);
        printf("Case %d: %d\n",x,mm);
        for(i=0;i<v.size();i++)
        printf("%d\n",v[i]);

    }


    return 0;
}
