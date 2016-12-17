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
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define     mem(x,y) memset(x,y,sizeof(x))
#define     PB(x) push_back(x)
#define     POB() pop_back()
#define     SZ(a) a.size()
#define     len(a) strlen(a)
#define     sf scanf
#define     pf printf

#define     inf 1<<25
#define     sz 2000
#define     eps 1e-9
#define     mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}

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
 int ar[1001][1001];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    sf("%d %d %d",&n,&m,&k);
    mem(ar,0);
    sm=0;
    for(i=0;i<k;i++)
    {
        sf("%d %d",&p,&q);
        p--;q--;
        int up=-1,lft=-1,dn=-1,rht=-1,upr=-1,upl=-1,dnl=-1,dnr=-1;
       if(p-1>=0)
        up=ar[p-1][q];
       if(q-1>=0)
        lft=ar[p][q-1];
       if(p+1<n)
        dn=ar[p+1][q];
        if(q+1<m)
            rht=ar[p][q+1];
        if(p-1>=0&&q+1<m)
            upr=ar[p-1][q+1];
        if(p-1>=0&&q-1>=0)
            upl=ar[p-1][q-1];
        if(p+1<n&&q-1>=0)
            dnl=ar[p+1][q-1];
        if(p+1<n&&q+1<m)
            dnr=ar[p+1][q+1];
       // pf("up=%d dn=%d lft=%d rht=%d upr=%d upl=%d dnl=%d dnr=%d\n",up,dn,lft,rht,upr,upl,dnl,dnr);
        if((upl&&lft&&up&&up!=-1&&upl!=-1&&lft!=-1)||(up&&upr&&rht&&up!=-1&&upr!=-1&&rht!=-1)||(lft&&dnl&&dn&&lft!=-1&&dnl!=-1&&dn!=-1)||(rht&&dnr&&dn&&rht!=-1&&dn!=-1&&dnr!=-1))
        {
            if(sm==0)
            pf("%d\n",i+1);
            sm=1;
        }
        else
            ar[p][q]=1;
    }
    if(sm==0)
    pf("0\n");
    return 0;
}
