#include<stdio.h>
#include<string.h>
int main()
{
    char a[500],b[500],sum[550];
    int r,carry=0,i,j,la,lb,t,k,reminder;
    gets(a);
    gets(b);
    la=strlen(a);
    lb=strlen(b);
    for(i=la-1,j=lb-1,k=0;i>=0||j>=0;i--,j--,k++)
    {
        if(j<0)
            b[j]=48;
        if(i<0)
            a[i]=48;
        r=(a[i]-48)+(b[j]-48)+carry;
        if(r>=10)
        {
             reminder=r%10;
             carry=r/10;
        }

        else
            reminder=r;
        if(k==0||j<0||i<0)
            sum[k]=reminder+48;
        else
            {
                sum[k]=reminder+carry+48;
                if(i!=0)
                carry=0;
            }

    }
    if(carry!=0)
    {
        sum[k]=carry+48;
        k=k+1;
    }
    sum[k]='\0';
    printf("%s",strrev(sum));
    return 0;
}
