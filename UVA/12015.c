#include<stdio.h>
#include<string.h>
int main()
{
    char w[20][150];
    int r[20],i,j,test_case,t,m;
    scanf("%d",&test_case);
    for(t=1;t<=test_case;t++)
    {
        for(i=0,j=0;i<10;i++,j++)
        {
            scanf("%s %d",&w[i],&r[i]);
        }
       m=r[0];
        for(i=0;i<10;i++)
        {
            if(m<r[i])
                m=r[i];
        }
        printf("Case #%d:\n",t);
        for(i=0;i<10;i++)
        {
            if(m==r[i])
                printf("%s\n",w[i]);
        }

    }
    return 0;

}
