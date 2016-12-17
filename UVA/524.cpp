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
int ar[20],n,visit[20];
vector<int>V;
void backtrack(void)
{
    int i,p,d;
    if(V.size()==n)
    {
        d=abs(V[0]+V[n-1]);
        if(d==2||d==3||d==5||d==7||d==11||d==13||d==17||d==19||d==23||d==29||d==31)
        {
        for(i=0;i<n;i++)
        {
            printf("%d",V[i]);
            if(i<n-1)
                printf(" ");
        }
        printf("\n");
        }
    }
    p=V.back();
    for(i=0;i<n-1;i++)
    {
        if(visit[i]==0)
        {
            d=abs(p+ar[i]);
            if(d==2||d==3||d==5||d==7||d==11||d==13||d==17||d==19||d==23||d==29||d==31)
            {
                visit[i]=1;
                V.push_back(ar[i]);
                backtrack();
                visit[i]=0;
                V.pop_back();
            }
        }
    }
}
int main()
{
    //   freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t=1,i;
    while(scanf("%d",&n)==1)
    {
        V.clear();
        if(t>1)
            printf("\n");
        memset(visit,0,sizeof(visit));
        printf("Case %d:\n",t++);
        for(i=0;i<=n-2;i++)
            ar[i]=i+2;
        V.push_back(1);
        backtrack();
    }
    return 0;
}

