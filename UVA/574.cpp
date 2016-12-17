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
vector<int>E[10000],V;
int r,n,t,ar[100];
void backtrack(int ind,int sum)
{
    int i;
    if(sum==t)
    {
            for(i=0;i<V.size();i++)
                E[r].push_back(V[i]);
        r++;
    }
    if(sum>t)
        return;
    for(i=ind;i<n;i++)
    {
         V.push_back(ar[i]);
        backtrack(i+1,sum+ar[i]);
        V.pop_back();
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j;
    while(1)
    {
        scanf("%d %d",&t,&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<=r;i++)
            E[i].clear();
        r=0;

        for(i=0;i<n;i++)
        {
            V.clear();
            backtrack(i,0);
        }
        for(i=0;i<r-1;i++)
        {            for(j=i+1;j<r;j++)
            if(E[i]==E[j])
                E[j].clear();
        }
        printf("Sums of %d:\n",t);
        if(r==0)
            printf("NONE\n");
        else
        {
            for(i=0;i<r;i++)
            {
                if(E[i].size()!=0)
                {
                    for(j=0;j<E[i].size();j++)
                    {
                        if(j==0)
                            printf("%d",E[i][j]);
                        else
                        printf("+%d",E[i][j]);

                    }
                    printf("\n");
                }
            }
        }

    }

    return 0;
}

