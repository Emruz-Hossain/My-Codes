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
 struct st
 {
     int a[7];
 }E[1000005];
 int ar[1000005],ANS[1000005][5][5];
 int mp[150];
 char ss[1000005];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   char s1[10],s2[10];
   mp['c']=0;mp['h']=1;mp['e']=2;mp['f']=3;
    sf("%s",&ss);
    l=strlen(ss);
    E[0].a[0]=E[0].a[1]=E[0].a[2]=E[0].a[3]=0;
    for(i=0;i<l;i++)
    {
        ar[i]=mp[ss[i]];
    }
    if(ar[0]==0)
        E[0].a[0]=1;
    else if(ar[0]==1)
        E[0].a[1]=1;
    else if(ar[0]==2)
     E[0].a[2]=1;
    else
        E[0].a[3]=1;
    for(i=1;i<l;i++)
    {
        if(ar[i]==0)
            E[i].a[0]=E[i-1].a[0]+1;
        else
           E[i].a[0]=E[i-1].a[0];
        if(ar[i]==1)
            E[i].a[1]=E[i-1].a[1]+1;
       else
          E[i].a[1]=E[i-1].a[1];

         if(ar[i]==2)
            E[i].a[2]=E[i-1].a[2]+1;
        else
          E[i].a[2]=E[i-1].a[2];

          if(ar[i]==3)
            E[i].a[3]=E[i-1].a[3]+1;
        else
          E[i].a[3]=E[i-1].a[3];
    }
    for(i=0;i<l;i++)
        pf("%d ",E[i].a[0]);
    pf("\n");
     for(i=0;i<l;i++)
        pf("%d ",E[i].a[1]);
    pf("\n");
     for(i=0;i<l;i++)
        pf("%d ",E[i].a[2]);
    pf("\n");
     for(i=0;i<l;i++)
        pf("%d ",E[i].a[3]);
    pf("\n");
    for(j=0;j<4;j++)
    {
        for(k=0;k<4;k++)
        {
            ANS[0][j][k]=0;
        }
    }
    for(i=1;i<l;i++)
    {
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                if(j!=k)
                {
                    p=E[i-1].a[j];
                    if(i==4&&j==0&&k==3)
                        pf("%d\n",p);
                    if(E[i].a[k]==E[i-1].a[k])
                    {
                        ANS[i][j][k]=ANS[i-1][j][k];
                    }
                    else
                    {
                        //pf("%d\n",p);
                         ANS[i][j][k]=ANS[i-1][j][k]+p;
                    }

                }
            }
        }
    }
    for(i=0;i<l;i++)
    {
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                pf("i=%d j=%d k=%d   ans= %d\n",i,j,k,ANS[i][j][k]);
            }
        }
    }
    sf("%d",&q);
    while(q--)
    {
        sf("%s %s %d %d",&s1,&s2,&l,&h);
        x=mp[s1[0]];
        y=mp[s2[0]];
        l--;
        h--;
        p=E[h].a[y]-E[l].a[y];
        pf("p=%d\n",p);
        r=ANS[h][x][y]-ANS[l-1][x][y]*p;
        pf("%d\n",r);
    }
    return 0;
}

