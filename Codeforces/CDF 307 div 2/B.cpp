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
int MOD(int a,int b){int r=a%b;return r<0?r+b:r;}
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
 int mp1[300],mp2[300],mp3[300];
 char ss1[100005],ss2[100005],ss3[100005],ans1[100005],ans2[100005];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,l1,l2,l3,cnt1,cnt2,mn1,mn2;
   sf("%s %s %s",&ss1,&ss2,&ss3);
   l1=strlen(ss1);
   l2=strlen(ss2);
   l3=strlen(ss3);
   mem(mp1,0);
   mem(mp2,0);
   mem(mp3,0);
   for(i=0;i<l1;i++)
   {
       mp1[ss1[i]]++;
   }
   for(i=0;i<l2;i++)
    mp2[ss2[i]]++;
   for(i=0;i<l3;i++)
    mp3[ss3[i]]++;
    mn1=10000000;
   for(i='a';i<='z';i++)
   {
       if(mp2[i]!=0)
       {
           mn1=min(mn1,mp1[i]/mp2[i]);
       }
   }
   mn2=10000000;
   for(i='a';i<='z';i++)
   {
       if(mp3[i]!=0)
       {
           mn2=min(mn2,mp1[i]/mp3[i]);
       }
   }
   if(mn1==0&&mn2==0)
    pf("%s\n",ss1);
   else
   {
       j=0;
       while(mn1!=0||mn2!=0)
       {
           if(mn1>mn2)
           {
              for(i=0;i<l2;i++)
              {
                  ans1[j]=ss2[i];
                  mp1[ss2[i]]--;
                  j++;
              }
               mn2=10000000;
               for(i='a';i<='z';i++)
               {
                 if(mp3[i]!=0)
                 {
                     mn2=min(mn2,mp1[i]/mp3[i]);
                  }
                }
                mn1--;
          }
          else
          {
              for(i=0;i<l3;i++)
              {
                  ans1[j]=ss3[i];
                  mp1[ss3[i]]--;
                  j++;
              }
               mn1=10000000;
               for(i='a';i<='z';i++)
               {
                 if(mp2[i]!=0)
                 {
                     mn1=min(mn1,mp1[i]/mp2[i]);
                  }
                }
                mn2--;
          }
       }
       for(i=j;i<l1;i++)
       {
           for(k='a';k<='z';k++)
           {
               if(mp1[k]>0)
               {
                   mp1[k]--;
                   ans1[i]=k;
                   break;
               }
           }
       }
       }
       ans1[l1]='\0';

       pf("%s\n",ans1);


    return 0;
}
