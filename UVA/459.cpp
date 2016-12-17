
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
#define sz 200
vector<int>E[sz];
int visit[sz];
char ss[sz];
void dfs(int p)
{
    int i,ch;
    if(visit[p]==1)
        return;
    visit[p]=1;
    for(i=0;i<E[p].size();i++)
    {
        ch=E[p][i];
        if(visit[ch]==0)
            dfs(ch);
    }
}
int main()
{
         //freopen("output.txt","w",stdout);
    int t,cmp,tt,i;
    char x,y,n,ch;
    scanf("%d%c",&t,&ch);
    getchar();
    while(t--)
    {
        cmp=0;
        memset(visit,0,sizeof(visit));
        gets(ss);
        n=ss[0];
        while(gets(ss))
        {

            if(strlen(ss)<=0)
                break;
            E[ss[0]-64].push_back(ss[1]-64);
            E[ss[1]-64].push_back(ss[0]-64);
        }
    tt=n-64;
    for(i='A'-64;i<=tt;i++)
    {

        if(visit[i]==0)
        {
        dfs(i);
        cmp++;
        }


    }
    printf("%d\n",cmp);
    if(t>0)
    {
         printf("\n");
        // getchar();
    }
    for(i=0;i<=tt;i++)
        E[i].clear();
    }
    return 0;
}
