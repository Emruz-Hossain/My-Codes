#include<stdio.h>
int main()
{
    int initial_temp,test_case,i,increase;
    double fi,fn ,final_temp;
    scanf("%d",&test_case);
    for(i=1;i<=test_case;i++)
    {
        scanf("%d %d",&initial_temp,&increase);
        fi=((9*initial_temp)/5)+32;
        fn=fi+increase;
        final_temp=(5*(fn-32))/9;
        printf("Case %d: %.2lf\n",i,final_temp);
    }
    return 0;
}
