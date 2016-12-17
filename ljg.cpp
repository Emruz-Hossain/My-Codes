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
char prm[10000009];
int ar[100],br[100];
char ss[100];
void sieve()
{
    int n,i,j;
    n=10000007;
    for(i=4;i<=n;i+=2)
        prm[i]='*';
    for(i=3;i*i<=n;i+=2)
    {
        for(j=2;j*i<=n;j++)
            prm[i*j]='*';
    }
    prm[1]='*';
    prm[0]='*';
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q,r,l,k;
    sieve();
    scanf("%d",&a);

    for(x=1;x<=a;x++)
    {
        n=0;
        scanf("%s",&ss);
        for(i=strlen(ss)-1,j=0;i>=0;i--,j++)
        {
            d=ss[i]-48;
            n+=d*pow(2,j);
        }

        if(prm[n]!='*')
            printf("Case %d: YES\n",x);
        else
        {
            for(i=n;i<=10000007;i++)
            {
                if(prm[i]!='*')
                    break;
            }
            for(j=n;j>=0;j--)
            {
                if(prm[j]!='*')
                    break;
            }
            if(j<0)
                i=2;
            else if(i-n<n-j)
                i=i;
            else if(i-n>n-j)
                i=j;
            else
                i=j;
            k=0;
            while(i)
            {
                ar[k++]=i%2;
                i=i/2;
            }
            for(i=k-1,j=0;i>=0;i--,j++)
                br[j]=ar[i];
            printf("Case %d: ",x);
            for(i=0;i<k;i++)
                printf("%d",br[i]);
            printf("\n");
        }
    }

    return 0;
}

