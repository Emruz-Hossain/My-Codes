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
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int ar[100],i,j,n,k,t,cnt,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        p=0;
        for(i=0;i<n;i++)
        {
            cnt=0;
            for(j=i;j<n;j++)
            {
                if(ar[j]%2==0)
                    cnt++;
                if(cnt==k)
                {
                    p=1;
                    break;
                }
            }

        }
        if(p==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}


