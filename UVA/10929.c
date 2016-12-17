#include<stdio.h>
#include<string.h>
int main()
{
    char n[1500];
    int odd_sum,even_sum,result,i;
    while(1)
    {
        odd_sum=0;even_sum=0;result=0;
        scanf("%s",&n);
        if(strcmp(n,"0")==0)
            break;
        else
        {
            for(i=strlen(n)-1;i>=0;i--)
            {
                if(i%2==0)
                    even_sum=even_sum+(n[i]-'0');
                else
                    odd_sum=odd_sum+(n[i]-'0');
            }
            result=odd_sum-even_sum;
        }
        if(result==0||(result%11)==0)
            printf("%s is a multiple of 11.\n",n);
        else
            printf("%s is not a multiple of 11.\n",n);
    }
    return 0;
}
