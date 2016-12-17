#include<stdio.h>
#include<string.h>
int main()
{
    char sub_string[1000000],main_string[1000000];
    int ls,lm,i,j,counter,k;
    while(scanf("%s %s",&sub_string,&main_string)==2)
    {
        counter=0;
        ls=strlen(sub_string);
        lm=strlen(main_string);
        if(ls>lm)
            printf("No\n");
        else
        {
            k=0;
            for(i=0;i<ls;i++)
            {
                for(j=k;j<lm;j++)
                    if(sub_string[i]==main_string[j])
                    {
                        counter++;
                        main_string[j]='0';
                        k=j;
                        break;
                }
            }
            if(counter==ls)
                printf("Yes\n");
            else
                printf("No\n");
        }


    }
    return 0;
}
