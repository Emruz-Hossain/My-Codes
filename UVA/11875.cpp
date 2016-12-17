#include<stdio.h>
int main()
{
    int t,age[100],i,j,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&age[j]);
        printf("Case %d: %d\n",i,age[n/2]);
    }
        return 0;
}
