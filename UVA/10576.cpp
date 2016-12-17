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
int s,d;
long long ans;
vector<int>V;
int validate(void)
{
    int i,j,cnt=0;
    long long sum;
    for(i=0;i<8;i++)
    {
        sum=0;
        for(j=i;j<i+5;j++)
        {
            sum+=V[j];
        }
        if(sum<0)
            cnt++;
    }
    if(cnt==8)
        return 1;
    else
        return 0;
}
void backtrack(void)
{
    int p,i;
    long long sum;
    if(V.size()>12)
        return;
    if(V.size()==12)
    {
        p=validate();
        if(p==1)
        {
            sum=0;
            for(i=0;i<V.size();i++)
                sum+=V[i];
            ans=max(ans,sum);
        }
        return;
    }
    V.push_back(s);
    backtrack();
    V.pop_back();
    V.push_back(d);
    backtrack();
    V.pop_back();
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    while(scanf("%d %d",&s,&d)==2)
    {
        d=-1*d;
        ans=-1*inf;
        backtrack();
        if(ans>=0)
            printf("%lld\n",ans);
        else
            printf("Deficit\n");
    }

    return 0;
}
