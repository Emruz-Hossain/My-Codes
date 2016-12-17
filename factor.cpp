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
vector<int>vp[30000003];
void tkf(int x,int n)
{
    if(n==1)
        return;
    vp[x].push_back(n);
    tkf(x,prime_factor[n].second);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    generate_factor(30000000);
//    for(i=1;i<=200;i++)
//        printf("%d = %d %d\n",i,prime_factor[i].first,prime_factor[i].second);
    for(i=1;i<=30000000;i++)
    {
        vp[i].push_back(prime_factor[i].first);
        tkf(i,prime_factor[i].second);
    }
    return 0;
}
