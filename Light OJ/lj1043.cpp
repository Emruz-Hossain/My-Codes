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
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,x;
    double a,b,c,r;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&r);
        printf("Case %d: %.12lf\n",x,sqrt((r*a*a)/(r+1)));
    }


    return 0;
}


