#include<stdio.h>
int main()
{
    int p,q,x,y,n,i;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        else
        {
            scanf("%d %d",&p,&q);
            for(i=0;i<n;i++)
            {
                scanf("%d %d",&x,&y);
                if(x==p||y==q)
                    printf("divisa\n");
                else if(x>p&&y>q)
                    printf("NE\n");
                else if(x>p&&y<q)
                    printf("SE\n");
                else if(x<p&&y>q)
                    printf("NO\n");
                    else if(x<p&&y<q)
                    printf("SO\n");
            }

        }
    }
    return 0;
}
