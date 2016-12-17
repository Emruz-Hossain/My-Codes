#include<stdio.h>
int main()
{
    int a[200],m,n,t,i,j,p,q,c[200],y,z,temp;
    char ch;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(j=1;j<=m;j++)
        {
            scanf("%s",&ch);
                if(ch=='P')
                    {
                        scanf("%d %d",&y,&z);
                         temp=a[y];
                        a[y]=a[z];
                        a[z]=temp;
                    }

                else if(ch=='R')
                {
                    for(p=n-1,q=0;p>=0;p--,q++)
                    c[q]=a[p];
                    for(p=0;p<n;p++)
                    a[p]=c[p];
                }
                else if(ch=='S')
                    {
                        scanf("%d",&y);
                        for(p=0;p<n;p++)
                        a[p]=a[p]+y;
                    }
                else if(ch=='M')
                    {
                        scanf("%d",&y);
                        for(p=0;p<n;p++)
                        a[p]=a[p]*y;
                    }
                else if(ch=='D')
                    {
                        scanf("%d",&y);
                        for(p=0;p<n;p++)
                        a[p]=a[p]/y;
                    }

        }
        printf("Case %d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%d",a[j]);
            if(j!=n-1)
            printf(" ");
            if(j==n-1)
                printf("\n");
        }
        }
    return 0;
}
