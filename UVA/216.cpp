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
struct st
{
    int x,y;
}ar[10],a;
vector<st>v,E;
int n,visit[10];
double mn;
void rec(void)
{
    int i;
    if(v.size()==n)
    {
        double d=0.00;
        for(i=1;i<v.size();i++)
        {
           int p=v[i].x-v[i-1].x;
           int q=v[i].y-v[i-1].y;
           d+=(sqrt(p*p+q*q)+16.00);
        }
        if(d<mn)
        {
            mn=d;
            E.clear();
            E.resize(n);
            for(i=0;i<v.size();i++)
                E[i]=v[i];
        }
//        printf("d=%lf\n",d);
//        for(i=0;i<v.size();i++)
//            printf("%d %d\n",v[i].x,v[i].y);
//        printf("_______________________________\n");
    }
    for(i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            a.x=ar[i].x;
            a.y=ar[i].y;
            v.push_back(a);
            visit[i]=1;
            rec();
            v.pop_back();
            visit[i]=0;
        }
    }
}
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,m,x,y,i,j,k,l,r,t,cnt,sm,tmp;
    double tl,p,q,d;
    x=0;
    while(1)
    {
        ++x;
        scanf("%d",&n);
        if(n==0)
            break;
            E.clear();
            memset(visit,0,sizeof(visit));
        E.resize(n);
        mn=(double)2000000;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].x,&ar[i].y);
        }
        rec();
        printf("**********************************************************\n");
        printf("Network #%d\n",x);
        tl=0.00;
        for(i=1;i<E.size();i++)
        {
            p=E[i].x-E[i-1].x;
            q=E[i].y-E[i-1].y;
            d=sqrt(p*p+q*q)+16.00;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",E[i-1].x,E[i-1].y,E[i].x,E[i].y,d);
            tl+=d;
        }
        printf("Number of feet of cable required is %.2lf.\n",tl);

    }

    return 0;
}
