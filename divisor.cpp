#include<stdio.h>
int main()
{
    int n,i;
    while(scanf("%d",&n)==1)
{
    for(i=1;i<=n/2;i++)
        printf("%d ",n/i);
}
    return 0;
}
