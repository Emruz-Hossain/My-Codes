#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,k;
    char str[500],rev[500];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",&str);
        strcpy(rev,strrev(str));
        //scanf("%s",&rev);
        k=strcmp(str,rev);
        printf("%d",k);
        if(k!=0)
            printf("Case %d: No\n",i);
          else
            printf("Case %d: Yes\n",i);


    }
    return 0;
}
