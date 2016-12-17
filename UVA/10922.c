#include<stdio.h>
#include<string.h>
int c;
int sum(int x)
{
    int sum=0;
    while(x!=0)
    {
        sum=sum+(x%10);
        x=x/10;
    }
    return sum;
}
void checker(int m)
{
    c++;
    if(m<9)
    {
        c=0;
        return;
    }
    if(m==9)
        return;
    else
        checker(sum(m));

}
int main()
{
    int sum,i;
    char n[1500];
    while(1)
    {
        c=0;
        sum=0;
        scanf("%s",&n);
        if(strcmp(n,"0")==0)
            break;
        for(i=0;i<strlen(n);i++)
        {
            sum=sum+(n[i]-'0');
        }
            checker(sum);
        if(c==0)
            printf("%s is not a multiple of 9.\n",n);
        else
            printf("%s is a multiple of 9 and has 9-degree %d.\n",n,c);
    }
    return 0;
}
