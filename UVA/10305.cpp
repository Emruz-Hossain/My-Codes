//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
#define s 1000
vector<int>E[s];
queue<int >Q;
int visit[s],ind[s];
int main()
{
    int n,m,u,v,i,j,x;
    while(1)
    {
        memset(visit,0,sizeof(visit));
        memset(ind,0,sizeof(ind));
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
            E[i].clear();
        if(n==0&&m==0)
            break;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            ind[v]++;
            E[u].push_back(v);
        }
        for(j=1;j<=n;j++)
        {
            if(ind[j]==0)
            {
                Q.push(j);
                visit[j]=1;
            }
        }
        x=0;
        while(!Q.empty())
            {
                u=Q.front();
                Q.pop();
                if(x>0)printf(" ");
                printf("%d",u);
                x++;
                for(i=0;i<E[u].size();i++)
                {
                    v=E[u][i];
                    ind[v]--;
                }
                for(i=1;i<=n;i++)
                {
                    if(visit[i]==0&&ind[i]==0)
                    {
                        Q.push(i);
                        visit[i]=1;
                    }
                }
            }
            printf("\n");
    }
 return 0;
}

