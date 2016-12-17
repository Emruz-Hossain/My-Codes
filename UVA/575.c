#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int sum,digit,l,i,j;
    char str[10000];
    while(1)
    {
        sum=0;
        gets(str);
        if(strcmp(str,"0")==0)
            break;
        l=strlen(str);
        for(i=l-1,j=1;i>=0;i--,j++)
        {
            digit=str[i]-'0';
            sum+=(digit*(pow(2,j)-1));

        }
        printf("%d\n",sum);
    }

    return 0;
}
