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
    long long a,b,c,d,m,n,p,x,i,j,q,r,l;
    scanf("%d",&a);
    for(x=1;x<=a;x++)
    {
        scanf("%d %d",&m,&n);
        printf("X^2");
        if(m>0||m<0)
        {
            if(m==1)
                printf("-x");
            else if(m>1)
                printf("%dx",-1*m);
            else if(m==-1)
                printf("+x");
            else if(m<-1)
                printf("+%dx",-1*x);
        }
        if(n>0||n<0)
        {
            if(n<0)
            printf("-%d",n);
            else
                printf("+%d",-1*n);
        }
        printf("=0\n");
    }

    return 0;
}

