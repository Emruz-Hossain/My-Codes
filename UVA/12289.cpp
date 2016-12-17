#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int l,t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",&str);
        l=strlen(str);
        if(l==5)
            printf("3\n");
        else
        {
           if(str[0]=='o'||str[1]=='n')
            printf("1\n");
           else
            printf("2\n");
        }
    }
    return 0;
}
