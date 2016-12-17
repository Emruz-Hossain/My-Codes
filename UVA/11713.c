#include<stdio.h>
#include<string.h>
char name[250],mutant[250];
int ln,lm;
int main()
{
    int i,r,t;
    scanf("%d",&t);
    getchar();
  for(r=0;r<t;r++)
   {
       scanf("%s %s",&name,&mutant);
        ln=strlen(name);
       lm=strlen(mutant);
       if(ln==lm)
       {
           for(i=0;i<ln;i++)
            {
                if(name[i]=='a'||name[i]=='e'||name[i]=='i'||name[i]=='o'||name[i]=='u')
                    name[i]='0';
            }
           for(i=0;i<lm;i++)
            {
                if(mutant[i]=='a'||mutant[i]=='e'||mutant[i]=='i'||mutant[i]=='o'||mutant[i]=='u')
                    mutant[i]='0';
            }
            if(strcmp(name,mutant)==0)
                printf("Yes\n");
            else
                printf("No\n");
       }
       else
        printf("No\n");
   }
   return 0;
}
