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
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    p=0;
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    x3=x1;y3=y1+d;x4=x2;y4=y2+d;
    if((x1==x3&&y1==y2&&x2==x4&&y3==y4))
        p=1;
    x3==x2;y3=y2+d;x4=x1;y4=y1+d;
    if((x1==x4&&y1==y2&&x2==x3&&y3==y4))
        p=1;
    x3=x1+d;y3=y1;x4=x2+d;y4=y2;
    if(x1==x2&&y1 ==y3&&x3==x4&&y2==y4)
    return 0;
}

