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
int D[524290];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
//int a,b,c,d,m,n,p,x,i,j,q,r,l;
int t,i,ind,M;
int H,N,A,B,X,X1,X2;
double area;

    scanf("%d",&t);
    while(t--)
    {
        area=0.00;
        scanf("%d %d %d %d %d %d",&H,&N,&M,&A,&B,&ind);
        for(i=0;i<M;i++)
        scanf("%d",&D[i]);
        X=0;
        for(i=1;i<N;i+=2)
        {
            X1=X+D[ind];
            ind=(A*ind+B)%M;
            X2=X1+D[ind];
            ind=(A*ind+B)%M;
            X=X2;
            area+=(double)0.5*(X2-X)*H;
        }
        if((N-1)%2==1)
        {
            X1=X+D[ind];
            ind=(A*ind+B)%M;
            X2=X1;
            area+=(double)(0.5*(X2-X)*H);
        }
        printf("%.1lf\n",area);

    }

    return 0;
}
