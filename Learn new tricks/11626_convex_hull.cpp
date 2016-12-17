//BISMILLAHIR RAHMANIR RAHIM

//use of Two pivots
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
 P ar[100005],pvt,pvt2;
 bool cmp1(P a,P b)
 {
     if(a.y==b.y)
        return (a.x<b.x)?true:false;
     else
        return(a.y<b.y)?true:false;
 }
 bool cmp2(P b,P a)
 {
     double k=crp(mkv(pvt,a),mkv(pvt,b));
     if(k<0.0)
        return true;
     else if(k>0.0)
        return false;
     else
     {
        double r=crp(mkv(pvt,pvt2),mkv(pvt,a));
        //printf("a= %lf %lf b=%lf %lf r=%lf\n",a.x,a.y,b.x,b.y,r);
         double dst1=sqrt((pvt.x-a.x)*(pvt.x-a.x)+(pvt.y-a.y)*(pvt.y-a.y));
         double dst2=sqrt((pvt.x-b.x)*(pvt.x-b.x)+(pvt.y-b.y)*(pvt.y-b.y));
         if(r<0.0)
         return(dst1>dst2)?true:false;
         else
             return(dst1<dst2)?true:false;
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    scanf("%d",&t);
    while(t--)
    {
        P pp;
        char ss[10];
        scanf("%d",&n);
        d=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf %s",&pp.x,&pp.y,&ss);
            if(ss[0]=='Y')
            {
                ar[d++]=pp;
            }
        }
        sort(ar,ar+d,cmp1);
        pvt=ar[0];
        pvt2=ar[d-1];
        sort(ar+1,ar+d,cmp2);
        vector<P>v;
        double mx=1000000009.0;
        int ind=0;
        for(i=0;i<d;i++)
        {
            if(ar[i].x<mx)
            {
                mx=ar[i].x;
                ind=i;
            }
        }
//        printf("---------------\n");
//        for(i=0;i<d;i++)
//            printf("%lf %lf\n",ar[i].x,ar[i].y);
//        printf("---------------------\n");
        for(i=ind;i<d;i++)
            v.push_back(ar[i]);
        for(i=0;i<ind;i++)
            v.push_back(ar[i]);
        printf("%d\n",d);
        for(i=0;i<d;i++)
        {
            if(v[i].x<0.0)
                v[i].x-=eps;
            else
                v[i].x+=eps;
            if(v[i].y<0.0)
                v[i].y-=eps;
            else
                v[i].y+=eps;
            a=v[i].x;
            b=v[i].y;
             printf("%d %d\n",a,b);
        }

    }

    return 0;
}

