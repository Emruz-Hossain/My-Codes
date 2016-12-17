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

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    while(1)
    {
    scanf("%d %d",&n,&m);
    if(m==0&&n==0)
        break;
    vector< vector<int> >ar(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
   vector<int>d(m,-1),d1(m),d2(m);
   stack<int>st;
   sm=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(ar[i][j]==1)
                d[j]=i;
        }
        while(!st.empty())st.pop();
        for(j=0;j<m;j++)
        {
            while(!st.empty()&&d[st.top()]<=d[j])st.pop();
            d1[j]=(st.empty())?-1:st.top();
            st.push(j);
        }
        while(!st.empty())st.pop();
        for(j=m-1;j>=0;j--)
        {
            while(!st.empty()&&d[st.top()]<=d[j]) st.pop();
            d2[j]=(st.empty())?m:st.top();
            st.push(j);
        }
        for(j=0;j<m;j++)
        sm=max(sm,(i-d[j])*(d2[j]-d1[j]-1));
    }
    printf("%d\n",sm);
    }
    return 0;
}
