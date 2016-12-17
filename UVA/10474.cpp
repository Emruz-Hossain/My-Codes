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
#define sz 10005
#define eps 1e-9
int ar[sz];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int i,j,k,t,m,l,h,qq,q,n,p;
    t=0;
    while(1)
    {
        t++;
        scanf("%d %d",&n,&qq);
        if(n==0&&qq==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        sort(ar,ar+n);
        printf("CASE# %d:\n",t);
        for(i=0;i<qq;i++)
        {
            scanf("%d",&p);
            q=0;
            l=0;h=n-1;
            while(l<=h)
            {
                m=(l+h)/2;
                if(ar[m]==p)
                {
                    q=1;
                    k=m;
                    for(j=m-1;j>=0;j--)
                    {
                        if(ar[j]==p)
                            k=j;
                    }
                    printf("%d found at %d\n",p,k+1);
                    break;
                }
                if(ar[m]>p)
                    h=m-1;
                else
                    l=m+1;
            }
            if(q==0)
                printf("%d not found\n",p);
        }
    }


    return 0;
}


