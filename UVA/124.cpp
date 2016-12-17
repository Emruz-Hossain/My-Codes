
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
 vector<char>vs,E[200],ans;
 char cth;
 int ar[200][200],len,visit[200];
 void dfs(char ch)
 {
     int i;
     if(visit[ch]==1)
        return;
     visit[ch]=1;
    for(i=0;i<E[ch].size();i++)
    {
        if(visit[E[ch][i]]==0)
        {
          ar[cth][E[ch][i]]=1;
          ar[E[ch][i]][cth]=-1;
             dfs(E[ch][i]);
        }
    }
 }
 void backtrack(void)
 {
     int i,p,j;
     char ch3,ch4,ch5;
     if(ans.size()==len)
     {
        for(i=0;i<ans.size();i++)
        pf("%c",ans[i]);
        pf("\n");
         return;
     }
     for(i=0;i<len;i++)
     {
         p=1;
         ch4=vs[i];
         for(j=0;j<ans.size();j++)
         {
             ch5=ans[j];
             if(ar[ch5][ch4]==-1)
             {
                 p=0;
                 break;
             }
         }
         if(visit[vs[i]]==0&&(p||ans.size()==0))
         {
             visit[vs[i]]=1;
             ans.PB(vs[i]);
             backtrack();
             visit[vs[i]]=0;
             ans.POB();
         }
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   char ch1,ch2,ss[10005];
   cnt=0;
   while(gets(ss))
   {
       if(cnt==1)
        pf("\n");
       else
        cnt=1;
       l=strlen(ss);
       mem(ar,0);
       ans.clear();
       mem(visit,0);
       vs.clear();
       for(i=0;i<l;i+=2)
       {
           vs.PB(ss[i]);
       }
       len=vs.size();
       gets(ss);
       l=strlen(ss);
       for(i=0;i<l;i+=4)
       {
           ch1=ss[i];
           ch2=ss[i+2];
           E[ch1].PB(ch2);
           //pf("%c %c\n",ch1,ch2);
       }
       for(i='a';i<='z';i++)
       {
           mem(visit,0);
           cth=i;
            dfs(i);
       }
//       for(i='a';i<='z';i++)
//       {
//           for(j='a';j<='z';j++)
//            pf("%d ",ar[i][j]);
//           pf("\n");
//       }
       mem(visit,0);
       sort(vs.begin(),vs.end());
       backtrack();
       for(i='a';i<='z';i++)
        E[i].clear();
   }

    return 0;
}

