#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    char ss[1005][30],s2[30];
    vector<string>v;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sprintf(s2,"%d.mp3",i);
       // strcpy(ss[i-1],s2);
        v.push_back(s2);
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    {
       cout<<v[i]<<endl;
    }
    return 0;
}
