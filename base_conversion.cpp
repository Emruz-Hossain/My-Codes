#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n,base;
    scanf("%d %d",&n,&base);
    vector<int>v;
    while(n)
    {
        v.push_back(n%base);
        n=n/base;
    }
    for(int i=v.size()-1;i>=0;i--)
        printf("%d",v[i]);
    printf("\n");
}
