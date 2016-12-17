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
 int digit[]={1,2,3,4,5,6,7,8,9},ans;
 vector<int>E;
 int check_runaround(vector<int>vv,int len)
 {
     int i,j,p,vis[12],k,d;
     mem(vis,0);
     d=0;k=0;
     while(d<vv.size())
     {
         p=vv[k];
         p=p%len;
         if(p==0)
            return 0;
         for(j=k+1;p;j++)
         {
             p--;
             if(j==vv.size())
                j=0;
            if(p==0)
            {
                if(vis[j]==1)
                    return 0;
                vis[j]=1;
                k=j;
            }

         }
         d++;
     }
     return 1;
 }
 vector<int>v;
 int visit[12];
 void creat_number(int len)
 {
     int i,k,num;
     if(v.size()==len)
     {
         k=check_runaround(v,len);
         if(k==1)
         {
             num=0;
             for(i=0;i<v.size();i++)
             {
                 num=num*10+v[i];
             }
             E.push_back(num);
         }
         return;
     }
     for(i=0;i<9;i++)
     {
         if(visit[i]==0)
         {
             visit[i]=1;
             v.push_back(digit[i]);
             creat_number(len);
             v.pop_back();
             visit[i]=0;
         }
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   for(i=2;i<=7;i++)
   {
       creat_number(i);
   }
   l=E.size();
   t=0;
   while(sf("%d",&n)==1)
   {
       if(n==0)
        break;
       ++t;
       for(i=0;i<l;i++)
        if(E[i]>=n)
       {
           pf("Case %d: %d\n",t,E[i]);
           break;
       }
   }
    return 0;
}
