#include<stdio.h>
int main()
{
    long long n,result,m;
   int i,t,p;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       result=0;
       p=0;
       scanf("%lld",&n);
       if(n<10)
        printf("%d\n",n);
       else
       {
           while(n!=0)
           {
               for(m=2;m<=9;m++)
                {
                if(n%m==0)
                    {
                        p=1;
                        result=result*10+m;
                        break;
                    }
                    else
                        p=0;

                }
            n=n/m;
            if(p!=1)
                {
                    result=-1;
                    break;
                }

            }
        if(result!=0)
       printf("%d\n",result);
       else
        printf("-1\n");
       }
   }
   return 0;
}
