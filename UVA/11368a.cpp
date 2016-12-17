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
    int w,h;
} ar[20003];
bool cmp(st a,st b)
{
    if(a.w>b.w)
        return true;
    else if(a.w<b.w)
        return false;
    else
    {
        return(a.h<b.h)?true:false;
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].w,&ar[i].h);
        }
        sort(ar,ar+n,cmp);
        vector<st>v;
        st a;
        for(i=0;i<n;i++)
        {
            if(v.size()==0)
            {
                a.h=ar[i].h;
                a.w=ar[i].w;
                v.push_back(a);
            }
            else
            {
                l=0;h=v.size()-1;
                p=-1;
                while(l<=h)
                {
                    m=(l+h)/2;
                    a.w=v[m].w;
                    a.h=v[m].h;
                    if(v[m].w>ar[i].w&&v[m].h>ar[i].h)
                    {
                        h=m-1;
                        p=m;
                    }
                    else

                       l=m+1;
                }
                if(p==-1)
                {
                    a.h=ar[i].h;
                    a.w=ar[i].w;
                    v.push_back(a);
                }
                else
                {
                v[p].h=ar[i].h;
                v[p].w=ar[i].w;
                }
            }
        }
        printf("%d\n",v.size());
    }

    return 0;
}

