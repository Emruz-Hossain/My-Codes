//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<iomanip>
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

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
int cnt,ar[10],br[10],i,n;
void backtrack(int E[])
{
    int p=0,i,tmp;
    for(i=0;i<n;i++)
    {
        if(E[i]==br[i])
            p=1;
        else
        {
            p=0;
            break;
        }
    }
    if(p==1)
        cnt++;
    for(i=0;i<n-1;i++)
    {
        if(E[i]>E[i+1])
        {
            tmp=E[i+1];
            E[i+1]=E[i];
            E[i]=tmp;
            backtrack(E);
            tmp=E[i+1];
            E[i+1]=E[i];
            E[i]=tmp;
        }
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,p,t=1;
    while(1)
    {
        cnt=0;
        scanf("%d",&n);
        if(n==0)
            break;
       for(i=0;i<n;i++)
       {
             scanf("%d",&ar[i]);
             br[i]=ar[i];
       }
      sort(br,br+n);
      p=1;
      for(i=0;i<n;i++)
      {
            if(br[i]!=ar[i])
                p=0;
      }
      if(p==1)
        printf("There are 0 swap maps for input data set %d.\n",t);
      else
      {
          backtrack(ar);
          printf("There are %d swap maps for input data set %d.\n",cnt,t);
      }
      t++;

    }

    return 0;
}
