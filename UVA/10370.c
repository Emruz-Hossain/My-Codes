#include<stdio.h>
int main()
{
    int number[2000],i,j,m;
    double test_case,student_no,total,result,avarage;;
    scanf("%lf",&test_case);
    for(i=1;i<=test_case;i++)
    {
        total=0;
        m=0;
        scanf("%lf",&student_no);
        for(j=0;j<student_no;j++)
            scanf("%d",&number[j]);
        for(j=0;j<student_no;j++)
            total+=number[j];
        avarage=total/student_no;
        for(j=0;j<student_no;j++)
        {
            if(number[j]>avarage)
                m++;
        }
        result=(m*100)/student_no;
        printf("%.3lf%%\n",result);
    }
    return 0;
}
