#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],as[10];
    int ar[200],i,j,p,t,n,k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        p=0;
        scanf("%d",&n);

        for(j=1;j<=n;j++)
        {
           scanf("%s",&str);
            if(strcmp(str,"LEFT")==0)
            {
                p--;
                ar[j]=-1;
            }
            else if(strcmp(str,"RIGHT")==0)
            {
                p++;
                ar[j]=1;
            }
            else if(strcmp(str,"SAME AS"))
            {
                scanf("%s %d",&as,&k);
                p+=ar[k];
                ar[j]=ar[k];
            }
        }
        printf("%d\n",p);
    }
    return 0;
}
