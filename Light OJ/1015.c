#include<stdio.h>
int main()
{
    int t,i,dust[1050],total,j,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        total=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&dust[j]);
            if(dust[j]<0)
                dust[j]=0;
            total+=dust[j];
        }
        printf("Case %d: %d\n",i,total);
    }
    return 0;
}
