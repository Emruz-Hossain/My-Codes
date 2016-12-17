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
char ss[1000005];
int l;
int check()
{
    int i=0,j=l-1;
    while(i<j)
    {
        if(ss[i]=='*')
            i++;
        else if(ss[j]=='*')
        {
            j--;
        }
        else
        {
            if(ss[i]!=ss[j])
                return 0;
            else
            {
                i++;j--;
            }
        }
    }
    return 1;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,q,r,t,cnt,sm,tmp,k1,k2,t1,t2;
    scanf("%d",&x);
    while(x--)
    {
        scanf("%s",&ss);
        l=strlen(ss);
        if(l<=8000)
        {
        char ch;
        p=0;
        for(i=0;i<l;i++)
        {
            ch=ss[i];
            ss[i]='*';
            p=check();
            if(p==1)
                break;
            else
                ss[i]=ch;
        }
        if(p==0)
            printf("NO\n");
        else
            printf("YES\n");
        }
        else
        {
            i=0;
        j=l-1;
        p=0;
        while(i<j)
        {
            if(ss[i]==ss[j])
            {
                i++;
                j--;
            }
            else
            {
                r=i+1+j+1;
                if(r%2==0)
                {
                    k1=r/2;
                    k2=k1-1;
                }
                else
                {
                    k1=(r/2)-1;
                    k2=r/2+1;
                }
                t=i+j-1+1;
                if(t%2==0)
                {
                    t1=t/2;
                    t2=t1-1;
                }
                else
                {
                    t1=t/2-1;
                    t2=t/2+1;
                }
                if(ss[i+1]==ss[j]&&(ss[k1]==ss[k2]))
                {
                    i++;
                    p++;
                }
                else if(ss[i]==ss[j-1]&&ss[t1]==ss[t2])
                {
                    j--;
                    p++;
                }
                else
                {
                    p=5;
                    break;
                }
            }
        }
        if(p>1)
            printf("NO\n");
        else
            printf("YES\n");
        }
    }

    return 0;
}


