#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string ,string>mp;
struct st
{
    char ct1[100],ct2[100];
    int cost;
}E[60000];
bool cmp(st a,st b)
{
    return a.cost<b.cost;
}
string parent(string u)
{
   if(u.compare(mp[u])==0)
        return u;
    else
        return mp[u]=parent(mp[u]);
}
int main()
{
    int t,i,j,n,total,node,edge;
    string p,q;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        total=0;
        scanf("%d %d",&node,&edge);
        for(i=0;i<edge;i++)
        {
            scanf("%s %s %d",&E[i].ct1,&E[i].ct2,&E[i].cost);

            mp[E[i].ct1]=E[i].ct1;
            mp[E[i].ct2]=E[i].ct2;
        }
        sort(E,E+edge,cmp);
        for(i=0;i<edge;i++)
        {
            p=parent(E[i].ct1);
            q=parent(E[i].ct2);
            if(p.compare(q)!=0)
            {
                if(p.compare(q)>0)
                    mp[q]=p;
                else
                    mp[p]=q;
                 total+=E[i].cost;
            }

        }
        printf("%d\n",total);
        if(t!=0)
        printf("\n");
    }
 return 0;
}
