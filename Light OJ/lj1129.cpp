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
    int endm,npt;
    int ar[12];
};
st tri[10009];
char ss[10009];
int root;
int built(int ind,int l,int rt)
{
  int ch;
    if(ind>=l)
        return 0;
    else if(tri[ind].endm==1)
        return 1;
    else
    {
        ch=ss[ind]-'0';
        if(tri[rt].ar[ch]==0)
        {
           tri[rt].ar[ch]=1;
           root++;
           tri[rt].npt=rt=root;
           if(ind==l-1)
                tri[ind].endm=1;
           return built(ind+1,l,rt);
        }
        else
            return built(ind+1,l,tri[rt].npt);
    }

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q=10005,r,l,t;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        p=0;
        root=0;
         for(i=0;i<=q;i++)
        {
            tri[i].endm=0;
            tri[i].npt=0;
            for(j=0;j<10;j++)
                tri[i].ar[j]=0;
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",&ss);
            l=strlen(ss);
           p=max(p,built(0,l,0));
        }
        if(p==1)
            printf("Case %d: YES\n",x);
        else
            printf("Case %d: NO\n",x);
        q=root;
    }

    return 0;
}

