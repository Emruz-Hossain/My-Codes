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
#define sz 50005
#define eps 1e-9
 int ar[sz];
int finder(int s,int p,int n)
{
    int l,h,m,i;
    l=0;h=n-1;
    while(l<=h)
    {
        m=(l+h)/2;
        if(ar[m]==s)
        {
            if(p==1)
                {
                    for(i=m;i>=0;i--)
                    {
                        if(ar[i]!=ar[m])
                        return ar[i];
                    }
                    if(i<0)
                        return -1;
                }
            else
               {
                   for(i=m;i<n;i++)
                   {
                       if(ar[i]!=ar[m])
                        return ar[i];
                   }
                   if(i==n)
                    return -1;
               }
        }
        else if(ar[m]>s)
            h=m-1;
        else
            l=m+1;

    }
    if(p==1)
        return ar[h];
    else
        return ar[l];

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int n,i,p,q,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&p);
        x=finder(p,1,n);
        y=finder(p,2,n);
        if(x>0&&y>0)
            printf("%d %d\n",x,y);
        else if(x<1&&y>0)
            printf("X %d\n",y);
        else if(x<1&&y<1)
            printf("X X\n");
        else if(x>0&&y<1)
        printf("%d X\n",x);
    }


    return 0;
}


