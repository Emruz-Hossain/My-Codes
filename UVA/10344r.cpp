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
int ar[10];
int backtrack(int total,int ind)
{
    int p,q,r;
    if(ind>4)
    {
        if(total==23)
            return 1;
        return 0;
    }
    p=backtrack(total+ar[ind],ind+1);
    q=backtrack(total-ar[ind],ind+1);
    r=backtrack(total*ar[ind],ind+1);
    return p|q|r;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int p;
    while(1)
    {
        p=0;
        scanf("%d %d %d %d %d",&ar[0],&ar[1],&ar[2],&ar[3],&ar[4]);
        if(ar[0]==ar[1]&&ar[2]==ar[3]&&ar[4]==0)
            break;
        sort(ar,ar+5);
        do
        {
            p=backtrack(ar[0],1);
            if(p)
                break;
        }while(next_permutation(ar,ar+5));
        if(p==1)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }


    return 0;
}
