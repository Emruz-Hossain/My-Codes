//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
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
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    while(scanf("%d %d %d",&m,&n,&t)==3)
    {
        k=max(m,n);
        m=min(m,n);
        n=k;
        p=t/m;
        if(t%m==0)
        {
            printf("%d\n",p);
            continue;
        }
        else
        {
            r=0;l=t-p*m;a=p;q=0;
            while(p>=0)
            {
                if(t-p*m>=n)
                    q=(t-p*m)/n;
                r=p*m+q*n;
                if(r==t)
                    break;
                else
                {
                    if(l>t-r)
                    {
                        l=t-r;
                        a=p+q;
                    }
                }
                p--;

            }
            if(r==t)
            {
                printf("%d\n",p+q);
                continue;
            }
            else
                printf("%d %d\n",a,l);
        }
    }

    return 0;
}
