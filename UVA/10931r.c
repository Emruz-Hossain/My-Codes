#include<stdio.h>
#include<string.h>
char a[100000],b[100000];
int parity,i;
void binary(long long m)
{
    int digit;
    if(m==0)
        return ;
    else
        {
            digit=m%2;
            a[i]=digit+'0';
            i++;
            binary(m/2);
            parity=parity+digit;
        }
        a[i]='\0';
        return ;

}
void revers(void)
{
    int k,j,l;
    l=strlen(a);
    for(k=l-1,j=0;k>=0;k--,j++)
    {

        b[j]=a[k];
    }
    b[j]='\0';

}
int main()
{
    long long n;
    while(1)
    {
        parity=0;
        i=0;
        scanf("%lld",&n);
        if(n==0)
            break;
        else
            binary(n);
            revers();
        printf("The parity of %s is %d (mod 2).\n",b,parity);
    }
    return 0;
}
