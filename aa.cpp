#include<stdio.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        printf(" ");
        for(j=0;j<i*2+1;j++)
        {
            if(i==n/2)
                printf("*");
            else
            {
                if(j==0||j==(i*2))
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");

    }
    return 0;
}
