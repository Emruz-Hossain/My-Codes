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
struct st
{
    double d,p;
}ar[100];
double Dis,cap,dip,m,ans;
int k,s;
void backtrack(int ind,double last,double cost,double rem)
{
    double d,r;
    if(ind>=s)
    {
        k=1;
        return;
    }
    if(rem==0.00)
        return;
    d=Dis-last;
    if(d/dip>=rem)
    {
        ans=min(ans,cost);
        return;
    }
    backtrack(ind+1,last,cost,rem);
    r=d/dip;
    if((r>rem&&r<cap/2)||(ans==double(inf)&&k==1))
        backtrack(ind+1,ar[ind].d,cost+200.0+(cap-rem)*ar[ind].p,cap);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,cost,t=1;
    while(1)
    {
        k=0;
        ans=double(inf);
        scanf("%lf",&Dis);
        if(Dis<0)
            break;
        scanf("%lf %lf %lf %d",&cap,&dip,&m,&s);
        for(i=0;i<s;i++)
        {
            scanf("%lf %lf",&ar[i].d,&ar[i].p);
        }
        cost=m*100.00;
        backtrack(0,0.00,cost,cap);
        ans=ans/100.0;
        printf("Data Set #%d\n",t++);
        printf("minimum cost = $%.2lf\n",ans);
    }

    return 0;
}
