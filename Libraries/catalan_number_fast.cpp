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
std:: vector<std::pair<int,int> >prime_factor;
    vector<int>power;
void generate_factor(int N)
{
    int i,j;
    prime_factor.resize(N+1);
    for(i=1;i<=N;i++)
        prime_factor[i]=std::pair<int ,int>(i,1);
    for(i=2,j=4;j<=N;j+=i+i+1,i++)
    {
        if(prime_factor[i].second==1)
        {
        int r=i;
        int k=j;
        while(k<=N)
        {
            prime_factor[k]=pair<int,int>(i,r);
            r++;
            k+=i;
        }

        }
    }
}
void cal_power(int n,int p)
{
    while(prime_factor[n].first!=1)
    {
        power[prime_factor[n].first]+=p;
        n=prime_factor[n].second;
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int n,i;
   long long res;
     generate_factor(200000);
    scanf("%d",&n);
    if(n==0||n==1)
        printf("1\n");
    else
    {
    power.resize(2*n+1);
    for(i=2;i<=n;i++)
    {
        cal_power(n+i,1);
        cal_power(i,-1);
    }
    res=1;
    for(i=1;i<power.size();i++)
    {
        while(power[i]--)
        {
            res*=i;
            res%=mod;
        }
    }
    printf("%lld\n",res);
    }

    return 0;
}
