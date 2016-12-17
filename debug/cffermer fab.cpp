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
#define N 4000
long long prime[N];
int main()
{
    long long i,j,t,x,y;
    memset(prime,0,sizeof(prime));
    for(prime[0]=prime[1]=1,i=4;i<=N;i+=2)
        prime[i]=1;
    for(i=3;i<=sqrt(N)+1;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=N;j+=i*2)
            {
                prime[j]=1;
            }
        }
    }
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&x,&y);
        for(i=x+y+1;i<=N;i++)
        {
            if(prime[i]==0)
            {
                printf("%lld\n",i-(x+y));
                break;
            }
        }
    }

    return 0;
}


