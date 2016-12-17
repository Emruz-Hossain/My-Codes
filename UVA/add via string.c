#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,reminder,la,lb,r;
    char a[100],b[100],sum[200];
    gets(a);
    gets(b);
    la=strlen(a);
    lb=strlen(b);
    sum[la]='\0';
    for(i=la-1,j=lb-1;i>=0||j>=0;i--,j--)
    {
        if(j<0)
            b[j]=0;
        if(i<0)
            a[i]=0;
        r=a[i]+b[j];
        if(r>9)
        {
            reminder=r%10;
            r=1;
        }
        else
            reminder=0;
        sum[i]=r+reminder;
    }
    puts(sum);
    return 0;

}
