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
vector<string>E;
int CA,CB,n,p;
void backtrack(int M,int N)
{
    int i;
    if(N==n)
    {
        p=1;
        for(i=0;i<E.size();i++)
        {
            cout<<E[i]<<endl;
        }
        cout<<"success"<<endl;
        return;
    }
    if(p==0)
    {
    if(M<CA)
    {
         E.push_back("fill A");
         backtrack(CA,N);
         E.pop_back();
    }
    if(N<CB)
    {
        E.push_back("fill B");
        backtrack(M,CB);
        E.pop_back();
    }
    if(M<CA)
    {
        E.push_back("pour B A");
        if(M+N>=CA)
            backtrack(CA,N-(CA-M));
        else
        backtrack(M+N,0);
        E.pop_back();

    }
    if(N<CB)
    {
        E.push_back("pour A B");
        if(M+N>=CB)
            backtrack(M-(CB-N),CB);
        else
        backtrack(0,M+N);
        E.pop_back();
    }
    if(M!=0)
    {
        E.push_back("empty A");
        backtrack(0,N);
        E.pop_back();
    }
    if(N!=0)
    {
        E.push_back("empty B");
        backtrack(M,0);
        E.pop_back();
    }
    }

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    while(scanf("%d %d %d",&CA,&CB,&n)==3)
    {
        E.clear();
        p=0;
        backtrack(0,0);
    }

    return 0;
}

