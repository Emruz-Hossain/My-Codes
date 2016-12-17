#include<stdio.h>
#include<string.h>
int main()
{
    char word[100000],str[100000];
    int i,l,c,j,k;
    while(gets(word))
    {
        k=0;
        l=strlen(word);
        for(i=0;i<l;i++)
            if(word[i]=='"')
            k++;
        if(k==1&&k==l-1||k==l-2)
            c=2;
        else
            c=1;

       for(i=0,j=0;i<l;i++)
        {
           if(word[i]=='"')
           {
               if(c%2!=0)
               {
                   str[j]='`';
                   j++;
                   str[j]='`';

               }
                else
                    {
                        str[j]='\'';
                        j++;
                        str[j]='\'';

                    }
                c++;
           }
           else
              str[j]=word[i];
            j++;
        }
        str[j]='\0';
        puts(str);
    }
    return 0;
}
