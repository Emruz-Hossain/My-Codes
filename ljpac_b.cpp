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
struct st
{
    long long n,c;
}a;
vector<st>V;
int main()
{
        freopen("output.txt","r",stdin);
    //    freopen("input.txt","r",stdin);
    long long t,x,n,m,sum,i,cnt,nd,sd,k;
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
    {
        V.clear();
        scanf("%lld %lld",&n,&m);
        k=n;
        sum=1;
        if(n%2==0)
        {
            cnt=0;
            while(n%2==0)
            {
                cnt++;
                n/=2;
            }
            a.n=2;
            a.c=cnt;
            V.push_back(a);
        }
        if(n!=0)
        {
            for(i=3;i*i<=n;i+=2)
            {

                if(n%i==0)
                {
                    cnt=0;
                    while(n%i==0)
                    {
                        cnt++;
                        n/=i;
                    }
                    a.n=i;
                    a.c=cnt;
                    V.push_back(a);
                }
            }
        }
        if(n!=0&&n!=1)
        {
            a.n=n;
            a.c=1;
            V.push_back(a);
        }
        nd=1;
        if(V.size()==1&&V[0].n==k)
        nd=1;
        else
        {
        for(i=0;i<V.size();i++)
        {
            nd*=(V[i].c+1);
        }
        }
        printf("%lld\n",nd);
        sd=1;
        for(i=0;i<V.size();i++)
        {
            //printf("%d %d\n",V[i].n,V[i].c);
            sd*=(pow(V[i].n,V[i].c+1)-1)/(V[i].n-1);
        }
        sd-=k;
        printf("%lld\n",sd);
        if(nd<m)
            printf("Case %lld: Impossible\n",x);
        else
        {
            printf("Case %lld: Yes %lld\n",x,sd);
        }
    }

    return 0;
}

