#include<stdio.h>
#include<string.h>
int process(char str[])
{
    int l,i,sum=0,digit=0,result=0;
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))
        {
            if(str[i]>=97)
            sum=sum+str[i]-96;
            else
            sum=sum+str[i]-64;
        }
    }
    while(sum>0)
    {
        digit=sum%10;
        result=result+digit;
        sum=sum/10;
        if(result>9)
            {
                sum=result;
                result=0;
            }

    }
    return result;
}
int main()
{
    char name1[100],name2[100];

    double r=0,a,b;
    while(gets(name1))
    {
        gets(name2);
        a=process(name1);
        b=process(name2);
        if(a==0&&b==0)
            r=100;
        else if(a>b)
            r=(b*100)/a;
        else
            r=(a*100)/b;
        printf("%.2lf %%\n",r);
    }
    return 0;
}
