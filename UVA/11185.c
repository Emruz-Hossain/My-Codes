#include<stdio.h>
void ternary(long long m)
{
    int reminder;
    if(m>0)
    {
        reminder=m%3;
        ternary(m/3);
        printf("%d",reminder);
    }
}
int main()
{
    long long n;
    int t=0;
    while(t<100)
    {
        scanf("%lld",&n);
        if(n<0)
            break;
        else
        {
            ternary(n);
            t++;
        }
        printf("\n");
    }
     return 0;
}
