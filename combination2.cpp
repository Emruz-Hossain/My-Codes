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
char ss[100];
vector<char>V;
int l,visit[100];
void backtrack()
{
    int i;
    if(V.size()==l)
    {
        for(i=0;i<l;i++)
            printf("%c",V[i]);
        printf("\n");
    }
    for(i=0;i<l;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            V.PB(ss[i]);
            backtrack();
            visit[i]=0;
            V.pop_back();
        }
    }
}
int main()
{
       // freopen("output.txt","w",stdout);
       // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    scanf("%s",&ss);
    l=strlen(ss);
    backtrack();
    return 0;
}
