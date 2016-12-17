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

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct st
{
    int mass,iq,pos;
}ar[1005];
map<int,map<int,int> >dp;
int d, Lis[1005],seq[1005];
bool cmp(st a,st b)
{
    if(a.mass<b.mass)
        return true;
    else if(a.mass>b.mass)
    return false;
    else
        return(a.iq>b.iq)?true:false;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,top,mx;
    d=0;
    while(scanf("%d %d",&p,&q)==2)
    {
        ar[d].mass=p;
        ar[d].iq=q;
        ar[d].pos=d+1;
        d++;
    }
    sort(ar,ar+d,cmp);
   for(i=0;i<=d;i++)
    Lis[i]=1;
    for(i=0;i<d;i++)
    {
        for(j=i+1;j<d;j++)
        {
            if(ar[i].iq>ar[j].iq&&ar[i].mass<ar[j].mass)
                Lis[j]=max(Lis[j],Lis[i]+1);
        }
    }
    mx=0;
    for(i=0;i<d;i++)
    {
        if(Lis[i]>Lis[mx])
        {
             mx=i;
        }

    }
    sm=Lis[mx];
    top=Lis[mx]-1;
    seq[top]=ar[mx].pos;
    top--;
    for(i=mx-1;i>=0;i--)
    {
        if(ar[i].iq>ar[mx].iq&&Lis[i]==Lis[mx]-1)
        {
            seq[top]=ar[i].pos;
            mx=i;
            top--;
        }
    }
    printf("%d\n",sm);
    for(i=0;i<sm;i++)
       printf("%d\n",seq[i]);
    return 0;
}

