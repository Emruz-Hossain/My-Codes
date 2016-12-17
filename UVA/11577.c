#include<stdio.h>
#include<string.h>
int main()
{
    char str[300];
    int ara[300],i,j,t,l,k,m;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        m=0;
        gets(str);
        l=strlen(str);
        for(k='a';k<='z';k++)
        {
            for(j=0;j<l-1;j++)

                    {
                        if(k==str[j])
                            ara[k]++;
                    }
        }
        for(k='a';k<='z';k++)
            if(m<ara[k])
            m=ara[k];
        for(k='a';k<='z';k++)
           {
            if(ara[k]==m)
            printf("%c",ara[k]);
           }
           printf("\n");
    }
    return 0;
}
