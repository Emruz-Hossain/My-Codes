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
char ss[100009];
int main()
{
    //    freopen("output.txt","w",stdout);
       // freopen("output.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    long long i,t,l;
    long long ans;
    scanf("%lld",&t);

    while(t--)
    {
        ans=1;
        scanf("%s",&ss);
        l=strlen(ss);
        for(i=0;i<l;i++)
        {
            if(ss[i]=='l')
            {
               if(i%2==1)
                ans=(ans*2-1)%mod;
               else
                ans=(ans*2)%mod;

            }
            else
            {
                if(i%2==1)
                    ans=(ans*2+1)%mod;
                else
                ans=(ans*2+2)%mod;
            }
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}

