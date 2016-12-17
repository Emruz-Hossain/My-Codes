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
int n;
vector<int>V;
int visit[20];
int prime(int n)
{
    int i,p=1;
    for(i=2;i<=sqrt(n);i++)
    {

        if(n%i==0)
        {
            p=0;
            break;
        }
    }
    return p;
}
int check(vector<int>E)
{
    int i,j,p;
    for(i=0,j=1;i<E.size()-1;i++,j++)
    {
     if(prime(E[i]+E[j]))
        p=1;
     else
     {
          p=0;
          break;
     }

    }
    if(p==1)
    p=prime(V[0]+V[V.size()-1]);
    return p;
}
void pring()
{
    int p,i,j;
    if(V.size()==n)
    {
        p=0;
        if(V[0]==1)
            p=check(V);
        if(p==1)
        {
            for(j=0;j<V.size();j++)
            {
                printf("%d",V[j]);
                if(j<V.size()-1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    for(i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            V.PB(i);
            visit[i]=1;
            pring();
            visit[i]=0;
            V.pop_back();
        }
    }
    return;
}
int main()
{
       //freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int x=1;;
    while(scanf("%d",&n)==1)
    {

        printf("Case %d:\n",x++);
        memset(visit,0,sizeof(visit));
        pring();
    }

    return 0;
}



