#include<stdio.h>
long long f91(long long m)
{

    if(m>=101)
    return m-10;
    else
    m=m-10;
        f91(m+11);

}
int main()
{
    long long number,result;
    while(1)
    {
        scanf("%lld",&number);
        if(number==0)
            break;
        else
           result= f91(number);
        printf("f91(%lld) = %lld\n",number,result);

    }
    return 0;
}
