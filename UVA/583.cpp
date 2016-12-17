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
#define sz 200000
#define eps 1e-9
#define s 1000000
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
long long col[s/64+10],ma;
int prime[sz],e;
int seive()//1 indexed
{
    long long i,j,k;
    k=0;
    long long  prev=0;
    prime[0]=2;prime[1]=3;
    e=2;
    for(i=3;i<s;i+=2)
         if(!(col[i/64]&(1LL<<(i%64))))
         {
               if((i%4)==1)
               {
                    k++;
                    prime[e++]=i;
                    ma=max(ma,i-prev);
                    prev=i;
                }
                for(j=i*i;j<s;j+=2*i)
                    col[j/64]|=(1LL<<(j%64));
         }
    return k;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    long long n,d;
    int i,p;
    seive();
    while(scanf("%I64d",&n)==1)
    {

         if(n==0)
            break;
            d=n;
         if(n<0)
         {
             n*=-1;
         }
         if(d==1)
         {
             printf("1 = 1\n");
         }
         else if(d==-1)
            printf("-1 = -1\n");
         else
         {
            if(d<0)
                printf("%I64d = -1 ",d);
            else
            printf("%I64d = ",d);
            for(i=0;i<=sqrt(n);i++)
            {
                if(n%prime[i]==0)
                {
                    while(n%prime[i]==0)
                    {
                         printf(" x %d",prime[i]);
                         n=n/i;
                    }

                }
            }
        }
}
    return 0;
}


