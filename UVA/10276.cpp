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
vector<int>E[70];
int n,maxx;
void order(int p)
{
    int i,u,q,j;

    for(i=0;i<n;i++)
    {
        if(E[i].size()!=0)
        {
            u=E[i].back();
            q=sqrt(u+p);
        }
        if(E[i].size()==0||q*q==u+p)
        {
            maxx=max(maxx,p);
            E[i].push_back(p);
            order(p+1);
            break;
        }
    }
}
int main()
{
        //freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        maxx=0;
        for(i=0;i<=70;i++)
            E[i].clear();
        scanf("%d",&n);
        order(1);
        printf("%d\n",maxx);
    }

    return 0;
}

