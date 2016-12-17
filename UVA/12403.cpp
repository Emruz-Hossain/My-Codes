#include<stdio.h>
#include<string.h>
int main()
{
    char a[50];
    int account=0,donate,test_case,i,j,l,k;
    scanf("%d",&test_case);
    for(i=1;i<=test_case;i++)
    {
        donate=0;
        gets(a);
        if(strcmp(a,"report")==0)
            printf("%d\n",account);
        else
        {
            l=strlen(a);
            for(j=0;j<l;j++)
            {
                if(a[j]==' ')
                {
                    for(k=j+1;k<l;k++)
                        donate=donate*10+(a[k]-48);
                    break;
                }
                else
                    continue;
            }
            account=account+donate;

        }

    }
    return 0;
}
