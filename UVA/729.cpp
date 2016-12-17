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
string ar;
int N,H;

vector<string>V;
void backtrack(int ind,int p)
{
    int i;
    if(ind>N)
        return;
    if(p==H&&ind==N)
    {
        V.push_back(ar);
    }
    ar[ind]='1';
    backtrack(ind+1,p+1);
    ar[ind]='0';
    backtrack(ind+1,p);
}
int main()
{
       // freopen("output.txt","w",stdout);
       // freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        V.clear();
        ar.clear();
        scanf("%d %d",&N,&H);
        for(i=0;i<N;i++)
            ar+='0';
        backtrack(0,0);
        sort(V.begin(),V.end());
        for(i=0;i<V.size();i++)
            cout<<V[i]<<endl;
        if(t>0)
            cout<<endl;
    }
    return 0;
}
