#include<stdio.h>
int main()
{
    int t, n,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%d",&n);
        if(n%2==1)
            printf("Case %d: Bob win.\n",x);
        else
            printf("Case %d: Alice win.\n",x);
    }
}
