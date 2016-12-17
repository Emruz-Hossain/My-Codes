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
    int p,v;
}ar[100009];
bool cmp(st a,st b)
{
    return (a.v<b.v)?true:false;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q,r,l,t,cst;
    scanf("%d",&t);
    while(t--)
    {
        cst=0;d=0;m=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i].v);
            ar[i].p=i;
            if(ar[i].v>=0)
                m+=ar[i].v;
            else
                d+=ar[i].v;
        }
        sort(ar,ar+n,cmp);
        i=0;j=n-1;
        while(d)
        {
            if(ar[j].v>abs(ar[i].v))
            {
                ar[j].v+=ar[i].v;
                cst+=abs(ar[i].v)*(j-i);
                d+=ar[i].v;
                ar[i].v=0;
                i++;
            }
            else if(ar[j].v<abs(ar[i].v))
            {
                ar[i].v+=ar[j].v;
                cst+= abs(ar[j].v)*(j-i);
                d+=abs(ar[j].v);
                ar[j].v=0;
                j--;
            }
            else
            {
                d+=ar[j].v;
                cst+=abs(ar[i].v)*(j-i);
                ar[i].v=0;
                ar[j].v=0;

                i++;j--;
            }
        }
        printf("%d\n",cst);
    }


    return 0;
}
