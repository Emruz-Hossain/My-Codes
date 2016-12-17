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
 int l,n,p;
 char ss[1000005];
 vector<int>v;
 void rec(int i,int prev)
 {
     if(i>=l)
     {
         p=1;
         return;
     }
     if(p==1)
        return;
     if(ss[i]=='A')
     {
        if(prev==0||prev==7||prev==8)
        {
             v.push_back(5);
             rec(i+1,5);
        }
        else if(prev==4||prev==1||prev==5)
        {
            v.push_back(0);
            rec(i+1,0);
        }
         else
         return;
     }
     else if(ss[i]=='B')
     {

        if(prev==0||prev==2||prev==6)
        {
             v.push_back(1);
             rec(i+1,1);
        }
        else if(prev==1||prev==8||prev==9)
        {
            v.push_back(6);
            rec(i+1,6);
        }
        else
        return;
     }
     else if(ss[i]=='C')
     {

        if(prev==1||prev==7||prev==3)
        {
             v.push_back(2);
             rec(i+1,2);
        }
        else if(prev==2||prev==5||prev==9)
        {
            v.push_back(7);
            rec(i+1,7);
        }
        else
            return;
     }
     else if(ss[i]=='D')
     {

        if(prev==2||prev==4||prev==8)
        {
             v.push_back(3);
             rec(i+1,3);
        }
        else if(prev==3||prev==5||prev==6)
        {
            v.push_back(8);
            rec(i+1,8);
        }
        else
            return;
     }
     else if(ss[i]=='E')
     {

        if(prev==0||prev==3||prev==9)
        {
             v.push_back(4);
             rec(i+1,4);
        }
        else if(prev==4||prev==6||prev==7)
        {
            v.push_back(9);
            rec(i+1,9);
        }
        else
            return;
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int b,c,d,h,m,x,y,i,j,k,q,r,t,cnt,sm,tmp;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();p=0;
        scanf("%s",&ss);
        l=strlen(ss);
        if(ss[0]=='A')
         {
             v.push_back(0);
             rec(1,0);
             if(p==0)
             {
                 v.clear();
                 v.push_back(5);
                 rec(1,5);
             }
         }
         else if(ss[0]=='B')
         {
             v.push_back(1);
             rec(1,1);
             if(p==0)
             {
                 v.clear();
                 v.push_back(6);
                 rec(1,6);
             }
         }
         else if(ss[0]=='C')
         {
             v.push_back(2);
             rec(1,2);
             if(p==0)
             {
                 v.clear();
                 v.push_back(7);
                 rec(1,7);
             }
         }
         else if(ss[0]=='D')
         {
             v.push_back(3);
             rec(1,3);
             if(p==0)
             {
               v.clear();
                 v.push_back(8);
                 rec(1,8);
             }
         }
         else if(ss[0]=='E')
         {
             v.push_back(4);
             rec(1,4);
             if(p==0)
             {
                v.clear();
                 v.push_back(9);
                 rec(1,9);
             }
         }
        if(p==0)
            printf("-1\n");
        else
        {
            l=v.size();
            for(i=0;i<l;i++)
                printf("%d",v[i]);
            printf("\n");
        }
    }
    return 0;
}
