#include<stdio.h>
int main()
{
    int aray[500],n,i=0,j,k,sum=0;
    while(1)
    {
        scanf("%d",&aray[i]);
        if(aray[i]==0)
            break;
            i++;
    }
    printf("PERFECTION OUTPUT\n");
    for(j=0;j<i;j++)
    {
        sum=0;
        for(k=1;k<aray[j];k++)
        {
            if(aray[j]%k==0)
                sum+=k;
        }
        if(sum==aray[j])
            printf("%5d  PERFECT\n",aray[j]);
        else if(sum<aray[j])
            printf("%5d  DEFICIENT\n",aray[j]);
        else if(sum>aray[j])
            printf("%5d  ABUNDANT\n",aray[j]);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
