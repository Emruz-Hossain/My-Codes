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
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int p,q,r,t;
    double n,a,b;
    scanf("%d",&t);
    while(t--)
    {
        q=1;r=0;
        scanf("%lf",&n);
        a=360/n;
        p=a;
        if(n>360)
            q=0;
        b=(360-(n*(n-1)/2));
        if(b>n-1)
        r=1;
        if(p==a)
            printf("y ");
        else
            printf("n ");
        if(q==1)
            printf("y ");
        else
            printf("n ");
        if(r==1)
            printf("y\n");
        else
            printf("n\n");
    }


    return 0;
}


