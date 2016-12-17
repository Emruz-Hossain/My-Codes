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

 char ss[105][105];
 char s2[105]={'A','L','L','I','Z','Z','W','E','L','L'};
 int n,m,visit[105][105],flag;
 void dfs(int x,int y,int k)
 {
     int i,j,p,q;
     if(k==10)
     {
         flag=1;
         return;
     }
     if(!flag)
     {
    for(i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&p<n&&q>=0&&q<m&&visit[p][q]==0&&ss[p][q]==s2[k])
        {
            visit[p][q]=1;
            dfs(p,q,k+1);
            visit[p][q]=0;
        }
    }
     }
 }
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    sf("%d",&t);
    getchar();
    while(t--)
    {
        sf("%d %d",&n,&m);
        getchar();
        flag=0;
        for(i=0;i<n;i++)
           {
               scanf("%s",&ss[i]);
           }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                  if(ss[i][j]=='A')
                  {
                      mem(visit,0);
                      visit[i][j]=1;
                      dfs(i,j,1);
                      if(flag)
                        break;
                  }
            }
            if(flag)
                break;
        }
        if(flag)
            pf("YES\n");
        else
            pf("NO\n");
    }
    return 0;
}
