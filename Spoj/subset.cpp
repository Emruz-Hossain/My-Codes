#include<stdio.h>
int main()
{
    int n,tmp,sm,mx,i,j,ar[30];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    mx=(1<<n)-1;
    for(i=0;i<=mx;i++)
    {

        tmp=i;
        sm=0;
       for(j=0;j<n;j++)
        {
            if(tmp%2==1)
            {
                sm+=ar[j];
            }
            tmp>>=1;
        }
        printf(" %d",sm);
    }
    return 0;
}
