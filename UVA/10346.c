#include<stdio.h>
int number;
int reminder;
void count_cigaret(int n,int k)
{
    number=number+n+(n/k);
    reminder = n%k;
    n=(n/k)+reminder;
    if(n<k)
        return;
    else
        count_cigaret(n/k,k);
}
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)==2)
    {
        number=0;
        reminder=0;
        count_cigaret(n,k);
        printf("%d\n",number);

    }
    return 0;
}
