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
    long long  n,i,j,m,k,l;
    scanf("%lld",&n);
    while(n--)
    {
        m=0;
        scanf("%lld %lld",&i,&j);
        k=max(i,j);
        l=min(i,j);
        while(k!=l)
        {
            if(k>l)
            {
            k=k/2;
            m++;
            }
            if(k==l)
                break;
            else if(l>k)
            {
                l=l/2;
                m++;
            }


        }
        printf("%lld\n",m);
    }
    return 0;
}


