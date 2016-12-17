//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
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

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct P
{
    double x,y;
    P(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    int ar[12][12];
    memset(ar,0,sizeof(ar));
    cnt=0;
    ar[0][0]=1;ar[0][1]=1;
    ar[1][1]=1;ar[2][2]=1;ar[3][1]=1;ar[3][3]=1;ar[4][1]=1;ar[4][4]=1;ar[5][5]=1;ar[6][5]=1;ar[6][6]=1;
    ar[7][1]=1;ar[7][7]=1;ar[8][0]=1;ar[8][1]=1;ar[8][2]=1;ar[8][3]=1;ar[8][4]=1;ar[8][5]=1;ar[8][6]=1;
    ar[8][7]=1;ar[8][8]=1;ar[8][9]=1;ar[9][5]=1;ar[9][1]=1;ar[9][7]=1;ar[9][9]=1;ar[9][3]=1;ar[3][7]=1;ar[0][7]=1;ar[9][4]=1;
    scanf("%d",&n);
    if(n<10)
    {
        p=0;
        q=n;
    }
    else
    {
        q=n%10;
        p=n/10;
    }
    //printf("%d %d\n",p,q);
    for(i=0;i<100;i++)
    {
        if(i<10)
        {
            x=0;
            y=i;
        }
        else
        {
            y=i%10;
            x=i/10;
        }
        if((ar[x][p]==1&&ar[y][q]==1))
            cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}
