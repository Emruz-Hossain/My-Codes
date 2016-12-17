#include<stdio.h>
#include<string.h>
int main()
{
    char str[5000];
    int t=0;
    while(1)
    {

        t++;
        scanf("%s",&str);
        if(strcmp(str,"#")==0)
            break;
        if(strcmp(str,"HELLO")==0)
            printf("Case %d: ENGLISH\n",t);
        else if(strcmp(str,"HOLA")==0)
            printf("Case %d: SPANISH\n",t);
        else if(strcmp(str,"HALLO")==0)
            printf("Case %d: GERMAN\n",t);
        else if(strcmp(str,"BONJOUR")==0)
            printf("Case %d: FRENCH\n",t);
        else if(strcmp(str,"CIAO")==0)
            printf("Case %d: ITALIAN\n",t);
        else if(strcmp(str,"ZDRAVSTVUJTE")==0)
            printf("Case %d: RUSSIAN\n",t);
        else
            printf("Case %d: UNKNOWN\n",t);
    }
    return 0;
}
