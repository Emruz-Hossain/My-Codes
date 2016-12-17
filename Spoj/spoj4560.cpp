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
#include<ctime>
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

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct st
{
    int a,b;
};
st ar[10005],br[10005];
int Find(int p)
{
    int l=0,h=10000,m,r=0;
    while(l<h)
    {
        m=(l+h)/2;
        if(br[m].a==p)
        {
            r=1;
             break;
        }
        else if(br[m].a>p)
        {
            if(br[m-1].a>p)
                h=m-1;
            else
            {
                if(br[m-1].a==p)
                {
                    r=1;m=m-1;break;
                }
                else
                    break;
            }
        }
        else
        {
            if(br[m+1].a==p)
            {
                r=1;
                m=m+1;
                break;
            }
            else if(br[m+1].a<p)
            {
                l=m+1;
            }
            else
                break;
        }
    }
    if(r==0)
        return 0;
    else
        return m;
}
int main()
{
    //    freopen("output.txt","w",stdout);2
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    while(1)
    {
        for(i=0;i<10005;i++)
        {
            ar[i].a=0;ar[i].b=0;br[i].a=0; br[i].b=0;
        }
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i].a);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&br[i].a);
        for(i=n-1;i>=0;i--)
        {
            ar[i].b=ar[i].a+ar[i+1].a;
        }
        for(i=m-1;i>=0;i--)
        {
            br[i].b=br[i].a+br[i+1].a;
        }
        p=0;q=0;
        for(i=n-1;i>=0;i--)
        {
            k=Find(ar[i].a);
            if(k==0)
                continue;
            else
            {
                p=max(p,br[m].b+q-ar[i].b-p);
                q=max(q,ar[i].b+p-br[m].b-q);
            }
        }
        printf("%d\n",max(ar[0].b+p,br[0].b+q));


    }

    return 0;
}

