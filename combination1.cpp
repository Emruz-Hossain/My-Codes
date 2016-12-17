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
using namespace std;
#define inf 1<<25
#define sz 2000
#define eps 1e-9
char str[]="01234";
vector<int>V;
int visit[100];
long long ar[100][100];
long long maxx=0;
void cmb(int n)
{
    long long sum,i;
    if(V.size()==n)
    {
       sum=ar[V[0]][V[1]]+ar[V[1]][V[0]]+2*ar[V[2]][V[3]]+2*ar[V[3]][V[2]]+ar[V[1]][V[2]]+ar[V[2]][V[1]]+2*ar[V[3]][V[4]]+2*ar[V[4]][V[3]];
       maxx=max(maxx,sum);
    }
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            V.push_back(str[i]-48);
            cmb(n);
            visit[i]=0;
            V.pop_back();
        }
    }
}
int main()
{
    int l,i,j;
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%I64d",&ar[i][j]);
        }
    }
    cmb(5);
    printf("%I64d\n",maxx);
    return 0;
}


