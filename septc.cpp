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
int ar[1000009];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int m,n,i,ind=0,d;
    char ch,ss[100];
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&ar[i]);
    while(m--)
    {

        getchar();
        gets(ss);
        sscanf(ss,"%c %d",&ch,&d);
        if(ch=='C')
            ind-=d;
        else if(ch=='A')
        ind+=d;
        else if(ch=='R')
            printf("%d\n",ar[(d+ind)%n]);
    }

    return 0;
}

