#include<stdio.h>
#include<string.h>
int main()
{
    char a[20],b[20];
    int carry,la,lb,i,j,sum,reminder;
    while(1)
    {
        carry=0;
        sum=0;
        reminder=0;
        scanf("%s %s",&a,&b);
        la=strlen(a);
        lb=strlen(b);
        if(a[0]=='0'&&b[0]=='0')
            break;
        for(i=la-1,j=lb-1;i>=0||j>=0;i--,j--)
        {
            if(i<0)
                a[i]=48;
            if(j<0)
                b[j]=48;
            sum=a[i]-48+b[j]-48+reminder;
            if(sum>9)
            {
                reminder=1;
                carry++;
            }
            else
                reminder=0;

        }
        if(carry==1)
            printf("%d carry operation.\n",carry);
            else if(carry!=0)
                printf("%d carry operations.\n",carry);
        else
            printf("No carry operation.\n");
    }
    return 0;
}
