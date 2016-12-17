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
#define sz 300
#define eps 1e-9
char str[sz][sz];
int visit[sz][sz],k;
int R[]={-1,0,1,-1,0,1};
int C[]={-1,-1,0,0,1,1};
void dfs(int x,int y,int n,char ch)
{
    int p,q,i;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    for(i=0;i<6;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<n&&q<n&&str[p][q]==ch)
        {
            if(ch=='b')
            {
                if(p==n-1)
                    k=1;
                dfs(p,q,n,ch);

            }
            else
            {
                if(q==n-1)
                    k=1;
                dfs(p,q,n,ch);
            }
        }
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,i,n,d;
    t=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
            t++;
            memset(visit,0,sizeof(visit));
            k=0;d=0;
        for(i=0;i<n;i++)
            scanf("%s",&str[i]);
        for(i=0;i<n;i++)
        {
           if(str[0][i]=='b'&&visit[0][i]==0)
            dfs(0,i,n,'b');
           if(k==1)
           {
                 printf("%d B\n",t);
                d=1;
           }
           if(d==1)
            break;

        }
        if(d==0)
        for(i=0;i<n;i++)
        {
           if(str[i][0]=='w'&&visit[i][0]==0)
            dfs(i,0,n,'w');
           if(k==1)
           {
                 printf("%d W\n",t);
                d=1;
           }
            if(d==1)
                break;
        }
    }


    return 0;
}


