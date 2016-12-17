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
#include<iomanip>
#include<ctime>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,x1,x2,y1,y2;
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        sm=max(x1,x2);
        sm=max(sm,y1);
        sm=max(sm,y2);
        p=x1-x2;
        q=y1-y2;
        if(p==0)
        {
            a=x2+1;b=y2;
            if(a>1e9)
            {
                 a=x2-1;
            }
        }
        else if(q==0)
        {
            b=y2+1;
            a=x2;
            if(b>1e9)
                b=y2-1;
        }
        else
        {
            b=sm;
            r=(q*y2+p*x2-b*q);
            if(r%p==0)
                a=r/p;
            while(r%p!=0||(a==x2&&b==y2)||a>sm)
            {
                --b;
                r=(q*y2+p*x2-b*q);
                if(r%p==0)
                a=r/p;
            }
        }
        printf("Case %lld: %lld %lld %lld %lld\n",x,x2,y2,a,b);
    }
    return 0;
}
