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
    int t,x,y,p;
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%d %d",&x,&y);
        if(x==0&&y==0)
            p=1;
        if(x>=0)
        {
            if(x%2==1)
            {
                if((y<=x+1)||(y>=-1*(x-1)))
                    p=1;
            }
            if(y%2==0)
            {
                if(y>=0&&x<=y-1)
                p=1;
                else if(y<0&&x<=-1*(y+1))
                p=1;
            }

        }
        else
        {
            if(x%2==0)
            {
                if(y>=0&&y<=-1*x)
                    p=1;
                else if(y<0&&y>=x)
                p=1;
            }
            if(y%2==0)
            {
                if(y>=0&&x>=-1*y)
                    p=1;
                else if(y<0&&x>=y)
                    p=1;
            }
        }
        if(p==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
