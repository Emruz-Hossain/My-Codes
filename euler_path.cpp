//BISMILLAHIR RAHMANIR RAHIM
//MD: EMRUZ HOSSAIN
//CSE 12 SEC: B
//ID: 1204084
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
int visit[500][500];
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,node,edge,u,v;
     vector<int>E[500];
     int degree[500];
    scanf("%d %d",&n,&edge);

    for(i=0;i<edge;i++)
    {
        scanf("%d %d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
     p=0;
    for(i=1;i<=n;i++)
    {
        degree[i]=E[i].size();
        if(degree[i]%2==1)
        {
            p++;
            k=i;
        }
        if(E[i].size()==0||p>2)
        {
            printf("No Euler path.\n");
            return 0;
        }
    }
    stack<int>STK;
    vector<int>path;
    int cur;
    if(p!=0)
        STK.push(k);
    else
        STK.push(1);
    while(!STK.empty())
    {
        cur=STK.top();
            k=-1;
           while(E[cur].size())
           {
               p=E[cur].back();
               if(visit[cur][p]==0)
               {
                   visit[cur][p]=1;
                   visit[p][cur]=1;
                   k=1;
                    break;
               }
               else
                E[cur].pop_back();
           }
           if(k!=-1)
            STK.push(p);
            else
            {
                path.push_back(cur);
                STK.pop();
            }
        }
    for(i=path.size()-1;i>=0;i--)
        printf("%d ",path[i]);
    printf("\n");
    return 0;
}
