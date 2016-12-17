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
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q,r,l,t;

    scanf("%d",&t);
    while(t--)
    {
        a=0;b=0;p=0;
        scanf("%s",&ss);
        for(i=0;i<strlen(ss);i++)
        {
            if(ss[i]=='a')
                a++;
            else
                b++;
        }
        l=strlen(ss);
        for(i=0,j=l-1;i<j;i++,j--)
        {
            if(ss[i]==ss[j])
                continue;
            else
            {
                p=1;
                break;
            }
        }
        if(a==0||b==0||p==0)
            printf("1\n");
        else
            printf("2\n");
    }

    return 0;
}
