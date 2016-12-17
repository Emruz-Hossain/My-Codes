#include<stdio.h>
int total,reminder;
int count_cola(int m)
{
    if(m<3)
        return;
    else
    {
        total=total+m/3;
        reminder=m-(3*(m/3));
        m=reminder+m/3;
        count_cola(m);
    }
}
int main()
{
    int empty_bottle,i;
    while(1)
    {
        total=0;
        reminder=0;
        scanf("%d",&empty_bottle);
        if(empty_bottle==0)
            break;
        else
            count_cola(empty_bottle);
        printf("%d\n",total);
    }
    return 0;
}
