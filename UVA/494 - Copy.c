#include<stdio.h>
#include<string.h>
int main()
{
    char a[10000];
    int l,n,i,k;
    while(gets(a))
    {
        n=0;k=0;
        l=strlen(a);
        for(i=0;i<=l;)
        {
            if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
            {
               k=1;
               i++;
            }
            else
                {
                    if(k!=0)
                    n++;
                    i++;
                    k=0;
                }

        }
        printf("%d\n",n);
    }
    return 0;

}
