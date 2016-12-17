#include<stdio.h>
int total,reminder;
void count_cola(int m)
{
    if(m==2)
    {
        m++;
    }
   if(m<3)
    return;
   else
   {
       total=total+m/3;
       reminder=m-(3*(m/3));
       m=(m/3)+reminder;

   }
    count_cola(m);
}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        total=N;
        reminder=0;
        count_cola(N);
        printf("%d\n",total);
    }
    return 0;
}
