#include<stdio.h>
//#include<string.h>
void column(int n)
{
    if(n--)
    {
        column(n/26);
        putchar('A'+n%26);
    }


}
int main()
{
    int n,i,r,c;
    char str[200],*p;
    scanf("%d",&n);
    while(n--)
    {
        r=0;c=0;
        scanf("%s",&str);
        sscanf(str,"R%dC%d",&r,&c);// a ta somporke bolen
        printf("%d %d\n",r,c);
    }
    return 0;
}

