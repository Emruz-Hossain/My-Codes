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
    long long  s,d,i,n,t;
    while(scanf("%lld %lld",&s,&d)==2)
    {
        if(d==1)
            printf("%lld\n",s);
        else
        {
            n=s;t=s;
            while(t<d)
            {
                n++;
                t+=n;

            }
            printf("%lld\n",n);
        }
    }

    return 0;
}


