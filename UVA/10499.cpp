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
#define sz 200
int main()
{
    long long p,n;
    double d;
    while(1)
    {
        scanf("%lld",&n);
        if(n<0)
            break;
        if(n==1)
            printf("0%%\n");
        else
      printf("%lld%%\n",(n*100)/4);
    }
    return 0;
}


