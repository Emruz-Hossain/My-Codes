#include<stdio.h>
int main()
{
    int watching,expected,press1,press2;
    while(1)
    {
        scanf("%d %d",&watching,&expected);
        if(watching==-1&&expected==-1)
            break;
        if(watching>expected)
        {
            press1=watching-expected;
            press2=100-watching+expected;
        }
        else
        {
            press1=expected-watching;
            press2=100-expected+watching;
        }
        if(press1<press2)
            printf("%d\n",press1);
        else
            printf("%d\n",press2);
    }
    return 0;
}
