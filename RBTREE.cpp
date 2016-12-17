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
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,black,red,ans;
    char ss[100];
    black=1;red=2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&ss);
        if(strcmp(ss,"Qi")==0)
        {
            if(black==1)
            {
                 black=2;
                red=1;
            }
            else
            {
                black=1;
                red=2;
            }

        }
        if(strcmp(ss,"Qb")==0)
        {
            ans=0;
            scanf("%d %d",&x,&y);
            vector<int>v;
            if(x==y)
            {
                p=(int)log2(x)+1;
                 v.push_back(p);
            }

            else
            {
            while(x!=y)
            {
                if(x>y)
                {
                    p=(int)log2(x)+1;
                    v.push_back(p);
                     x=x/2;
                }
                if(y>x)
                {
                    p=(int)log2(y)+1;
                    v.push_back(p);
                     y=y/2;
                }
            }
            p=(int)log2(x)+1;
            v.push_back(p);
            }
            if(black==1)
            {
                for(i=0;i<v.size();i++)
                {
                    if(v[i]%2==1)
                        ans++;
                }
            }
            else
            {
                for(i=0;i<v.size();i++)
                {
                    if(v[i]%2==0)
                        ans++;
                }
            }
            printf("%d\n",ans);
            }
        else if(strcmp(ss,"Qr")==0)
            {
            ans=0;
            scanf("%d %d",&x,&y);
            vector<int>v;
            if(x==y)
            {
                p=(int)log2(x)+1;
                 v.push_back(p);
            }
            else
            {
            while(x!=y)
            {
                if(x>y)
                {
                    p=(int)log2(x)+1;
                      v.push_back(p);
                      x=x/2;
                }
                if(y>x)
                {
                    p=(int)log2(y)+1;
                    v.push_back(p);
                    y=y/2;
                }
            }
            p=(int)log2(x)+1;
            v.push_back(p);
            }
            if(red==1)
            {
                for(i=0;i<v.size();i++)
                {
                    if(v[i]%2==1)
                        ans++;
                }
            }
            else
            {
                for(i=0;i<v.size();i++)
                {
                    if(v[i]%2==0)
                        ans++;
                }
            }
            printf("%d\n",ans);
            }

        }

    return 0;
}
