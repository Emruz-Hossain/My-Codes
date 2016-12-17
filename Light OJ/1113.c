#include<stdio.h>
#include<string.h>
int main()
{
    char a[200][200],b[50];
    int t,i,p,c;
    strcpy(a[0],"http://www.lightoj.com/");
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        p=0;
        c=0;
        printf("Case %d:\n",i);
        while(1)
        {
          scanf("%s",&b);
            if(strcmp(b,"VISIT")==0)
            {
                c++;
                p=c;
                scanf("%s",&a[c]);
                 printf("%s\n",a[c]);

            }
            if(strcmp(b,"QUIT")==0)
                break;
            if(strcmp(b,"BACK")==0)
            {
                c--;
                if(c<0)
                    {
                        printf("Ignored\n");
                        c++;
                    }
                else
                    printf("%s\n",a[c]);
            }
            if(strcmp(b,"FORWARD")==0)
            {
                c++;
                if(c>p)
                    {
                        printf("Ignored\n");
                        c--;
                    }
                else
                    printf("%s\n",a[c]);
            }

        }
        }
        return 0;
}
