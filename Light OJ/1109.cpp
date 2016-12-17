#include<stdio.h>
int main()
{
    int a[1050],i,n,t,j,c,b[1025],k;
    scanf("%d",&t);
    for(i=0;i<=1000;i++)
    {
        c=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
                c++;
        }
        a[i]=c;
    }
    for(i=1,k=1;i<=1000,k<=32;k++)
       {
           for(j=1000;j>=1;j--)
           {
               if(a[j]==k)
               {
                   b[i]=j;

                   i++;

               }
           }
       }
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",i,b[n]);
    }
    return 0;
}
