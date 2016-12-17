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
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i;
    double R,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %lf",&R,&n);
        printf("Case %d: %.12lf\n",i,(R*sin(2*acos(0)/n))/(1+sin(2*acos(0)/n)));
    }


    return 0;
}


