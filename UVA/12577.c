#include<stdio.h>
#include<string.h>
int main()
{
    char a[50];
    int i=1;
    while(1)
    {
        gets(a);
        if(strcmp(a,"*")==0)
            break;
        else
        {
            if(strcmp(a,"Hajj")==0)
                printf("Case %d: Hajj-e-Akbar\n",i);
            else if(strcmp(a,"Umrah")==0)
                printf("Case %d: Hajj-e-Asghar\n",i);
        }
        i++;
    }
    return 0;
}
