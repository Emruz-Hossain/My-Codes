#include<stdio.h>
int main()
{
    int ar[100],t,w,i,j,h,l,p;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        h=0;l=0;
        scanf("%d",&w);
        for(j=0;j<w;j++)
            scanf("%d",&ar[j]);
        p=ar[0];
        for(j=0;j<w;j++)
        {
            if(ar[j]>p)
                {
                    h++;
                    p=ar[j];
                }
            if(ar[j]<p)
                {
                    l++;
                    p=ar[j];
                }
        }
        printf("Case %d: %d %d\n",i,h,l);
    }
    return 0;
}
