#include <stdio.h>
int main()
{
int month,cas,n,i,j,mon[1000];
float down,loan,owe,worth,dep[1000],instlmnt;
while(scanf("%d %f %f %d",&month,&down,&loan,&cas))
{
    if(month<0)
        break;
    n=0;
    owe=0;
    worth=0;
    instlmnt = loan/month;
    for(i=0;i<cas;i++)
        scanf("%d %f",&mon[i],&dep[i]);
    mon[i] = month;
    owe = loan+down;
    worth = loan;
    int k=0;
    j=0;
    while(j<month)
    {
        for(i=0;i<mon[k+1]-mon[k];i++)
        {
            owe = owe - (owe*dep[k]);
            worth = worth - instlmnt;
            n = n + 1;
            if (owe > worth)
                break;

        }
        k++;
        j=j+i;
        if (owe > worth)
            break;

    }
    if (j == 1)
        printf("1 month\n");
    else
        printf ("%d months\n",j);
}
return 0;
}
