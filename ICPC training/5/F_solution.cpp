#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int maxn=1005;
struct node{
    int x,y;
}f[maxn],ff[maxn];
int a[maxn],b[maxn],c[maxn],g[maxn];
int vis[maxn];
int t,num,gg,num2,hh;
int nx[maxn];
int judge(int n)
{
    int i,j,k;
    memset(vis,0,sizeof(vis));
    sort(b+1,b+n+1);
    num=0;
    for(i=1;i<=n;i++)
    {
        if(b[i]==c[i])continue;
        if(vis[i])continue;
        for(j=i+1;j<=n;j++)
        {
            if(vis[j])continue;
            if(b[i]==c[j]&&b[j]==c[i])
            {
                f[num].x=i;
                f[num++].y=j;
                vis[j]=1;
                swap(c[i],c[j]);
            }
        }
        vis[i]=1;
    }
    for(i=1;i<=n;i++)
        if(b[i]!=c[i])return 0;
    if(num==0)printf("0\n");
    else
    {
        printf("1\n%d",num);
        for(i=0;i<num;i++)
            printf(" %d %d",f[i].x,f[i].y);
        printf("\n");
    }
    return 1;
}
int main()
{
    //freopen("D:\\out.txt","r",stdin);
    //freopen("D:\\out2.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k,u,v,t1,t2;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            c[i]=b[i]=a[i];
        }
        if(!judge(n))
        {
            memset(vis,0,sizeof(vis));
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(vis[j])continue;
                    if(a[i]==b[j])
                    {
                        nx[i]=j;
                        vis[j]=1;
                        break;
                    }
                }
                //printf("*%d\n",nx[i]);
            }
            num=0;
            memset(vis,0,sizeof(vis));
            for(i=1;i<=n;i++)
            {
                if(vis[i])continue;
                gg=0;
                j=i;
                while(nx[j]!=i)
                {
                    g[gg++]=j;
                    vis[j]=1;
                    j=nx[j];
                }
                g[gg++]=j;
                //printf("gg:%d\n",gg);
                vis[j]=1;
                if(gg<3)continue;
                j=1;k=gg-1;
                while(j<k)
                {
                    f[num].x=g[j];
                    f[num++].y=g[k];
                    swap(nx[g[j]],nx[g[k]]);
                    j++;
                    k--;
                }
                /*for(int x=1;x<gg;x+=2){
                if(gg-x+1<3) break;
                int u=g[x],v=g[gg-1];
                swap(g[x],g[gg-1]);
                f[num].x=u;
                f[num++].y=v;
                swap(nx[g[x]],nx[g[gg-1]]);
                int k=g[gg-1];
                for(int j=gg-1;j>x+1;j--) g[j]=g[j-1];
                g[x+1]=k;
                }*/
            }
            printf("2\n%d",num);
            for(i=0;i<num;i++)
            printf(" %d %d",f[i].x,f[i].y);
            printf("\n");

            /*for(i=0;i<num;i++)
                swap(a[f[i].x],a[f[i].y]);*/

            num=0;
            for(i=1;i<=n;i++)
            {
                if(nx[i]!=i)
                {
                    f[num].x=i;
                    f[num++].y=nx[i];
                    nx[nx[i]]=nx[i];
                }
            }
            printf("%d",num);
            for(i=0;i<num;i++)
            printf(" %d %d",f[i].x,f[i].y);
            printf("\n");

            /*for(i=0;i<num;i++)
                swap(a[f[i].x],a[f[i].y]);
            for(i=0;i<n;i++)
                if(a[i]!=b[i])break;
            if(i<n)printf("NO\n");
            else printf("YES\n");*/
        }
    }
    return 0;
}
