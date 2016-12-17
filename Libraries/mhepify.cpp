//OUM NAMA MA SWARASATI



#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
vector<int> n;
int vis[100005];
void mhpfy(int p,int s,int ch)
{
    int mc,im;
    vis[p]=1;

    if(p<1||p>s)
        return;

    if(2*p>s&&2*p+1>s)
        return;

    if(2*p<=s&&!vis[2*p])
        mhpfy(2*p,s,1);

    if(2*p+1<=s&&!vis[2*p])
        mhpfy(2*p+1,s,1);

    if(2*p<=s&&2*p+1<=s)
        mc=n[2*p]<n[2*p+1]?2*p+1:2*p;
    else mc=2*p;

    if(n[p]<n[mc])
    {
        im=n[mc],n[mc]=n[p],n[p]=im;
    }
    if(ch==1)return;
    mhpfy(p/2,s,0);
}
int main()
{
    int s,i,a;
    scanf("%d",&s);
    n.clear(),n.push_back(0);
    memset(vis,0,sizeof(vis));
    for(i=1;i<=s;i+=1)
    {

        scanf("%d",&a);
        n.push_back(a);
    }

    mhpfy(s/2,s,0);
    for(i=1;i<=s;i++)
        cout<<n[i]<<" ";
    while(n.size()!=1)
    {
        cout<<n[1]<<" ";
        s=n.size();
        n[1]=n[s-1];
        n.pop_back();
        memset(vis,0,sizeof(vis));
        mhpfy(1,s,0);
    }
return 0;
}


