
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

#define inf 1<<32
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
    long long mn,dd;
}A[100009];
long long ar[100009];
bool cmp(st a,st b)
{
    if(a.mn<b.mn)
        return true;
    else if(a.mn==b.mn&&a.dd<b.dd)
        return true;
    else
        return false;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long a,b,c,d,m,n,p,x,i,j,q,r,l,mn,dd,ind,ind2,k;
    scanf("%lld %lld",&n,&k);
    p=11;
    d=min(p,n-2+1);
    for(i=0;i<=n;i++)
    {
        A[i].dd=inf;
        A[i].mn=inf;
    }
    for(i=1;i<=n;i++)
        scanf("%lld",&ar[i]);
    for(i=n;i>=n-d;i--)
    {
        for(j=1;j<=n;j++)
        {
           ind=i-j;
           m=ar[i]-ar[j];
           dd=m/ind;
           ind2=i-1;
           p=ar[i]-dd*ind2;
           if(ar[i]>0&&p<0)
            p++;
           if(A[j].mn>p&&p>=10e-9)
           {
               A[j].mn=p;
               A[j].dd=dd;
           }
           else if(A[j].mn==p&&dd<A[j].dd)
            A[j].dd=dd;
        }
    }
    sort(A,A+n+1,cmp);
    for(i=0;i<n;i++)
    {
        x=k;
        dd=A[i].dd;
        mn=A[i].mn;
        for(j=1;j<=n;j++)
        {
            if(ar[j]!=mn)
                {
                    x--;
                    if(x<0)
                        break;
                }
            mn=mn+dd;
        }
        if(x>=0)
            break;
    }
    mn=A[i].mn;
    dd=A[i].dd;
    for(i=0;i<n;i++)
        {
            printf("%lld",mn);
            if(i<n-1)
                printf(" ");
            p=mn+dd;
            if(mn<0&&p>0)
                mn=p-1;
            else
                mn=p;
        }
        printf("\n");
    return 0;
}
