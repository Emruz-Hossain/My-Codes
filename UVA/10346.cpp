#include<stdio.h>
int total;
void counter(int n,int k)
{
    int r;
    if(n<k)
        return;
    else
    {
        r=n-(n/k)*k;
        total+=n/k;
        n=(n/k)+r;
        counter(n,k);
    }
}
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)==2)
    {
        total=n;
        counter(n,k);
        printf("%d\n",total);
    }
    return 0;
}
