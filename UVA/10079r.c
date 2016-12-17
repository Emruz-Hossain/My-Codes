#include<stdio.h>
int main()
{
    long long n,total;
    while(1)
    {
        scanf("%lld",&n);
        if(n<0)
            break;
        else
            total=1+(n*(n+1))/2;
        printf("%lld\n",total);
    }
    return 0;
}
