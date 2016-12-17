#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,s,m,i,d,p[200],j,mi,k,x,r;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        d=0;
        scanf("%d",&s);
        for(j=0;j<s;j++)
            scanf("%d",&p[j]);
        sort(p,p+s);
        m=p[0];
        for(j=0;j<s;j++)
        {
            d+=p[j]-m;
            m=p[j];
        }
        d*=2;
        printf("%d\n",d);
    }
}
