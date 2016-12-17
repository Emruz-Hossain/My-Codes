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
    int st,des,ps;
}E[50],b;
vector<st>taken;
int cap,n,m,ans,k;
int visit[50];
int update(int r)
{
    int i,sum=0;
    for(i=0;i<taken.size();i++)
    {
        sum+=taken[i].ps;
        if(taken[i].des<=r)
            sum-=taken[i].ps;
    }
    return sum;

}
void backtrack(int ind,int tk)
{
    ans=max(tk,ans);
    if(ind>=n)
        return;

     int l=update(E[ind].st);
    if(E[ind].ps+l<=cap)
    {
        b.st=E[ind].st;
        b.des=E[ind].des;
        b.ps=E[ind].ps;
        taken.push_back(b);
        backtrack(ind+1,tk+(E[ind].des-E[ind].st)*E[ind].ps);
        taken.pop_back();
    }
    backtrack(ind+1,tk);
}
bool cmp(st a,st b)
{
    return(a.st<b.st)?true:false;

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i;
    while(1)
    {
        memset(E,0,sizeof(E));

        memset(visit,0,sizeof(visit));
        ans=0;
        scanf("%d %d %d",&cap,&m,&n);
        if(cap==0&&m==0&&n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&E[i].st,&E[i].des,&E[i].ps);
        }
        sort(E,E+n,cmp);
        for(i=0;i<n;i++)
        {
            taken.clear();
            if(E[i].ps<=cap)
            {
                b.st=E[i].st;
                b.des=E[i].des;
                b.ps=E[i].ps;
                taken.push_back(b);
                backtrack(i+1,(E[i].des-E[i].st)*E[i].ps);
            }

        }
        printf("%d\n",ans);

    }

    return 0;
}

