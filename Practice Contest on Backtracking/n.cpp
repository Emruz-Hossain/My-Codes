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
#include<iomanip>c
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
 int ans,visit[10][10],mm;
 struct st
 {
   int col,row;
 };
 vector<st>v;
 vector<string>E;
 void SET(int x,int y,int p)
 {
     int i,j;
     for(i=y;i<8;i++)
        visit[x][i]+=p;
    for(i=y;i>=0;i--)
        visit[x][i]+=p;
     for(i=x;i<8;i++)
        visit[i][y]+=p;
    for(i=x;i>=0;i--)
        visit[i][y]+=p;
     for(i=x,j=y;i<8&&j<8;i++,j++)
        visit[i][j]+=p;
     for(i=x,j=y;i>=0&&j>=0;i--,j--)
        visit[i][j]+=p;
     for(i=x,j=y;i<8&&j>=0;i++,j--)
        visit[i][j]+=p;
     for(i=x,j=y;i>=0&&j<8;i--,j++)
        visit[i][j]+=p;
 }
 bool cmp(st a,st b)
 {
     return a.col<b.col;
 }
 void backtrack(int ind)
 {
     int i,j;
     st a;
     if(v.size()==8)
     {
       vector<st>vv;
       for(i=0;i<v.size();i++)
        vv.push_back(v[i]);
       sort(vv.begin(),vv.end(),cmp);
        string ss;
        for(i=0;i<8;i++)
            ss+=vv[i].row+'0';
        E.push_back(ss);
        vv.clear();
        return;
     }
     if(ind==mm)
        backtrack(ind+1);
     else
     {
     for(i=0;i<8;i++)
     {
         if(visit[ind][i]==0)
         {
             SET(ind,i,1);
             a.row=ind+1;
             a.col=i+1;
             v.push_back(a);
             backtrack(ind+1);
             SET(ind,i,-1);
             v.pop_back();
         }
     }
     }
 }
int main()
{
      //  freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    sf("%d",&t);
   for(x=1;x<=t;x++)
    {
        v.clear();
        sf("%d %d",&p,&q);
        if(x>1)
            pf("\n");
        pf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        E.clear();
        mem(visit,0);
        SET(p-1,q-1,1);
        st a;
        a.col=q;
        a.row=p;
        mm=p-1;
        v.push_back(a);
        if(p>1)
          backtrack(0);
        else
            backtrack(1);
        sort(E.begin(),E.end());
        for(i=0;i<E.size();i++)
        {
            string sp=E[i];
            pf("%2d      ",i+1);
            for(j=0;j<sp.size();j++)
            {
                if(j>0)
                    pf(" ");
                pf("%c",sp[j]);
            }
            pf("\n");
        }
    }
    return 0;
}
