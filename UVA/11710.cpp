#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
vector<string>V;
map<string,string>mp;
struct st
{
    string s1;
    string s2;
    int cost;
}E[79900];
bool cmp(st a,st b)
{
    return a.cost<b.cost;
}
string find(string u)
{
    if(u.compare(mp[u])==0)
        return u;
    else
        return mp[u]=find(mp[u]);
}
int main()
{
    int n,c,i,j,l,ct,p;
    long long tc;
    string a,b,d,u,v;
    while(1)
    {
        tc=0;
        mp.clear();
        V.clear();
        scanf("%d %d",&n,&c);
        if(n==0&&c==0)
            break;
        for(i=0;i<n;i++)
        {
           cin>>a;
            V.push_back(a);
        }
        for(i=0;i<c;i++)
        {
           cin>>a>>b>>ct;
            E[i].s1=a;
            E[i].s2=b;
            E[i].cost=ct;
            mp[a]=a;
            mp[b]=b;
        }
        sort(E,E+c,cmp);
        cin>>d;
        for(i=0;i<c;i++)
        {
            u=find(E[i].s1);
            v=find(E[i].s2);
            if(u.compare(v)!=0)
            {
                if(u.compare(v)>0)
                    mp[v]=u;
                else
                    mp[u]=v;
                tc+=E[i].cost;
            }

        }
        a=mp[d];
        p=1;
        if(c==0||n==1)
            p=0;
        else
        {
        for(i=0;i<V.size();i++)
        {
            if(mp[V[i]].compare(a)!=0)
                {
                    p=0;
                    break;
                }
        }
        }
        if(p==0)
            printf("Impossible\n");
        else
            printf("%lld\n",tc);
    }
    return 0;
}
