#include<stdio.h>
int main()
{
    int t,i,x1,y1,x2,y2,p,q,j,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&n);
        printf("Case %d:\n",i);
        for(j=1;j<=n;j++)
        {
            scanf("%d %d",&p,&q);
            if((p>x1&&q>y1)&&(p<x2&&q<y2))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
