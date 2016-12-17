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
    double per ,day,n,p,k;
    while(scanf("%lf %lf",&per,&day)==2)
    {
        per=per/100;
        p=1;
        n=1;
        k=day-1;
        while(p>per)
        {
            p=p*(k/day);
            n++;
            k--;
        }
        printf("%d\n",(int)n);
    }


    return 0;
}


