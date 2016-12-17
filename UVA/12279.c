#include<stdio.h>
int main()
{
    int t=0,i,e,n,m;
    while(1)
    {
        t++;
        e=0;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            if(m!=0)
                e++;
            else
                e--;
        }
        printf("Case %d: %d\n",t,e);
    }
}
