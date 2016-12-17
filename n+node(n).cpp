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
#define sz 1000005
int ar[sz];
int factor(int n)
{
    int cnt=0,fact=1;
    while(n%2==0)
    {
        cnt++;
        n/=2;
    }
    fact*=(cnt+1);
    for(int i=3;i<=sqrt(n);i+=2)
    {
        cnt=0;
       while(n%i==0)
        {
            cnt++;
            n=n/i;
        }
        if(cnt!=0)
            fact*=(cnt+1);
    }
    if(n>2)
        fact*=2;
    return fact;
}
int search_e(int n,int l,int h,int p)
{
    int m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(ar[m]==n)
            return m;
        else if(ar[m]>n)
            h=m;
        else if(ar[m]<n)
            l=m;
        if(l==h)
            break;
    }
    if(l==h&&p==1)
        return l+1;
    else
        return l-1;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int n,i,fac,x,t,a,b,p,q;
    ar[0]=1;
    ar[1]=2;
    n=2;
    x=2;
    while(n<=1000000)
    {
        ar[x]=ar[x-1]+factor(ar[x-1]);
        n=ar[x++];
    }
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&a,&b);
        p=search_e(a,0,x,1);
        q=search_e(b,0,x,2);
        printf("Case %d: %d\n",i,q-p+1);
    }
    return 0;
}


