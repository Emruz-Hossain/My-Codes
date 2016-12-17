#include<stdio.h>
#include<string.h>
int main()
{
    int ac,d,t,op,i,j;
    char a[20];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        ac=0;
        scanf("%d",&op);
        printf("Case %d:",i);
        for(j=0;j<op;j++)
        {
            scanf("%s",&a);
            if(strcmp(a,"donate")==0)
            {
                scanf("%d",&d);
                ac+=d;
            }
            else if(strcmp(a,"report")==0)
                printf("%d\n",ac);
        }
    }
    return 0;
}
