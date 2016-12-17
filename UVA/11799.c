#include<stdio.h>
int main()
{
    int test_case,student[120],speed,i,j,number;
    scanf("%d",&test_case);
    for(i=1;i<=test_case;i++)
    {
        scanf("%d",&number);
        for(j=0;j<number;j++)
        scanf("%d",&student[j]);
        speed=student[0];
        for(j=0;j<number;j++)
        {
            if(speed<student[j])
                speed=student[j];
        }
        printf("Case %d: %d\n",i,speed);
    }
    return 0;
}
