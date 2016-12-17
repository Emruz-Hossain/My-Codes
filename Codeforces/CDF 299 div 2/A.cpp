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
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   map<int,string>mp;
   mp[1]="one";
   mp[2]="two";
    mp[3]="three";
     mp[4]="four";
      mp[5]="five";
       mp[6]="six";
        mp[7]="seven";
         mp[8]="eight";
          mp[9]="nine";
    mp[10]="ten";
    mp[11]="eleven";
    mp[12]="twelve";
    mp[13]="thirteen";
    mp[14]="fourteen";
    mp[15]="fifteen";
    mp[16]="sixteen";
    mp[17]="seventeen";
    mp[18]="eighteen";
    mp[19]="nineteen";
     mp[20]="twenty";
      mp[30]="thirty";
       mp[40]="forty";
        mp[50]="fifty";
         mp[60]="sixty";
          mp[70]="seventy";
           mp[80]="eighty";
            mp[90]="ninety";
        sf("%d",&n);
        if(n<=20||n==30||n==40||n==50||n==60||n==70||n==80||n==90)
           cout<<mp[n]<<endl;
        else if(n>20&&n<30)
        {
          cout<<mp[20]<<"-"<<mp[n-20]<<endl;
        }
         else if(n>30&&n<40)
        {
              cout<<mp[30]<<"-"<<mp[n-30]<<endl;
        }
         else if(n>40&&n<50)
        {
             cout<<mp[40]<<"-"<<mp[n-40]<<endl;
        }
         else if(n>50&&n<60)
        {
             cout<<mp[50]<<"-"<<mp[n-50]<<endl;
        }
         else if(n>60&&n<70)
        {
             cout<<mp[60]<<"-"<<mp[n-60]<<endl;
        }
         else if(n>70&&n<80)
        {
             cout<<mp[70]<<"-"<<mp[n-70]<<endl;
        }
         else if(n>80&&n<90)
        {
             cout<<mp[80]<<"-"<<mp[n-80]<<endl;
        }
         else if(n>90&&n<100)
        {
             cout<<mp[90]<<"-"<<mp[n-90]<<endl;
        }
    return 0;
}
