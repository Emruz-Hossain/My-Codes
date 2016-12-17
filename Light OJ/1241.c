#include<stdio.h>
int main()
{
    int t,i,j,n,lies,a[100],m,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        m=2;
        lies=0;
        for(j=0;j<n;j++)
        {
            k=a[j]-m;
            if(k>0&&k<=5)
                lies++;
            else if(k%5==0)
                lies+=k/5;
            else
                lies+=(k/5)+1;
            m=a[j];
        }
        printf("Case %d: %d\n",i,lies);

    }
    return 0;
}
