#include<stdio.h>
int main()
{
    int t1,t2,f,a,ct1,ct2,ct3,test_case,total,temp,i;
    double best2,ct;
    scanf("%d",&test_case);
    for(i=1;i<=test_case;i++)
    {
        scanf("%d %d %d %d %d %d %d",&t1,&t2,&f,&a,&ct1,&ct2,&ct3);
        if(ct1<ct2)
        {
            temp=ct1;
            ct1=ct2;
            ct2=temp;
        }
        if(ct2<ct3)
        {
            temp=ct2;
            ct2=ct3;
            ct3=temp;
        }
        best2=ct1+ct2;
        ct=best2/2;
        total=t1+t2+f+a+ct;
        if(total>=90)
            printf("Case %d: A\n",i);
        else if(total>=80&&total<90)
            printf("Case %d: B\n",i);
        else if(total>=70&&total<80)
            printf("Case %d: C\n",i);
         else if(total>=60&&total<700)
            printf("Case %d: D\n",i);
        else if(total<60)
            printf("Case %d: F\n",i);
    }
    return 0;

}
