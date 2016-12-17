#include<stdio.h>
#include<string.h>
char ss[100000];
int main()
{
    char c,ch2,ch;
    int x,value,ascii[500],i,line,count,k,t,l;
    double result;
    unsigned long long sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        memset(ascii,0,sizeof(ascii));
        for(i=0;i<k;i++)
        {
            getchar();
            scanf("%c",&ch);
            getchar();
            scanf("%d",&value);
            ascii[ch]=value;
        }
        scanf("%d",&line);
        getchar();
        sum=0;
        while(line--)
        {
            gets(ss);
            l=strlen(ss);
            for(i=0;i<l;i++)
                sum+=ascii[ss[i]];
        }
        result=sum/100.0;
        printf("%.2lf$\n",result);
    }
    return 0;
}
