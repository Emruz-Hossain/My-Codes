#include<stdio.h>
int main()
{
    int m,number,difference,result;
    while(1)
    {
        scanf("%d",&number);
        if(number==0)
            break;
        else if(number==1)
            printf("1\n");
       else
       {
           m=2;
        while(m<number)
        {
            m=m*2;
        }
        difference=m-number;
        result=number-difference;
        printf("%d\n",result);
       }
    }
    return 0;
}
