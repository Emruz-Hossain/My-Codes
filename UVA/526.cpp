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
#include<strstream>
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
 int dp[100][100];
char s1[100],s2[100];
 vector<string>v;
 int l1,l2;
 void rec(int i,int j,int n)
 {
     string s;
     int d1,d2;
    if(i<0&&j<0)
        return;
    if(i-1>=0&&j-1>=0&&dp[i-1][j-1]==n-1)
     {
         s+="C";s+=s2[j-1];
         v.PB(s);
        rec(i-1,j-1,n-1);
     }
     else if(i-1>=0&&dp[i-1][j]==n-1)
     {
        v.PB("D");
        rec(i-1,j,n-1);
     }
     else if(j-1>=0&&dp[i][j-1]==n-1)
     {
         s+="I";s+=s2[j-1];
        v.PB(s);
        rec(i,j-1,n-1);
     }
    else
    {
        if(i>0&&j>0)
        v.PB("X");
         rec(i-1,j-1,n);
    }
     return ;
 }
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,a;
    string s,ss;
    tmp=0;
    while(gets(s1))
    {
        gets(s2);
        l1=len(s1);
        l2=len(s2);
        for(i=0;i<=l2;i++)
            dp[0][i]=i;
        for(i=0;i<=l1;i++)
            dp[i][0]=i;
        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                a=1+dp[i][j-1];
                d=1+dp[i-1][j];
                c=dp[i-1][j-1];
                if(s1[i-1]!=s2[j-1])
                    c++;
                dp[i][j]=min(a,min(d,c));
            }
        }
//        for(i=0;i<=l1;i++)
//        {
//            for(j=0;j<=l2;j++)
//                printf("%d ",dp[i][j]);
//            printf("\n");
//        }
        v.clear();
        rec(l1,l2,dp[l1][l2]);
        p=1;
        if(tmp>0)
            printf("\n");
        tmp++;
        printf("%d\n",dp[l1][l2]);
        x=1;
        for(i=v.size()-1;i>=0;i--)
        {
            if(v[i][0]!='X')
            {
            if(v[i][0]=='I')
            {
               printf("%d Insert %d,%c\n",x,p,v[i][1]);
               p++;
               x++;
            }
            else if(v[i][0]=='C')
            {
                printf("%d Replace %d,%c\n",x,p,v[i][1]);
                p++;
                x++;
            }
            else if(v[i][0]=='D')
            {
                 printf("%d Delete %d\n",x,p);
                 x++;
            }
            }
            else
                p++;
        }
    }
    return 0;
}


