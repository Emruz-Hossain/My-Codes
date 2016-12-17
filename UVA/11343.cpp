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
struct st
{
    P fp,sp;
}ar[300];
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}
 int check(P a1,P a2,P b1,P b2)
 {
     double v1,v2,v3,v4,marea1,area1,area2,marea2,area3,area4;
     P l1=mkv(a1,a2);
     P l2=mkv(b1,b2);
     v1=crp(l1,mkv(a1,b1));
     v2=crp(l1,mkv(a1,b2));
     v3=crp(l2,mkv(b1,a1));
     v4=crp(l2,mkv(b1,a2));
     if((v1*v2-0.0)<eps&&(v3*v4-0.0)<eps)
     {
         if(v1*v2<0.0&&v3*v4<0.0)
            return 1;
          else if((v1-0.0)<eps&&(v2-0.0)<eps&&(v3-0.0)<eps&&(v4-0.0)<eps)
            {
             if((a1.x==b1.x&&a1.y==b1.y)||(a1.x==b2.x&&a1.y==b2.y)||(a2.x==b1.x&&a2.y==b1.y)||(a2.x==b2.x&&a2.y==b2.y))
                return 1;
             else
                return 0;
            }
            else
            {
                marea1=ART(a1,a2);
                area1=ART(a1,b1)+ART(a2,b1);
                area2=ART(a1,b2)+ART(a2,b2);
                marea2=ART(b1,b2);
                area3=ART(b1,a1)+ART(b1,a2);
                area4=ART(b2,a1)+ART(b2,a2);
                if(fabs(marea1-area1)<eps||fabs(marea1-area2)<eps||(marea2-area3)<eps||(marea2-area4)<eps)
                    return 1;
                else
                    return 0;
            }
     }
     else
        return 0;
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf %lf %lf %lf",&ar[i].fp.x,&ar[i].fp.y,&ar[i].sp.x,&ar[i].sp.y);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                p=check(ar[i].fp,ar[i].sp,ar[j].fp,ar[j].sp);
                if(p==1)
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

