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
 int dp[1001][1001],dir[1001][1001],l2;
 char ss[1005];
 string s,s1,s2,s3;
 int rec(int i,int j,int tkn)
 {
     int p,q;
     if(tkn>=l2)
        return inf;
     if(i==j||i>j)
        return 0;
     if(dp[i][j]!=-1)
        return dp[i][j];
     if(ss[i]==ss[j])
     {
         return dp[i][j]=rec(i+1,j-1,tkn);
     }
     else
     {
         p=rec(i,j-1,tkn+1)+1;
         q=rec(i+1,j,tkn+1)+1;
         if(p<q)
            dir[i][j]=1;
        else
            dir[i][j]=-1;
        return dp[i][j]=min(p,q);
     }
 }
 void prn(int i,int j)
 {
     if(i==j)
     {
         s1+=ss[i];
         return;
     }
    if(i>j)
        return;
    if(ss[i]==ss[j])
    {
        s1+=ss[i];
        s2+=ss[j];
        prn(i+1,j-1);
    }
    else
    {
        if(dir[i][j]==1)
        {
            s1+=ss[j];
            s2+=ss[j];
            prn(i,j-1);
        }
        else
        {
            s2+=ss[i];
            s1+=ss[i];
            prn(i+1,j);
        }
    }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    while(sf("%s",&ss)==1)
    {
        mem(dp,-1);
        l=len(ss);
        l2=l;
        m=rec(0,l-1,0);
       // pf("%d\n",m);
        s1.clear();
        s2.clear();
        prn(0,l-1);
        s.clear();
        l=s2.size();
        s3.clear();
        for(i=l-1;i>=0;i--)
            s3+=s2[i];
        s=s1+s3;
        cout<<m<<" "<<s<<endl;
    }
    return 0;
}
