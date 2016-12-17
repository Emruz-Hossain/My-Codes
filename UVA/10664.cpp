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
int ar[100];
char ss[100005],sq[100];
int dp[30][300],sm,d;
int rec(int ind,int p)
{
    int r=0,q=0;
    if(ind>=d)
    {
        if(p==sm/2)
            return 1;
        else
            return 0;
    }
    if(dp[ind][p]!=-1)
        return dp[ind][p];
    if(p+ar[ind]<=sm/2)
    r=rec(ind+1,p+ar[ind]);
    q=rec(ind+1,p);
    return dp[ind][p]=r||q;

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,m,n,p,x,y,i,j,k,l,q,r,t,cnt,tmp;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        gets(ss);
        r=0; d=0,sm=0;
        for(i=0;i<strlen(ss);i++)
        {
            if(i==strlen(ss)-1)
            {
                sq[r]=ss[i];
                sq[r+1]='\0';
                sscanf(sq,"%d",&ar[d++]);
                sq[0]='\0';
                r=0;
            }
            else if(ss[i]==' '&&ss[i-1]!=' ')
            {
                sq[r]='\0';
                sscanf(sq,"%d",&ar[d++]);
                sq[0]='\0';
                r=0;
            }
            else
            {
                sq[r++]=ss[i];
            }
        }
        sm=0;
        for(i=0;i<d;i++)
        {
            sm+=ar[i];
        }
        if(sm%2!=0)
        {
            printf("NO\n");
        }
        else
        {
            p=rec(0,0);
            if(p==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
//        for(i=0;i<d;i++)
//        {
//            printf("%d ",ar[i]);
//        }
//        printf("\n");
    }

    return 0;
}

