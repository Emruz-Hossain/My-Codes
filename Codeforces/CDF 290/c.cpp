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
 int visit[300][300],vis[300],vis2[300],par[300];
 char ss[300][300];
 vector<int>E[300],ans;
 void dfs(int ind)
 {
     int i;
     if(vis[ind]==1)
        return;
     vis[ind]=1;
     for(i=0;i<E[ind].size();i++)
     {
         if(vis[E[ind][i]]==0)
            dfs(E[ind][i]);
     }
     ans.push_back(ind);
 }
 int main()
 {
     int i,n,j,p,q,pp,qq,l1,l2,l;
     sf("%d",&n);
     for(i=0;i<n;i++)
     {
         sf("%s",ss[i]);
     }
     for(i=0;i<n-1;i++)
     {
         p=ss[i][0];
         q=ss[i+1][0];
         if(p==q)
         {
             l1=strlen(ss[i]);
             l2=strlen(ss[i+1]);
             l=min(l1,l2);
             for(j=1;j<l;j++)
             {
                 pp=ss[i][j];qq=ss[i+1][j];
                 if(pp==qq)
                    continue;
                 else
                 {
                     if(visit[pp][qq]==1)
                     {
                         pf("Impossible\n");
                         return 0;
                     }
                     else
                     {
                      E[pp].push_back(qq);
                     par[qq]=pp;
                     while(pp!=0)
                     {
                         if(visit[pp][qq]==1)
                         {
                             pf("Impossible\n");
                             return 0;
                         }
                         visit[qq][pp]=1;
                         pp=par[pp];
                     }
                     break;
                     }

                 }
             }
             if(j==l&&l2<l1)
             {
                 pf("Impossible\n");
                 return 0;
             }
         }
         else
         {
             if(visit[p][q]==1||vis2[p]||vis2[q])
             {
                 pf("Impossible\n");
                 return 0;
             }
             else
             {
                 E[p].push_back(q);
                 par[q]=p;
                 while(p!=0)
                 {
                     if(visit[p][q]==1)
                     {
                         pf("Impossible\n");
                         return 0;
                     }
                     visit[q][p]=1;
                     p=par[p];
                 }
             }
             vis2[p]=1;
         }
     }
     for(i='z';i>='a';i--)
     {
         if(vis[i]==0)
            dfs(i);
     }
     for(i=ans.size()-1;i>=0;i--)
        pf("%c",ans[i]);
     pf("\n");

     return 0;
 }
