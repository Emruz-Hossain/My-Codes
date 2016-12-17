#include<stdio.h>
#include<vector>
#include<queue>
#define max 2600
#define inf 1<<30
#include<string.h>
using namespace std;
vector<int>E[max];
queue<int>Q;
int day[max];
int main()
{
    int n,i,j,u,f,t,s,v,m,k,c,ind;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&f);
        for(j=0;j<f;j++)
        {
            scanf("%d",&u);
            E[i].push_back(u);
        }
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&s);
        for(j=0;j<n;j++)
            day[j]=inf;
        day[s]=0;
        Q.push(s);
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            for(j=0;j<E[u].size();j++)
            {
                v=E[u][j];
                if(day[v]>day[u]+1)
                {
                    day[v]=day[u]+1;
                    Q.push(v);
                }

            }
        }
        m=0;
        for(j=1;j<=n;j++)
        {
            c=0;
            for(k=0;k<n;k++)
            {
                if(day[k]==j)
                {
                    c++;
                }
            }
            if(m<c)
            {
                m=c;
                ind=j;
            }
        }
    if(m==0)
        printf("0\n");
    else if(m!=0)
        printf("%d %d\n",m,ind);
    }
    return 0;

}

