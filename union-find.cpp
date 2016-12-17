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
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int rankk[sz],parent[sz];
int findd(int i)
{
    int res;
    if(parent[i]==i)
        return i;
    else
    {
        res=findd(parent[i]);
        parent[i]=res;
        return res;
    }
}
void unionn(int i,int j)
{
     int ip,jp,ir,jr;
     ip=findd(i);
     jp=findd(j);
     ir=rankk[ip];
     jr=rankk[jp];
     if(ip==jp)
        return;
     if(ir<jr)
        parent[ir]=jr;
    else if(ir>jr)
        parent[jr]=ir;
     else
     {
          parent[ir]=jr;
          rankk[jr]++;
     }

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int n,m,i,j,u,v;
    while(scanf("%d %d",&n,&m))
    {
        for(i=1;i<=n;i++)
        {
            parent[i]=i;
            rankk[i]=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            unionn(u,v);
        }
        for(i=1;i<=n;i++)
            printf("%d ",i);
        printf("\n");
        for(i=1;i<=n;i++)
            printf("%d ",parent[i]);
    }


    return 0;
}


