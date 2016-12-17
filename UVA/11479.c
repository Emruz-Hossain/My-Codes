#include<stdio.h>
int main()
{
    int t,i;
    long long int a,b,c,k;
    scanf("%d",&t);
        for(i=1;i<=t;i++)
        {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a<b||a<c)
            {
                if(a<b)
                {
                    k=a;
                    a=b;
                    b=k;
                }

              if(a<c)
              {
                  k=a;
                  a=c;
                  c=k;
              }
            }

        if(b+c<=a)

            {
                printf("Case %d: Invalid\n",i);
                continue;
            }
        if(a==b&&a==c&&b==c)
        {
            printf("Case %d: Equilateral\n",i);
            continue;
        }
        if((a==b&&b!=c)||(b==c&&a!=c)||(c==a&&b!=a))
        {
            printf("Case %d: Isosceles\n",i);
            continue;
        }

        if(a!=b&&a!=c&&b!=c)
             {
                 printf("Case %d: Scalene\n",i);
                 continue;
             }


        }

    return 0;
}
