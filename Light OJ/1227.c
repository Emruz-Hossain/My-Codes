#include<stdio.h>
int main()
{
    int t,n,p,q,ne,i,a[35],w,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d",&n,&p,&q);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        ne=0;
        w=0;
        for(j=0;j<n;j++)
        {
            if(ne>=p||(w+a[j])>q)
                break;
            else
                ne++;
                w+=a[j];
        }
            printf("Case %d: %d\n",i,ne);
    }
    return 0;
}

