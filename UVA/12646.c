#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        if(a==b&&c!=a)
            printf("C\n");
        else if(a==c&&b!=c)
            printf("B\n");
        else if(b==c&&a!=b)
            printf("A\n");
        else
            printf("*\n");

    }
    return 0;
}
