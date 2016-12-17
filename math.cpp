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
int ar[]={0,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49};
vector<int>v;
void rec(int p,int sm,int tk)
{
    int i;
    if(p>25)
        return;
    if(tk==5)
    {
        if(sm==53)
        {
            printf("%d\n",sm);
            for(i=0;i<v.size();i++)
            {
                printf("%d ",v[i]);
            }
            printf("\n");

        }
    }
    v.push_back(ar[p+1]);
    rec(p+1,sm+ar[p+1],tk+1);
    v.pop_back();
    rec(p+1,sm,tk);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q,r,l;
    rec(0,0,0);
    printf("Impossible\n");
    return 0;
}
